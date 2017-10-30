#include "stdafx.h"
#include "SoundManager.h"

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <tuple>
#include <string>
#include <cstring>
#include <map>
#include <Windows.h>
#include "Logging.h"

namespace SoundManager
{

	MMRESULT errorCode;
	TCHAR errorMessage[MAXERRORLENGTH];
	bool soundManagerInitialized = false;

	UINT_PTR deviceId = 0;
	WAVEOUTCAPS deviceCaps;
	bool deviceOpened = false;
	bool deviceClosing = false;
	bool devicePlaying = false;
	HWAVEOUT waveOut;
	WAVEFORMATEX waveFormat;

	struct LibraryEntry
	{
		WAVEHDR header;
		std::map<int, int> beatNumberAtFrame;
	};

	std::map<std::string, LibraryEntry> soundLibrary;
	LibraryEntry * currentSoundEntry = NULL;

	static bool setupWaveFormat();
	static bool openSoundCard();
	static bool closeSoundCard();
	static void CALLBACK waveOutCallback(
		HWAVEOUT  hwo,
		UINT      uMsg,
		DWORD_PTR dwInstance,
		DWORD_PTR dwParam1,
		DWORD_PTR dwParam2
	);

	struct SignalLeftover
	{
		double value;
		int framesRemaining;
		SignalLeftover() : value(0.0), framesRemaining(0) {}
	};

	struct InstrumentState
	{
		unsigned char instruction;
		int frameNumber;
		int framesPerInstruction;
		double balance;
		double staccatoDuration;
		double stateVar1;
		double stateVar2;
		SignalLeftover prev;
	};

	static double squareFn(InstrumentState & state);
	static SignalLeftover squareLeftover(InstrumentState & state);
	static double noiseFn(InstrumentState & state);
	static SignalLeftover noiseLeftover(InstrumentState & state);
	static int realignFrame(InstrumentState & state, int framesPerHalfCycle);

	typedef double InstrumentFn(InstrumentState &);
	static InstrumentFn * instrumentFunctions[] =
	{
		noiseFn,
		squareFn
	};
	
	typedef SignalLeftover InstrumentLeftover(InstrumentState &);
	static InstrumentLeftover * instrumentLeftovers[] =
	{
		noiseLeftover,
		squareLeftover
	};

	static int timingToFrames(int bpm, int noteValue);
	static unsigned char normalizeSignal(int in);

	bool Init()
	{
		LOG_INFO("SoundManager::Init\n");

		if (soundManagerInitialized)
		{
			LOG_WARNING("SoundManager::Init: Already initialized. Skipping\n");
			return 0;
		}

		if (setupWaveFormat())
		{
			LOG_ERROR("-> From SoundManager::Init\n");
			return 1;
		}

		if (openSoundCard())
		{
			LOG_ERROR("-> From SoundManager::Init\n");
			return 1;
		}

		soundManagerInitialized = true;

		return 0;
	}

	bool Teardown()
	{
		LOG_INFO("SoundManager::Teardown\n");

		if (closeSoundCard())
		{
			LOG_ERROR("-> From SoundManager::Teardown\n");
			// don't return
		}

		return 0;
	}

