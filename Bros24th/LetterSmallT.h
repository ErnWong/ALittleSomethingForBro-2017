#pragma once

#include <vector>
#include "Instruction.h"

namespace Art
{

	std::vector<Instruction> instrLetterSmallT = {
		//     .------------ time
		//    /  .---------- row
		//   /  /   .------- col
		//  /  /   /   .---- the string
		// /  /   /   /
		{  0, 1,  0, "|" },
		{  1, 1,  1, "_" },
		{  2, 2,  2, "|" },
		{  3, 3,  2, "|" },
		{  4, 3,  3, "_" },
		{  5, 3,  4, "|" },
		{  6, 2,  4, "|" },
		{  7, 1,  5, "_" },
		{  8, 1,  6, "|" },
		{  9, 0,  5, "_" },
		{ 10, 0,  4, "_" },
		{ 11, 0,  3, "_" },
		{ 12, 0,  2, "_" },
		{ 13, 0,  1, "_" }
	};

}