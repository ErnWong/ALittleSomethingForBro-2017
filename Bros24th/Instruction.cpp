#include "stdafx.h"
#include "Instruction.h"

namespace Art
{

	bool Instruction::operator <(const Instruction &right)
	{
		return time < right.time;
	}
	bool Instruction::operator <(int right)
	{
		return time < right;
	}

}