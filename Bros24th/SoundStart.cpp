#include "stdafx.h"
#include "Sounds.h"

using namespace SoundManager;
using namespace SoundManager::Keys;

namespace Sounds
{

	Sequence start =
	{
		{ INSTRUCTION_TIMING, { 200, 16 }},
		{ INSTRUCTION_PLAY, { C|5 } },
		{ INSTRUCTION_PLAY, { F|5 } },
		{ INSTRUCTION_PLAY, { A|5 } },
		{ INSTRUCTION_PLAY, { F|5 } },
		{ INSTRUCTION_PLAY, { G|5 } },
		{ INSTRUCTION_TIMING, { 160, 4 }},
		{ INSTRUCTION_PLAY, { C|6 } },
	};

}