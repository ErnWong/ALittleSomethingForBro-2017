#pragma once

#include <vector>
#include "Instruction.h"

namespace Art
{

	std::vector<Instruction> instrLetterY =
	{
		//     .------------ time
		//    /  .---------- row
		//   /  /   .------- col
		//  /  /   /   .---- the string
		// /  /   /   /
		{  0, 1,  0, "\\" },
		{  1, 2,  1, "\\" },
		{  2, 3,  2, "\\" },
		{  3, 4,  3, "\\" },
		{  4, 5,  4, "\\" },
		{  5, 6,  5, "." },
		{  6, 7,  5, "|" },
		{  7, 8,  5, "|" },
		{  8, 8,  6, "_" },
		{  9, 8,  7, "_" },
		{ 10, 8,  8, "_" },
		{ 11, 8,  9, "|" },
		{ 12, 7,  9, "|" },
		{ 13, 6,  9, "." },
		{ 14, 5, 10, "/" },
		{ 15, 4, 11, "/" },
		{ 16, 3, 12, "/" },
		{ 17, 2, 13, "/" },
		{ 18, 1, 14, "/" },
		{ 19, 0, 14, "_" },
		{ 20, 0, 13, "_" },
		{ 21, 0, 12, "_" },
		{ 22, 0, 11, "_" },
		{ 23, 1, 10, "/" },
		{ 24, 2,  9, "/" },
		{ 25, 3,  8, "/" },
		{ 26, 4,  7, "`" },
		{ 27, 3,  6, "\\" },
		{ 28, 2,  5, "\\" },
		{ 29, 1,  4, "\\" },
		{ 30, 0,  3, "_" },
		{ 31, 0,  2, "_" },
		{ 32, 0,  1, "_" },
		{ 33, 0,  0, "_" }
	};

}