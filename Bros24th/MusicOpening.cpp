#include "stdafx.h"
#include "Music.h"

using namespace SoundManager;
using namespace SoundManager::Keys;

namespace Music
{

	Sequence opening =
	{
		{ INSTRUCTION_TIMING, { 120, 8 } },
		{ INSTRUCTION_PLAY, { S|E  |2, Rest,    Rest,  Rest } },
		{ INSTRUCTION_PLAY, { S|F  |2, Rest,    Rest,  Rest } },
		{ INSTRUCTION_PLAY, { S|E  |2, Rest,    Rest,  Rest } },
		{ INSTRUCTION_PLAY, { S|F  |2, Rest,    Rest,  Rest } },
		{ INSTRUCTION_PLAY, { S|E  |2, Rest,    Rest,  Rest } },
		{ INSTRUCTION_PLAY, { S|F  |2, Rest,    Rest,  Rest } },
		{ INSTRUCTION_PLAY, { S|E  |2, Rest,    Rest,  Rest } },
		{ INSTRUCTION_PLAY, { S|F  |2, Rest,    Rest,  Rest } },
		{ INSTRUCTION_PLAY, {   E  |2, S|E  |3,   Rest,  Rest } },
		{ INSTRUCTION_PLAY, {   F  |2, S|F  |3,   Rest,  Rest } },
		{ INSTRUCTION_PLAY, {   E  |2, S|E  |3,   Rest,  Rest } },
		{ INSTRUCTION_PLAY, {   F  |2, S|F  |3,   Rest,  Rest } },
		{ INSTRUCTION_PLAY, {   E  |2, S|E  |3,   Rest,  Rest } },
		{ INSTRUCTION_PLAY, {   F  |2, S|F  |3,   Rest,  Rest } },
		{ INSTRUCTION_PLAY, {   E  |2, S|E  |3,   Rest,  Rest } },
		{ INSTRUCTION_PLAY, {   F  |2, S|F  |3,   Rest,  Rest } },
		{ INSTRUCTION_PLAY, {   E  |2, S|E  |3,   Gis|2, Rest } },
		{ INSTRUCTION_PLAY, {   F  |2, S|F  |3,   A  |2, Rest } },
		{ INSTRUCTION_PLAY, {   E  |2, S|E  |3,   Gis|2, Rest } },
		{ INSTRUCTION_PLAY, {   F  |2, S|F  |3,   A  |2, Rest } },
		{ INSTRUCTION_PLAY, {   E  |2, S|E  |3,   Gis|2, Rest } },
		{ INSTRUCTION_PLAY, {   F  |2, S|F  |3,   A  |2, Rest } },
		{ INSTRUCTION_PLAY, {   E  |2, S|E  |3,   Gis|2, Rest } },
		{ INSTRUCTION_PLAY, {   F  |2, S|F  |3,   A  |2, Rest } },
		{ INSTRUCTION_PLAY, {   Fis|2, S|Fis|3,   A  |2, Rest } },
		{ INSTRUCTION_PLAY, {   G  |2, S|G  |3,   Bes|2, Rest } },
		{ INSTRUCTION_PLAY, {   Fis|2, S|Fis|3,   A  |2, Rest } },
		{ INSTRUCTION_PLAY, {   G  |2, S|G  |3,   Bes|2, Rest } },
		{ INSTRUCTION_PLAY, {   Fis|2, S|Fis|3,   A  |2, Rest } },
		{ INSTRUCTION_PLAY, {   G  |2, S|G  |3,   Bes|2, Rest } },
		{ INSTRUCTION_PLAY, {   Fis|2, S|Fis|3,   A  |2, Rest } },
		{ INSTRUCTION_PLAY, {   G  |2, S|G  |3,   Bes|2, Rest } },
		{ INSTRUCTION_PLAY, {   As |2, S|As |3,   Ces|3, Rest } },
		{ INSTRUCTION_PLAY, {   A  |2, S|A  |3,   C  |3, Rest } },
		{ INSTRUCTION_PLAY, {   As |2, S|As |3,   Ces|3, Rest } },
		{ INSTRUCTION_PLAY, {   A  |2, S|A  |3,   C  |3, Rest } },
		{ INSTRUCTION_PLAY, {   As |2, S|As |3,   Ces|3, Rest } },
		{ INSTRUCTION_PLAY, {   A  |2, S|A  |3,   C  |3, Rest } },
		{ INSTRUCTION_PLAY, {   As |2, S|As |3,   Ces|3, Rest } },
		{ INSTRUCTION_PLAY, {   A  |2, S|A  |3,   C  |3, Rest } },
		{ INSTRUCTION_PLAY, {   Ais|2, S|Ais|3,   Cis|3, Rest } },
		{ INSTRUCTION_TIMING, { 180, 8 } },
		{ INSTRUCTION_PLAY, {   B  |2, S|B  |3,   D  |3, Rest } },
		{ INSTRUCTION_PLAY, {   Bis|2, S|Bis|3,   Dis|3, Rest } },
		{ INSTRUCTION_PLAY, {   Cis|3, S|Cis|4,   E  |3, Rest } },
		{ INSTRUCTION_TIMING, { 120, 8 } },
		{ INSTRUCTION_PLAY, {   D  |3, S|D  |4,   F  |3, Rest } },
		{ INSTRUCTION_PLAY, {   Cis|3, S|Cis|4,   E  |3, Rest } },
		{ INSTRUCTION_PLAY, {   Bis|2, S|Bis|3,   Dis|3, Rest } },
		{ INSTRUCTION_PLAY, {   B  |2, S|B  |3,   D  |3, Rest } },
		{ INSTRUCTION_PLAY, {   Ais|2, S|Ais|3,   Cis|3, Rest } },
		{ INSTRUCTION_PLAY, {   A  |2, S|A  |3,   C  |3, Rest } },
		{ INSTRUCTION_PLAY, {   As |2, S|As |3,   Ces|3, Rest } },
		{ INSTRUCTION_PLAY, {   G  |2, S|G  |3,   Bes|2, Rest } },
		{ INSTRUCTION_PLAY, {   Fis|2, S|Fis|3,   A  |2, Rest } },
		{ INSTRUCTION_PLAY, {   F  |2,    Rest,   As |2, Rest } },
		{ INSTRUCTION_PLAY, { S|E  |2,    Rest, S|G  |2, Rest } },
		{ INSTRUCTION_PLAY, { S|Es |2,    Rest, S|Ges|2, Rest } },
		{ INSTRUCTION_PLAY, { S|D  |2,    Rest, S|F  |2, Rest } },
	};

}
