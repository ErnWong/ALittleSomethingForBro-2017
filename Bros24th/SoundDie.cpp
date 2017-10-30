#include "stdafx.h"
#include "Sounds.h"

using namespace SoundManager;
using namespace SoundManager::Keys;

namespace Sounds
{

	Sequence die =
	{
		{ INSTRUCTION_TIMING, { 240, 16 } },
		{ INSTRUCTION_PLAY, { E  |6 } },
		{ INSTRUCTION_PLAY, { Es |6 } },
		{ INSTRUCTION_PLAY, { E  |6 } },
		{ INSTRUCTION_PLAY, { Rest  } },
		{ INSTRUCTION_TIMING, { 240, 2 } },
		{ INSTRUCTION_PLAY, { Rest  } },
		{ INSTRUCTION_TIMING, { 240, 16 } },
		{ INSTRUCTION_PLAY, { C  |6 } },
		{ INSTRUCTION_PLAY, { Es |6 } },
		{ INSTRUCTION_PLAY, { B  |5 } },
		{ INSTRUCTION_PLAY, { D  |6 } },
		{ INSTRUCTION_PLAY, { Bes|5 } },
		{ INSTRUCTION_PLAY, { Des|6 } },
		{ INSTRUCTION_PLAY, { A  |5 } },
		{ INSTRUCTION_PLAY, { C  |6 } },
		{ INSTRUCTION_PLAY, { As |5 } },
		{ INSTRUCTION_PLAY, { Ces|6 } },
		{ INSTRUCTION_PLAY, { G  |5 } },
		{ INSTRUCTION_PLAY, { Bes|5 } },
		{ INSTRUCTION_PLAY, { Fis|5 } },
		{ INSTRUCTION_PLAY, { A  |5 } },
		{ INSTRUCTION_PLAY, { F  |5 } },
		{ INSTRUCTION_PLAY, { As |5 } },
		{ INSTRUCTION_PLAY, { E  |5 } },
		{ INSTRUCTION_PLAY, { G  |5 } },
		{ INSTRUCTION_PLAY, { Es |5 } },
		{ INSTRUCTION_PLAY, { Ges|5 } },
		{ INSTRUCTION_PLAY, { D  |5 } },
		{ INSTRUCTION_PLAY, { F  |5 } },
		{ INSTRUCTION_PLAY, { Des|5 } },
		{ INSTRUCTION_PLAY, { Fes|5 } },
		{ INSTRUCTION_TIMING, { 240, 4 } },
		{ INSTRUCTION_PLAY, { C  |5 } },
		{ INSTRUCTION_PLAY, { E  |5 } },
		{ INSTRUCTION_PLAY, { G  |4 } },
		{ INSTRUCTION_PLAY, { C  |5 } },
		{ INSTRUCTION_PLAY, { C  |5 } },
	};

}