	bool Add(char * name, Sequence sequence)
	{
		LOG_INFO("SoundManager::Add\n");
		char displayName[3] = { name[0], name[strlen(name) - 1], '\0' };
		LOG_INFO("Adding sequence - %s\n", displayName);

		if (soundLibrary.count(name))
		{
			LOG_WARNING("SoundManager::Add: Sequence with name %s alrerady exists. Will be overwritten.", name);
		}

		LOG_INFO("SoundManager::Add: Calculating buffer size\n");

		int bufferSize = 0;
		int framesPerInstruction = timingToFrames(TEMPO_INITIAL, VALUE_INITIAL);

		for (const Instruction& instruction : sequence)
		{
			switch (instruction.type)
			{

			case INSTRUCTION_TIMING:
				framesPerInstruction = timingToFrames(instruction.channels[CHANNEL_TEMPO], instruction.channels[CHANNEL_VALUE]);
				break;

			case INSTRUCTION_PLAY:
				bufferSize += framesPerInstruction;
				break;

			}
		}

		unsigned char * signal = new unsigned char[bufferSize];
		LOG_INFO("SoundManager::Add: Buffer size - %d\n", bufferSize);

		LOG_INFO("SoundManager::Add: Generating waveform signal\n");

		unsigned char instruments[virtualChannelCount];
		for (unsigned char& instrument : instruments)
		{
			instrument = INSTRUMENT_INITIAL;
		}

		InstrumentState states[virtualChannelCount];
		for (InstrumentState& state : states)
		{
			state.balance = BALANCE_INITIAL;
			state.staccatoDuration = STACCATO_INITIAL / 256.0;
			state.prev = SignalLeftover();
		}

		framesPerInstruction = timingToFrames(TEMPO_INITIAL, VALUE_INITIAL);
		double beatsPerInstruction = (double)VALUE_SHORTEST / VALUE_INITIAL;
		int framesPerBeat = (int)(framesPerInstruction / beatsPerInstruction);
		int signalPosition = 0;
		std::map<int, int> beatNumberAtFrame;
		int beatFrame = -framesPerBeat;
		int beatNumber = 0;
		int noteValue = VALUE_INITIAL;

		for (const Instruction& instruction : sequence)
		{
			switch (instruction.type)
			{

			case INSTRUCTION_TIMING:
			{
				double beatFraction = (double)(signalPosition - beatFrame) / framesPerInstruction * beatsPerInstruction;
				framesPerInstruction = timingToFrames(instruction.channels[CHANNEL_TEMPO], instruction.channels[CHANNEL_VALUE]);
				noteValue = instruction.channels[CHANNEL_VALUE];
				beatsPerInstruction = (double)VALUE_SHORTEST / noteValue;
				beatFrame = (int)(signalPosition - beatFraction / beatsPerInstruction * framesPerInstruction);
				framesPerBeat = (int)(framesPerInstruction / beatsPerInstruction);
				break;
			}

			case INSTRUCTION_BALANCE:
				for (int i = 0; i < virtualChannelCount; i++)
				{
					states[i].balance = instruction.channels[i];
				}
				break;

			case INSTRUCTION_STACCATO:
				for (int i = 0; i < virtualChannelCount; i++)
				{
					states[i].staccatoDuration = instruction.channels[i] / 256.0;
				}
				break;

			case INSTRUCTION_INSTRUMENT:
				for (int i = 0; i < virtualChannelCount; i++)
				{
					if (instruments[i] == instruction.channels[i])
					{
						continue;
					}
					instruments[i] = instruction.channels[i];
					states[i].prev = SignalLeftover();
				}
				break;

			case INSTRUCTION_PLAY:
				for (int t = 0; t < framesPerInstruction; t++)
				{
					if (signalPosition - beatFrame >= framesPerBeat)
					{
						beatNumberAtFrame[signalPosition] = beatNumber;
						beatFrame = signalPosition;
						beatNumber++;
					}
					int value = 127;
					for (int i = 0; i < virtualChannelCount; i++)
					{
						states[i].frameNumber = t;
						states[i].framesPerInstruction = framesPerInstruction;
						states[i].instruction = instruction.channels[i];
						value += (int)(states[i].balance * instrumentFunctions[instruments[i]](states[i]));
					}
					signal[signalPosition] = normalizeSignal(value);
					signalPosition++;
				}
				for (int i = 0; i < virtualChannelCount; i++)
				{
					states[i].prev = instrumentLeftovers[instruments[i]](states[i]);
				}
				break;

			}
		}
		WAVEHDR header;
		header.dwBufferLength = bufferSize;
		header.lpData = (LPSTR) signal;
		header.dwFlags = WHDR_BEGINLOOP | WHDR_ENDLOOP;
		header.dwLoops = 1;

		LibraryEntry entry;
		entry.header = header;
		entry.beatNumberAtFrame = beatNumberAtFrame;

		soundLibrary[name] = entry;

		LOG_INFO("SoundManager::Add: Done adding sequence %s\n", displayName);

		return 0;
	}

