#pragma once

#include <Windows.h>

namespace Theatrical
{
	extern HANDLE hConsoleOutput;
	extern HANDLE hConsoleInput;
	extern HWND hWindow;
	extern HMENU hMenu;
	extern CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	extern DWORD consoleSize;
	extern DWORD charactersWritten;
	extern COORD screenMid;
	extern COORD screenMax;
	void Init();
	void ClearScreen();
	void ColorScreen(WORD attributes);
	void TidyBorder();
	void TypeTextCentered(char * message, COORD position);
	void TypeText(char * message, COORD position);
	WORD WaitForKey(char * message);
	WORD WaitForKey(char * message, COORD position);
}