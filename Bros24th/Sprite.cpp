#include "stdafx.h"
#include "Sprite.h"

#include <vector>
#include <algorithm>
#include <Windows.h>

#include "Instruction.h"
#include "Theatrical.h"

namespace Art
{

	Sprite::Sprite(int r, int c, std::vector<Instruction> i) : row(r), col(c), instructions(i)
	{
		std::sort(instructions.begin(), instructions.end());
	}

	void Sprite::Draw(HANDLE hConsoleOutput, int t)
	{
		COORD coord;
		auto instr = std::lower_bound(instructions.begin(), instructions.end(), t);
		while (instr != instructions.end() && (*instr).time == t)
		{
			coord.X = (short)(col + (*instr).col);
			coord.Y = (short)(row + (*instr).row);
			SetConsoleCursorPosition(hConsoleOutput, coord);
			//DWORD charactersWritten;
			//WriteConsole(hConsoleOutput, (*instr).str, 1, &charactersWritten, NULL);
			printf((*instr).str);
			instr++;
		}
		SetConsoleCursorPosition(hConsoleOutput, Theatrical::screenMax);
	}

	void Sprite::Draw(HANDLE hConsoleOutput, int t, char * str)
	{
		COORD coord;
		auto instr = std::lower_bound(instructions.begin(), instructions.end(), t);
		while (instr != instructions.end() && (*instr).time == t)
		{
			coord.X = (short)(col + (*instr).col);
			coord.Y = (short)(row + (*instr).row);
			SetConsoleCursorPosition(hConsoleOutput, coord);
			//DWORD charactersWritten;
			printf(str);
			//WriteConsole(hConsoleOutput, str, 1, &charactersWritten, NULL);
			instr++;
		}
		SetConsoleCursorPosition(hConsoleOutput, Theatrical::screenMax);
	}

}