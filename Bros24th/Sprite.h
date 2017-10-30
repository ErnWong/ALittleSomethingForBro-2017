#pragma once

#include <Windows.h>
#include <vector>
#include "instruction.h"

namespace Art
{

	class Sprite
	{
		std::vector<Instruction> instructions;

	public:
		int row;
		int col;
		Sprite(int r, int c, std::vector<Instruction> i);
		void Draw(HANDLE hConsoleOutput, int time);
		void Draw(HANDLE hConsoleOutput, int time, char * str);
	};

}