	bool Play(char * name, int repeats)
	{
		LOG_INFO("SoundManager::Play\n");

		if (!soundManagerInitialized)
		{
			LOG_ERROR("SoundManager::Play: Cannot play before sound manager is initialized\n");
			return 1;
		}
		
		if (!deviceOpened)
		{
			LOG_ERROR("SoundManager::Play: Sound card device has not been opened yet\n");
			return 1;
		}

		errorCode = waveOutReset(waveOut);
		if (errorCode)
		{
			waveOutGetErrorText(errorCode, errorMessage, MAXERRORLENGTH);
			LOG_ERROR("waveOutReset: %s\n", errorMessage);
			LOG_ERROR("-> From SoundManager::Play\n");
			return 1;
		}

		auto headerEntry = soundLibrary.find(name);

		if (headerEntry == soundLibrary.end())
		{
			LOG_ERROR("SoundManager::Play: Sequence %s does not exist\n", name);
			return 1;
		}

		WAVEHDR& header = headerEntry->second.header;
		header.dwLoops = repeats;

		errorCode = waveOutPrepareHeader(waveOut, &header, sizeof(header));
		if (errorCode)
		{
			waveOutGetErrorText(errorCode, errorMessage, MAXERRORLENGTH);
			LOG_ERROR("waveOutPrepareHeader: %s\n", errorMessage);
			LOG_ERROR("-> From SoundManager::Play\n");
			return 1;
		}

		errorCode = waveOutWrite(waveOut, &header, sizeof(header));
		if (errorCode)
		{
			waveOutGetErrorText(errorCode, errorMessage, MAXERRORLENGTH);
			LOG_ERROR("waveOutWrite: %s\n", errorMessage);
			LOG_ERROR("-> From SoundManager::Play\n");
			return 1;
		}
		devicePlaying = true;
		currentSoundEntry = &(headerEntry->second);

		return 0;
	}

	bool Play(char * name)
	{
		return Play(name, 1);
	}

	bool IsPlaying()
	{
		return devicePlaying;
	}

	void Stop()
	{
		waveOutReset(waveOut);
	}

	int WaitTillNextBeat(int noteValue)
	{
		if (!devicePlaying) return -1;
		if (currentSoundEntry == NULL)
		{
			LOG_ERROR("WaitTilleNextBeat: currentSoundEntry is NULL");
			return -1;
		}
		MMTIME time;
		time.wType = TIME_SAMPLES;
		waveOutGetPosition(waveOut, &time, sizeof(time));
		time.u.sample %= currentSoundEntry->header.dwBufferLength;
		auto it = currentSoundEntry->beatNumberAtFrame.upper_bound(time.u.sample);
		while (it != currentSoundEntry->beatNumberAtFrame.end() && it->second % (VALUE_SHORTEST / noteValue) != 0)
		{
			it++;
		}
		if (it == currentSoundEntry->beatNumberAtFrame.end())
		{
			return -1;
		}
		while (time.u.sample < (DWORD)it->first)
		{
			waveOutGetPosition(waveOut, &time, sizeof(time));
			time.u.sample %= currentSoundEntry->header.dwBufferLength;
			Sleep(10);
		}
		return it->first;
	}

	static bool setupWaveFormat()
	{
		LOG_INFO("SoundManager::setupWaveFormat\n");

		waveFormat.wFormatTag = WAVE_FORMAT_PCM;
		waveFormat.nChannels = 1;
		waveFormat.wBitsPerSample = 8;
		waveFormat.nSamplesPerSec = sampleRate;
		waveFormat.nBlockAlign = waveFormat.nChannels * waveFormat.wBitsPerSample / 8;
		waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
		waveFormat.cbSize = 0;

		return 0;
	}

	static bool openSoundCard()
	{
		LOG_INFO("SoundManager::openSoundCard\n");

		if (deviceOpened)
		{
			LOG_WARNING("SoundManager::openSoundCard: Sound card is already opened. Skipping\n");
			return 0;
		}

		if (waveOutGetNumDevs() < 1)
		{
			LOG_ERROR("SoundManager::openSoundCard: No sound cards available!\n");
			return 1;
		}

		LOG_INFO("SoundManager::openSoundCard: querying device with id %d\n", deviceId);
		errorCode = waveOutGetDevCaps(deviceId, &deviceCaps, sizeof(deviceCaps));
		if (errorCode)
		{
			waveOutGetErrorText(errorCode, errorMessage, MAXERRORLENGTH);
			LOG_ERROR("waveOutGetDevCaps: %s\n", errorMessage);
			LOG_ERROR("-> From SoundManager::openSoundCard\n");
			return 1;
		}

		LOG_INFO("SoundManager::openSoundCard: device name: %s\n", deviceCaps.szPname);

		LOG_INFO("SoundManager::openSoundCard: checking capabilities\n");
		if (!(deviceCaps.dwFormats & WAVE_FORMAT_44M08))
		{
			LOG_ERROR("SoundManager::openSoundCard: device does not support 1M08 format!\n");
			return 1;
		}

		LOG_INFO("SoundManager::openSoundCard: opening device\n");
		errorCode = waveOutOpen(&waveOut, deviceId, &waveFormat, (DWORD)waveOutCallback, NULL, CALLBACK_FUNCTION);
		if (errorCode)
		{
			waveOutGetErrorText(errorCode, errorMessage, MAXERRORLENGTH);
			LOG_ERROR("waveOutOpen: %s\n", errorMessage);
			LOG_ERROR("-> From SoundManager::openSoundCard\n");
			return 1;
		}
		deviceOpened = true;

		return 0;
	}

