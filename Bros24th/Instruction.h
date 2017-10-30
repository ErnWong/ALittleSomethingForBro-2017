#pragma once

namespace Art
{

	struct Instruction
	{
		int time;
		int row;
		int col;
		const char * str;

		bool operator <(const Instruction &right);
		bool operator <(int right);
	};

}