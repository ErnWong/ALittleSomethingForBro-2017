#include "stdafx.h"
#include "Music.h"

using namespace SoundManager;
using namespace SoundManager::Keys;

namespace Music
{

	Sequence prokofiev3 =
	{
		{ INSTRUCTION_TIMING, { 60, 8 } },
		{ INSTRUCTION_BALANCE, { 40, 40 } },
		{ INSTRUCTION_PLAY, {   E  |5,   Rest  } },
		{ INSTRUCTION_PLAY, {   D  |5,   Rest  } },
		{ INSTRUCTION_PLAY, {   A  |5,   Rest  } },
		{ INSTRUCTION_PLAY, {   A  |5,   Rest  } },
		{ INSTRUCTION_PLAY, {   F  |5,   Rest  } },
		{ INSTRUCTION_PLAY, {   F  |5,   Rest  } },

		{ INSTRUCTION_PLAY, {   E  |5,   Rest  } },
		{ INSTRUCTION_PLAY, {   E  |5,   Rest  } },
		{ INSTRUCTION_PLAY, {   B  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   B  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   C  |5,   Rest  } },
		{ INSTRUCTION_PLAY, {   B  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   A  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   G  |4,   Rest  } },

		{ INSTRUCTION_PLAY, {   A  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   A  |4,   Rest  } },
		{ INSTRUCTION_BALANCE, { 20, 20 } },
		{ INSTRUCTION_PLAY, {   E  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   E  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   E  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   E  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   E  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   E  |4,   Rest  } },
			
		{ INSTRUCTION_PLAY, {   E  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   E  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   E  |4,   Rest  } },
		{ INSTRUCTION_PLAY, {   F  |4,   Rest  } },
		{ INSTRUCTION_BALANCE, { 30, 30 } },
		{ INSTRUCTION_PLAY, {   G  |4,   E  |4 } },
		{ INSTRUCTION_PLAY, {   G  |4,   E  |4 } },
		{ INSTRUCTION_PLAY, {   G  |4,   E  |4 } },
		{ INSTRUCTION_PLAY, {   F  |4,   Rest  } },

		{ INSTRUCTION_BALANCE, { 40, 40 } },
		{ INSTRUCTION_PLAY, {   G  |4,   E  |4 } },
		{ INSTRUCTION_PLAY, {   G  |4,   E  |4 } },
		{ INSTRUCTION_PLAY, {   A  |4,   F  |4 } },
		{ INSTRUCTION_PLAY, {   B  |4,   G  |4 } },
		{ INSTRUCTION_PLAY, {   C  |5,   A  |4 } },
		{ INSTRUCTION_PLAY, {   D  |5,   B  |4 } },
		{ INSTRUCTION_TIMING, { 55, 8 } },
		{ INSTRUCTION_BALANCE, { 24, 24 } },
		{ INSTRUCTION_PLAY, {   E  |5,   C  |5 } },
		{ INSTRUCTION_PLAY, {   F  |5,   D  |5 } },

		{ INSTRUCTION_TIMING, { 50, 8 } },
		{ INSTRUCTION_BALANCE, { 20, 20 } },
		{ INSTRUCTION_PLAY, {   G  |5,   E  |5 } },
		{ INSTRUCTION_PLAY, {   G  |5,   E  |5 } },
		{ INSTRUCTION_TIMING, { 45, 8 } },
		{ INSTRUCTION_BALANCE, { 16, 16 } },
		{ INSTRUCTION_PLAY, {   A  |5,   F  |5 } },
		{ INSTRUCTION_PLAY, {   A  |5,   F  |5 } },
		{ INSTRUCTION_TIMING, { 40, 8 } },
		{ INSTRUCTION_BALANCE, { 12, 12 } },
		{ INSTRUCTION_PLAY, {   Ais|5,   Fis|5 } },
		{ INSTRUCTION_PLAY, {   Ais|5,   Fis|5 } },
		{ INSTRUCTION_TIMING, { 35, 16 } },
		{ INSTRUCTION_BALANCE, { 8, 8 } },
		{ INSTRUCTION_PLAY, {   B  |5,   G  |5 } },
		{ INSTRUCTION_BALANCE, { 6, 6 } },
		{ INSTRUCTION_PLAY, {   B  |5,   G  |5 } },
		{ INSTRUCTION_BALANCE, { 4, 4 } },
		{ INSTRUCTION_PLAY, {   B  |5,   G  |5 } },
		{ INSTRUCTION_BALANCE, { 2, 2 } },
		{ INSTRUCTION_PLAY, {   B  |5,   G  |5 } },
	};

}
