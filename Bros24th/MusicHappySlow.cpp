#include "stdafx.h"
#include "Music.h"

using namespace SoundManager;
using namespace SoundManager::Keys;

namespace Music
{

	Sequence happySlow =
	{
		{ INSTRUCTION_BALANCE, { 255, 0, 0, 0 } },
		{ INSTRUCTION_TIMING, { 60, 16 } },
		{ INSTRUCTION_PLAY, {   G  |3 } },
		{ INSTRUCTION_PLAY, {   G  |3 } },
		{ INSTRUCTION_PLAY, { S|G  |3 } },
		{ INSTRUCTION_PLAY, {   G  |3 } },
		{ INSTRUCTION_TIMING, { 60, 4 } },
		{ INSTRUCTION_PLAY, {   A  |3 } },
		{ INSTRUCTION_PLAY, {   G  |3 } },
		{ INSTRUCTION_PLAY, {   C  |4 } },
		{ INSTRUCTION_PLAY, {   B  |3 } },
		{ INSTRUCTION_PLAY, {   Rest  } },
		{ INSTRUCTION_TIMING, { 60, 16 } },
		{ INSTRUCTION_PLAY, {   G  |3 } },
		{ INSTRUCTION_PLAY, {   G  |3 } },
		{ INSTRUCTION_PLAY, { S|G  |3 } },
		{ INSTRUCTION_PLAY, {   G  |3 } },
		{ INSTRUCTION_TIMING, { 60, 4 } },
		{ INSTRUCTION_PLAY, {   A  |3 } },
		{ INSTRUCTION_PLAY, {   G  |3 } },
		{ INSTRUCTION_PLAY, {   D  |4 } },
		{ INSTRUCTION_PLAY, {   C  |4 } },
		{ INSTRUCTION_PLAY, {   Rest  } },
		{ INSTRUCTION_TIMING, { 60, 16 } },
		{ INSTRUCTION_PLAY, {   G  |3 } },
		{ INSTRUCTION_PLAY, {   G  |3 } },
		{ INSTRUCTION_PLAY, { S|G  |3 } },
		{ INSTRUCTION_PLAY, {   G  |3 } },
		{ INSTRUCTION_TIMING, { 60, 4 } },

		{ INSTRUCTION_PLAY, {   Ges|4 } },
		{ INSTRUCTION_PLAY, {   Es |4 } },
		{ INSTRUCTION_PLAY, {   Ces|4 } },
		{ INSTRUCTION_PLAY, {   Bes|3 } },
		{ INSTRUCTION_PLAY, { S|As |3 } },
		{ INSTRUCTION_TIMING, { 60, 16 } },
		{ INSTRUCTION_PLAY, {   E  |4 } },
		{ INSTRUCTION_PLAY, {   E  |4 } },
		{ INSTRUCTION_PLAY, { S|E  |4 } },
		{ INSTRUCTION_PLAY, {   E  |4 } },
		{ INSTRUCTION_TIMING, { 60, 4 } },
		{ INSTRUCTION_PLAY, {   Dis|4} },
		{ INSTRUCTION_PLAY, {   B  |3} },
		{ INSTRUCTION_PLAY, {   Cis|4} },
		{ INSTRUCTION_PLAY, {   Bis|3} },
		{ INSTRUCTION_PLAY, {   Rest  } },
		{ INSTRUCTION_TIMING, { 60, 16 } },

    /*
		{ INSTRUCTION_BALANCE, { 80, 80, 80, 0 } },
		{ INSTRUCTION_PLAY, {   Ges|4,   F  |4,   E  |4 } },
		{ INSTRUCTION_PLAY, {   Es |4,   D  |4,   Cis|4 } },
		{ INSTRUCTION_PLAY, {   Ces|4,   Bes|3,   A  |3 } },
		{ INSTRUCTION_PLAY, {   Bes|3,   A  |3,   Gis|3 } },
		{ INSTRUCTION_PLAY, { S|As |3,   G  |3,   Fis|3 } },
		{ INSTRUCTION_TIMING, { 60, 16 } },
		{ INSTRUCTION_PLAY, {   E  |4,   Es |4,   D  |4 } },
		{ INSTRUCTION_PLAY, {   E  |4,   Es |4,   D  |4 } },
		{ INSTRUCTION_PLAY, { S|E  |4, S|Es |4, S|D  |4 } },
		{ INSTRUCTION_PLAY, {   E  |4,   Es |4,   D  |4 } },
		{ INSTRUCTION_TIMING, { 60, 4 } },
		{ INSTRUCTION_BALANCE, { 60, 60, 60, 0 } },
		{ INSTRUCTION_PLAY, {   Dis|4,   D  |4,   Cis|4 } },
		{ INSTRUCTION_BALANCE, { 40, 40, 40, 0 } },
		{ INSTRUCTION_PLAY, {   B  |3,   Bes|3,   A  |3 } },
		{ INSTRUCTION_BALANCE, { 20, 20, 20, 0 } },
		{ INSTRUCTION_PLAY, {   Cis|4,   C  |4,   B  |3 } },
		{ INSTRUCTION_BALANCE, { 10, 10, 10, 0 } },
		{ INSTRUCTION_PLAY, {   Bis|3,   Bes|3,   A  |3 } },
		{ INSTRUCTION_PLAY, {   Rest  } },
		{ INSTRUCTION_TIMING, { 60, 16 } },*/
	};

}
