#pragma once

#include <vector>

namespace SoundManager
{

	typedef enum Instrument
	{
		INSTRUMENT_NOISE,
		INSTRUMENT_SQUARE,
		INSTRUMENT_TRIANGLE,
		INSTRUMENT_SAWTOOTH,
		INSTRUMENT_SINE
	}
	Instrument;
	const Instrument INSTRUMENT_INITIAL = INSTRUMENT_SQUARE;

	typedef enum InstructionType
	{
		INSTRUCTION_PLAY,
		INSTRUCTION_TIMING,
		INSTRUCTION_BALANCE,
		INSTRUCTION_STACCATO,
		INSTRUCTION_INSTRUMENT
	}
	InstructionType;

	typedef enum TimingChannels
	{
		CHANNEL_TEMPO = 0,
		CHANNEL_VALUE = 1
	}
	TimingChannels;

	const int virtualChannelCount = 4;
	const int sampleRate = 44100;

	// Example: timingInstruction.channels[0] = TEMPO_INITIAL
	const unsigned char TEMPO_SLOWEST = 40;
	const unsigned char TEMPO_FASTEST = 208;
	const unsigned char TEMPO_INITIAL = 100;

	// Example: timingInstruction.channels[1] = VALUE_INITIAL
	const unsigned char VALUE_SHORTEST = 32;
	const unsigned char VALUE_LONGEST = 1;
	const unsigned char VALUE_INITIAL = 4;

	const unsigned char STACCATO_INITIAL = 200;

	// Example: playInstruction.channels[0 or 1 or 2 or 3] = Keys::C+4
	const unsigned char OCTAVE_LOWEST = 0;
	const unsigned char OCTAVE_HIGHEST = 7;

	const unsigned char BALANCE_INITIAL = 255 / virtualChannelCount;

	namespace Keys
	{
		const unsigned char NOTE_MASK   = 0b01111000;
		const unsigned char NOTE_POS    = 0b00001000;
		const unsigned char OCTAVE_MASK = 0b00000111;
		const unsigned char OCTAVE_POS  = 0b00000001;
		typedef enum Key
		{
			Rest =  0 * NOTE_POS,
			Ces  =  1 * NOTE_POS,
			C    =  2 * NOTE_POS,
			Cis  =  3 * NOTE_POS,
			Des  =  3 * NOTE_POS,
			D    =  4 * NOTE_POS,
			Dis  =  5 * NOTE_POS,
			Es   =  5 * NOTE_POS,
			E    =  6 * NOTE_POS,
			Eis  =  7 * NOTE_POS,
			Fes  =  6 * NOTE_POS,
			F    =  7 * NOTE_POS,
			Fis  =  8 * NOTE_POS,
			Ges  =  8 * NOTE_POS,
			G    =  9 * NOTE_POS,
			Gis  = 10 * NOTE_POS,
			As   = 10 * NOTE_POS,
			A    = 11 * NOTE_POS,
			Ais  = 12 * NOTE_POS,
			Bes  = 12 * NOTE_POS,
			B    = 13 * NOTE_POS,
			Bis  = 14 * NOTE_POS,
			
			S    = 0b10000000
			/*
			C  = 0b00000000,
			D  = 0b00001000,
			E  = 0b00010000,
			F  = 0b00011000,
			G  = 0b00100000,
			A  = 0b00101000,
			B  = 0b00110000,
			S  = 0b01000000, // detatched
			SS = 0b11000000  // staccatissimo
			*/
		} Key;
	};

	struct Instruction
	{
		InstructionType type;
		unsigned char channels[virtualChannelCount];
	};

	typedef std::vector<Instruction> Sequence;

	bool Init();
	bool Teardown();
	bool Add(char * name, Sequence sequence);
	bool Play(char * name);
	bool Play(char * name, int repeats);
	bool IsPlaying();
	void Stop();
	int WaitTillNextBeat(int noteValue);
}