	static bool closeSoundCard()
	{
		LOG_INFO("SoundManager::closeSoundCard\n");

		deviceClosing = true;

		if (!deviceOpened)
		{
			LOG_WARNING("SoundManager::closeSoundCard: Device is already closed. Skipping.\n");
			return 0;
		}

		LOG_INFO("SoundManager::closeSoundCard: Stopping any music\n");

		errorCode = waveOutReset(waveOut);
		if (errorCode)
		{
			waveOutGetErrorText(errorCode, errorMessage, MAXERRORLENGTH);
			LOG_ERROR("waveOutReset: %s\n", errorMessage);
			LOG_ERROR("-> From SoundManager::closeSoundCard\n");
		}

		LOG_INFO("SoundManager::closeSoundCard: Cleaning up prepared sound buffers\n");

		for (auto &headerEntry : soundLibrary)
		{
			WAVEHDR &header = headerEntry.second.header;
			if (header.dwFlags & WHDR_PREPARED)
			{
				errorCode = waveOutUnprepareHeader(waveOut, &header, sizeof(header));
				if (errorCode)
				{
					waveOutGetErrorText(errorCode, errorMessage, MAXERRORLENGTH);
					LOG_ERROR("waveOutUnprepareHeader: %s\n", errorMessage);
					LOG_ERROR("-> From SoundManager::closeSoundCard\n");
				}
			}
		}

		LOG_INFO("SoundManager::closeSoundCard: Finally closing device\n");

		errorCode = waveOutClose(waveOut);
		if (errorCode)
		{
			waveOutGetErrorText(errorCode, errorMessage, MAXERRORLENGTH);
			LOG_ERROR("waveOutClose: %s\n", errorMessage);
			LOG_ERROR("-> From SoundManager::closeSoundCard\n");
		}
		deviceOpened = false;
		deviceClosing = false;

		return 0;
	}

	static void CALLBACK waveOutCallback(
		HWAVEOUT  hwo,
		UINT      uMsg,
		DWORD_PTR dwInstance,
		DWORD_PTR dwParam1,
		DWORD_PTR dwParam2
	)
	{
		LOG_INFO("SoundManager::waveOutCallback\n");
		switch (uMsg)
		{
		case WOM_DONE:
		{
			LOG_INFO("SoundManager::waveOutCallback: Sound finished playing\n");
			/*
			WAVEHDR * header = (WAVEHDR *)dwParam1;
			errorCode = waveOutUnprepareHeader(waveOut, header, sizeof(*header));
			if (errorCode)
			{
				waveOutGetErrorText(errorCode, errorMessage, MAXERRORLENGTH);
				LOG_ERROR("waveOutUnprepareHeader: %s\n", errorMessage);
				LOG_ERROR("-> From SoundManager::waveOutCallback\n");
			}
			if (currentlyLooping && !deviceClosing)
			{
				LOG_INFO("SoundManager::waveOutCallback: Replaying sound\n");

				errorCode = waveOutPrepareHeader(waveOut, header, sizeof(*header));
				if (errorCode)
				{
					waveOutGetErrorText(errorCode, errorMessage, MAXERRORLENGTH);
					LOG_ERROR("waveOutPrepareHeader: %s\n", errorMessage);
					LOG_ERROR("-> From SoundManager::waveOutCallback\n");
				}

				errorCode = waveOutWrite(waveOut, header, sizeof(*header));
				if (errorCode)
				{
					waveOutGetErrorText(errorCode, errorMessage, MAXERRORLENGTH);
					LOG_ERROR("waveOutWrite: %s\n", errorMessage);
					LOG_ERROR("-> From SoundManager::waveOutCallback\n");
				}
			}
			*/
			devicePlaying = false;
			break;
		}
		case WOM_CLOSE:
			LOG_INFO("SoundManager::waveOutCallback: Sound card closed\n");
			deviceOpened = false;
			break;
		}
		std::ignore = hwo;
		std::ignore = uMsg;
		std::ignore = dwInstance;
		std::ignore = dwParam1;
		std::ignore = dwParam2;

	}

