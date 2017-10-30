#include "stdafx.h"
#include "Sounds.h"

using namespace SoundManager;
using namespace SoundManager::Keys;

namespace Sounds
{

	Sequence jump =
	{
		{ INSTRUCTION_TIMING,{ 200, 32 } },
		{ INSTRUCTION_PLAY,{ B  | 5 } },
		{ INSTRUCTION_PLAY,{ C  | 6 } },
		{ INSTRUCTION_PLAY,{ Cis| 6 } },
		{ INSTRUCTION_PLAY,{ D  | 6 } },
		{ INSTRUCTION_PLAY,{ D  | 6 } },
	};

}