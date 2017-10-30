#pragma once

#include <vector>
#include "Instruction.h"

namespace Art
{

	std::vector<Instruction> instrLetterP =
	{
		//     .------------ time
		//    /  .---------- row
		//   /  /   .------- col
		//  /  /   /   .---- the string
		// /  /   /   /
		{  0, 1,  0, "|" },
		{  1, 2,  0, "|" },
		{  2, 3,  0, "|" },
		{  3, 4,  0, "|" },
		{  4, 5,  0, "|" },
		{  5, 6,  0, "|" },
		{  6, 7,  0, "|" },
		{  7, 8,  0, "|" },
		{  8, 8,  1, "_" },
		{  9, 8,  2, "_" },
		{ 10, 8,  3, "_" },
		{ 11, 8,  4, "|" },
		{ 12, 7,  4, "|" },
		{ 13, 6,  5, "_" },
		{ 14, 6,  6, "_" },
		{ 15, 6,  7, "_" },
		{ 16, 6,  8, "_" },
		{ 17, 6,  9, "_" },
		{ 18, 6, 10, "_" },
		{ 19, 6, 11, "/" },
		{ 20, 5, 12, "|" },
		{ 21, 4, 12, "|" },
		{ 22, 3, 12, "|" },
		{ 23, 2, 12, "|" },
		{ 24, 1, 11, "\\" },
		{ 25, 0, 10, "_" },
		{ 26, 0,  9, "_" },
		{ 27, 0,  8, "_" },
		{ 28, 0,  7, "_" },
		{ 29, 0,  6, "_" },
		{ 30, 0,  5, "_" },
		{ 31, 0,  4, "_" },
		{ 32, 0,  3, "_" },
		{ 33, 0,  2, "_" },
		{ 34, 0,  1, "_" },
		{ 35, 3,  4, "|" },
		{ 36, 4,  4, "|" },
		{ 37, 4,  5, "_" },
		{ 38, 4,  6, "_" },
		{ 39, 4,  7, "_" },
		{ 40, 4,  8, "|" },
		{ 41, 3,  8, "|" },
		{ 42, 2,  7, "_" },
		{ 43, 2,  6, "_" },
		{ 44, 2,  5, "_" }
	};

}