	static double getFrequency(unsigned char instruction)
	{
		double note = (instruction & Keys::NOTE_MASK) / Keys::NOTE_POS - (double)(Keys::A / Keys::NOTE_POS);
		double octave = (instruction & Keys::OCTAVE_MASK) / Keys::OCTAVE_POS - 4.0;
		return pow(2, note / 12 + octave) * 440.0;
	}

	static double squareFn(InstrumentState & state)
	{
		if (state.frameNumber < state.prev.framesRemaining)
		{
			return state.prev.value;
		}
		if ((state.instruction & Keys::NOTE_MASK) == Keys::Rest)
		{
			return 0.0;
		}

		double f = getFrequency(state.instruction);
		int framesPerHalfCycle = (int)(sampleRate / f / 2.0);

		if (state.instruction & Keys::S)
		{
			int frameEnd = (int)(state.staccatoDuration * state.framesPerInstruction);
			frameEnd /= framesPerHalfCycle;
			frameEnd *= framesPerHalfCycle;

			if (state.frameNumber > frameEnd)
			{
				return 0.0;
			}
		}

		int t = realignFrame(state, framesPerHalfCycle);

		return ((t / framesPerHalfCycle) & 1) - 0.5;
	}

	static int realignFrame(InstrumentState & state, int framesPerHalfCycle)
	{
		return state.frameNumber - state.prev.framesRemaining + (state.prev.value < 0.0) * framesPerHalfCycle;
	}

	static SignalLeftover squareLeftover(InstrumentState & state)
	{
		if ((state.instruction & Keys::NOTE_MASK) == Keys::Rest)
		{
			return SignalLeftover();
		}
		if (state.instruction & Keys::S)
		{
			return SignalLeftover();
		}

		double f = getFrequency(state.instruction);
		int framesPerHalfCycle = (int)(sampleRate / f / 2.0);

		state.frameNumber = state.framesPerInstruction;

		SignalLeftover leftover;
		leftover.value = squareFn(state);
		leftover.framesRemaining = framesPerHalfCycle - realignFrame(state, framesPerHalfCycle) % framesPerHalfCycle;

		return leftover;
	}

	static double noiseFn(InstrumentState & state)
	{
		if (!state.instruction)
		{
			return 0;
		}
		unsigned char skipRatio = state.instruction & ~Keys::S;
		double signal = (double)std::rand() / RAND_MAX - 0.5;
		if (state.frameNumber % skipRatio != 0)
		{
			const double a = 0;
			signal = a * signal + (1 - a) * state.stateVar1;
		}
		state.stateVar1 = signal;
		if (state.instruction & Keys::S)
		{
			/*double frameEnd = state.framesPerInstruction * state.staccatoDuration;
			if (state.frameNumber > frameEnd)
			{
				return 0;
			}*/
			//signal *= ((double)frameEnd - state.frameNumber) / state.framesPerInstruction;
			if (state.frameNumber == 0)
			{
				state.stateVar2 = 1.0;
			}
		}
		signal *= state.stateVar2;
		state.stateVar2 -= 4.0 / sampleRate;
		if (state.stateVar2 < 0.0) state.stateVar2 = 0.0;
		return signal;
	}

	static SignalLeftover noiseLeftover(InstrumentState & state)
	{
		std::ignore = state;
		return SignalLeftover();
	}

	static int timingToFrames(int bpm, int noteValue)
	{
		// Base everything to the shortest note value
		int shortest = sampleRate * 60 * 4 / bpm / VALUE_SHORTEST;
		int whole = shortest * VALUE_SHORTEST;
		return whole / noteValue;
	}

	static unsigned char normalizeSignal(int in)
	{
		if (in < 0) return 0;
		if (in > 255) return 255;
		return (unsigned char)in;
	}

}