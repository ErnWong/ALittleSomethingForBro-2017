#include "stdafx.h"
#include "Theatrical.h"
#include <Windows.h>
#include <cstring>
#include "Logging.h"

namespace Theatrical
{
	HANDLE hConsoleOutput;
	HANDLE hConsoleInput;
	HWND hWindow;
	HMENU hMenu;
	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	DWORD consoleSize;
	DWORD charactersWritten;
	COORD screenMid;
	COORD screenMax;
	void Init()
	{
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
		hWindow = GetConsoleWindow();
		hMenu = GetSystemMenu(hWindow, false);

		SetConsoleTitle("A Little Something...");

		if (!DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND))
		{
			LOG_ERROR("DeleteMenu: error %d\n", GetLastError());
		}
		if (!DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND))
		{
			LOG_ERROR("DeleteMenu: error %d\n", GetLastError());
		}
		if (!DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND))
		{
			LOG_ERROR("DeleteMenu: error %d\n", GetLastError());
		}
		if (!DeleteMenu(hMenu, SC_SIZE, MF_BYCOMMAND))
		{
			LOG_ERROR("DeleteMenu: error %d\n", GetLastError());
		}
		/*
		GetConsoleScreenBufferInfo(hConsoleOutput, &screenInfo);
		screenMid.X = screenInfo.srWindow.Right / 2;
		screenMid.Y = screenInfo.srWindow.Bottom / 2;
		screenMax.X = screenInfo.srWindow.Right;
		screenMax.Y = screenInfo.srWindow.Bottom;

		if (!SetConsoleScreenBufferSize(hConsoleOutput, {screenMax.X+1, screenMax.Y+1}))
		{
			LOG_ERROR("SetConsoleScreenBufferSize: error %d\n", GetLastError());
		}*/
		//*
		GetConsoleScreenBufferInfo(hConsoleOutput, &screenInfo);
		SMALL_RECT windowSize = screenInfo.srWindow;
		windowSize.Bottom = windowSize.Top + 24;
		windowSize.Right = windowSize.Left + 79;

		if (!SetConsoleWindowInfo(hConsoleOutput, true, &windowSize))
		{
			LOG_ERROR("SetConsoleWindowInfo: error %d\n", GetLastError());
		}
		if (!SetConsoleScreenBufferSize(hConsoleOutput, { 80, 25 }))
		{
			LOG_ERROR("SetConsoleScreenBufferSize: error %d\n", GetLastError());
		}
		GetConsoleScreenBufferInfo(hConsoleOutput, &screenInfo);
		screenMid.X = screenInfo.srWindow.Right / 2;
		screenMid.Y = screenInfo.srWindow.Bottom / 2;
		screenMax.X = screenInfo.srWindow.Right - 1;
		screenMax.Y = screenInfo.srWindow.Bottom;
		//*/

		GetConsoleScreenBufferInfo(hConsoleOutput, &screenInfo);
		consoleSize = screenInfo.dwSize.X * screenInfo.dwSize.Y;

		DWORD consoleMode;
		GetConsoleMode(hConsoleInput, &consoleMode);
		consoleMode |= ENABLE_EXTENDED_FLAGS;
		consoleMode &= ~ENABLE_QUICK_EDIT_MODE;
		//consoleMode &= ~ENABLE_INSERT_MODE;
		//consoleMode &= ~ENABLE_LINE_INPUT;
		//consoleMode |= ENABLE_PROCESSED_INPUT;
		//consoleMode &= ~ENABLE_MOUSE_INPUT;
		if (!SetConsoleMode(hConsoleInput, consoleMode))
		{
			LOG_ERROR("SetConsoleMode: error %d\n", GetLastError());
		}

		CONSOLE_CURSOR_INFO cursorInfo;
		cursorInfo.bVisible = false;
		cursorInfo.dwSize = 100;
		if (!SetConsoleCursorInfo(hConsoleOutput, &cursorInfo))
		{
			LOG_ERROR("SetConsoleCursorInfo: error %d\n", GetLastError());
		}
	}

	void ClearScreen()
	{
		FillConsoleOutputCharacter(hConsoleOutput, ' ', consoleSize, { 0, 0 }, &charactersWritten);
		TidyBorder();
	}

	void ColorScreen(WORD attributes)
	{
		for (SHORT i = 1; i < screenInfo.dwSize.Y - 1; i++)
		{
			FillConsoleOutputAttribute(hConsoleOutput, attributes, screenInfo.dwSize.X - 4, { 2, i }, &charactersWritten);
		}
		TidyBorder();
		SetConsoleTextAttribute(hConsoleOutput, attributes);
	}

	void TidyBorder()
	{
		WORD attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		for (SHORT i = 0; i < screenInfo.dwSize.X-1; i++)
		{
			FillConsoleOutputAttribute(hConsoleOutput, attributes, 1, { i, 0 }, &charactersWritten);
			FillConsoleOutputAttribute(hConsoleOutput, attributes, 1, { i, screenInfo.dwSize.Y-1 }, &charactersWritten);
		}
		for (SHORT i = 0; i < screenInfo.dwSize.Y-1; i++)
		{
			FillConsoleOutputAttribute(hConsoleOutput, attributes, 1, { 0, i }, &charactersWritten);
			FillConsoleOutputAttribute(hConsoleOutput, attributes, 1, { 1, i }, &charactersWritten);
			FillConsoleOutputAttribute(hConsoleOutput, attributes, 1, { screenInfo.dwSize.X, i }, &charactersWritten);
			FillConsoleOutputAttribute(hConsoleOutput, attributes, 1, { screenInfo.dwSize.X+1, i }, &charactersWritten);
		}
	}

	void TypeTextCentered(char * message, COORD position)
	{
		short messageSize = (short)strlen(message);
		TypeText(message, { position.X - messageSize / 2, position.Y });
	}

	void TypeText(char * message, COORD position)
	{
		SetConsoleCursorPosition(hConsoleOutput, position);
		while (*message)
		{
			printf("%c", *message);
			Sleep(30);
			message++;
		}
		SetConsoleCursorPosition(hConsoleOutput, screenMax);
		TidyBorder();
	}

	WORD WaitForKey(char * message)
	{
		return WaitForKey(message, screenMid);
	}

	WORD WaitForKey(char * message, COORD position)
	{
		short messageSize = (short)strlen(message);
		int keywaitCounter = 0;

		TidyBorder();
		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		GetConsoleScreenBufferInfo(hConsoleOutput, &bufferInfo);
		if (position.Y == screenMax.Y || position.Y == 0)
		{
			SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}

		FlushConsoleInputBuffer(hConsoleInput);
		while (true)
		{
			SetConsoleCursorPosition(hConsoleOutput, { position.X - messageSize / 2, position.Y });
			if ((keywaitCounter / 8) & 1)
			{
				printf(message);
			}
			else
			{
				for (int i = 0; i < messageSize; i++)
				{
					printf(" ");
				}
			}
			SetConsoleCursorPosition(hConsoleOutput, screenMax);
			Sleep(100);
			keywaitCounter++;

			while (true)
			{
				DWORD eventCount;
				GetNumberOfConsoleInputEvents(hConsoleInput, &eventCount);
				if (!eventCount) break;
				INPUT_RECORD events[256];
				DWORD readCount;
				ReadConsoleInput(hConsoleInput, (PINPUT_RECORD)&events, 256, &readCount);
				for (DWORD i = 0; i < readCount; i++)
				{
					if (events[i].EventType != KEY_EVENT) continue;
					if (!events[i].Event.KeyEvent.bKeyDown) continue;
					if (events[i].Event.KeyEvent.wVirtualKeyCode == VK_CONTROL) continue;

					SetConsoleCursorPosition(hConsoleOutput, { position.X - messageSize / 2, position.Y });
					for (int j = 0; j < messageSize; j++)
					{
						printf(" ");
					}
					SetConsoleCursorPosition(hConsoleOutput, screenMax);

					TidyBorder();
					SetConsoleTextAttribute(hConsoleOutput, bufferInfo.wAttributes);
					return events[i].Event.KeyEvent.wVirtualKeyCode;
				}
			}
		}
	}
}