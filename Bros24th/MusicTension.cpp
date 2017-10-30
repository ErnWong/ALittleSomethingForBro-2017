#include "stdafx.h"
#include "Music.h"

using namespace SoundManager;
using namespace SoundManager::Keys;

namespace Music
{

	Sequence tension =
	{
		{ INSTRUCTION_TIMING, { 120, 16 } },
		{ INSTRUCTION_BALANCE, { 20, 20, 60, 140 } },
		{ INSTRUCTION_INSTRUMENT, { INSTRUMENT_SQUARE, INSTRUMENT_SQUARE, INSTRUMENT_SQUARE, INSTRUMENT_NOISE } },
		{ INSTRUCTION_PLAY, { S|B  |3, S|B  |2, S|B  |4, S| 1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3, S|B  |2,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3, S|B  |2,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3, S|B  |2, S|B  |4, S| 1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|A  |3, S|Dis|2, S|A  |4, S| 1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3, S|B  |2,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3, S|B  |2,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest , S| 1 } },
		{ INSTRUCTION_PLAY, { S|A  |3, S|Dis|2, S|A  |4, S| 1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest , S| 1 } },
		{ INSTRUCTION_PLAY, { S|G  |3, S|E  |2, S|G  |4, S| 1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3, S|B  |2,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3, S|B  |2,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|G  |3, S|E  |2, S|G  |4, S| 1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|Fis|3, S|E  |2, S|Fis|4, S| 1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3, S|B  |2,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3, S|B  |2,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest ,    1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest , S| 1 } },
		{ INSTRUCTION_PLAY, { S|Fis|3, S|E  |2, S|Fis|4, S| 1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest , S| 1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest , S| 1 } },
		{ INSTRUCTION_PLAY, { S|B  |3,   Rest ,   Rest , S| 1 } },
	};

}
