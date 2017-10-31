#pragma once

#include <vector>
#include "Instruction.h"

namespace Art
{

	std::vector<Instruction> instrNumber2 =
	{
		//     .------------- time
		//    /   .---------- row
		//   /   /   .------- col
		//  /   /   /   .---- the string
		// /   /   /   /
		{  0,  1,  2, "/" },
		{  1,  2,  1, "/" },
		{  2,  3,  0, "." },
		{  3,  4,  0, "|" },
		{  4,  4,  1, "_" },
		{  5,  4,  2, "_" },
		{  6,  4,  3, "_" },
		{  7,  4,  4, "." },
		{  8,  3,  5, "/" },
		{  9,  2,  6, "_" },
		{ 10,  2,  7, "_" },
		{ 11,  3,  8, "\\" },
		{ 12,  4,  9, "|" },
		{ 13,  5,  8, "`" },
		{ 14,  5,  7, "." },
		{ 15,  6,  6, "`" },
		{ 16,  6,  5, "." },
		{ 17,  7,  4, "`" },
		{ 18,  7,  3, "." },
		{ 19,  8,  2, "`" },
		{ 20,  8,  1, "." },
		{ 21,  9,  0, "|" },
		{ 22, 10,  0, "|" },
		{ 23, 10,  1, "_" },
		{ 24, 10,  2, "_" },
		{ 25, 10,  3, "_" },
		{ 26, 10,  4, "_" },
		{ 27, 10,  5, "_" },
		{ 28, 10,  6, "_" },
		{ 29, 10,  7, "_" },
		{ 30, 10,  8, "_" },
		{ 31, 10,  9, "_" },
		{ 32, 10, 10, "_" },
		{ 33, 10, 11, "_" },
		{ 34, 10, 12, "_" },
		{ 35, 10, 13, "|" },
		{ 36,  9, 13, "|" },
		{ 37,  8, 12, "_" },
		{ 38,  8, 11, "_" },
		{ 39,  8, 10, "_" },
		{ 40,  8,  9, "_" },
		{ 41,  8,  8, "_" },
		{ 42,  8,  7, "." },
		{ 43,  8,  8, "`" },
		{ 44,  7,  9, "." },
		{ 45,  7, 10, "`" },
		{ 46,  6, 11, "." },
		{ 47,  6, 12, "`" },
		{ 48,  5, 13, "|" },
		{ 49,  4, 13, "|" },
		{ 50,  3, 13, "." },
		{ 51,  2, 12, "\\" },
		{ 52,  1, 11, "\\" },
		{ 53,  0, 10, "_" },
		{ 54,  0,  9, "_" },
		{ 55,  0,  8, "_" },
		{ 56,  0,  7, "_" },
		{ 57,  0,  6, "_" },
		{ 58,  0,  5, "_" },
		{ 59,  0,  4, "_" },
		{ 60,  0,  3, "_" }
	};

}