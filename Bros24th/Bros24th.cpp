// Bros24th.cpp : Defines the entry point for the console application.
//
//#pragma comment( lib, "Winmm.lib" )

#include "stdafx.h"

#include <Windows.h>
#include <cstring>


#include "Logging.h"

#include "Theatrical.h"

#include "LetterH.h"
#include "LetterA.h"
#include "LetterP.h"
#include "LetterY.h"
#include "Number2.h"
#include "Number4.h"
#include "LetterSmallT.h"
#include "LetterSmallH.h"
#include "PictureWindow.h"
#include "PictureDancer.h"
#include "PictureDoor.h"
#include "PicturePostman.h"
#include "PictureDuck.h"
#include "Sprite.h"

#include "Music.h"
#include "Sounds.h"
#include "SoundManager.h"


int main()
{
	Theatrical::Init();
	HANDLE hConsoleInput = Theatrical::hConsoleInput;
	HANDLE hConsoleOutput = Theatrical::hConsoleOutput;

	SoundManager::Init();
	SoundManager::Add("Happy Fast", Music::happyFast);
	SoundManager::Add("Prokofiev3", Music::prokofiev3);
	SoundManager::Add("Happy Slow", Music::happySlow);
	SoundManager::Add("Toccata", Music::toccata);
	SoundManager::Add("Tension", Music::tension);
	SoundManager::Add("Opening", Music::opening);
	SoundManager::Add("Start", Sounds::start);
	SoundManager::Add("Die", Sounds::die);
	SoundManager::Add("Win", Sounds::win);
	SoundManager::Add("Jump", Sounds::jump);

	LoggingDisable();

BEGINNING:;

	{

		Sleep(700);
		Theatrical::ClearScreen();
		Theatrical::ColorScreen(BACKGROUND_INTENSITY);
		Sleep(300);
		Theatrical::ColorScreen(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		Sleep(700);
		Theatrical::ColorScreen(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		Sleep(700);

		SoundManager::Play("Opening", 255);

		Theatrical::TypeTextCentered("TURN UP VOLUME.", { Theatrical::screenMid.X, Theatrical::screenMid.Y - 3 });
		Sleep(500);
		Theatrical::TypeTextCentered("DON'T HAVE SPEAKERS? PRESS CONTROL-C TO FORFEIT NOW.", { Theatrical::screenMid.X, Theatrical::screenMid.Y - 2 });
		Sleep(2000);
		Theatrical::WaitForKey("PRESS ANY KEY TO START");
		Theatrical::ClearScreen();
		SoundManager::Play("Start");
		Theatrical::TypeTextCentered("AND WE BEGIN...", Theatrical::screenMid);

	}
	{

		Sleep(1500);
		Theatrical::ClearScreen();
		Theatrical::ColorScreen(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		Sleep(1000);
		Theatrical::ColorScreen(BACKGROUND_INTENSITY);
		Sleep(1500);
		Theatrical::ColorScreen(FOREGROUND_RED | FOREGROUND_GREEN);
		Sleep(1000);
		SoundManager::Play("Prokofiev3", 1);
		Sleep(2000);
		SHORT textRow = Theatrical::screenMid.Y - 1;
		Theatrical::TypeText("Once upon a time, in a galaxy far, far away...", { 4, 4 });
		Sleep(1000);
		Theatrical::TypeText("...aka America...", { 10, 5 });
		Sleep(1000);
		Theatrical::TypeText("One young happy hippy nerdy(skux)bro", { 4, textRow });
		Theatrical::TypeText("decided to look out the window", { 4, textRow + 1 });

		Art::Sprite spriteWindow = Art::Sprite(Theatrical::screenMid.Y - 5, Theatrical::screenMax.X - 20, Art::instrPictureWindow);
		WORD windowFrameForeground = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		for (int i = 0; i <= 10; i++)
		{
			spriteWindow.Draw(hConsoleOutput, i + 22);
			WORD attr = BACKGROUND_BLUE | (i >= 7 ? BACKGROUND_GREEN | BACKGROUND_RED : 0) | windowFrameForeground;
			if (i == 0 || i == 10)
			{
				attr = FOREGROUND_RED | FOREGROUND_GREEN;
			}
			DWORD charsWritten;
			COORD pos;
			pos.X = (short)(spriteWindow.col + 2);
			pos.Y = (short)(spriteWindow.row + i);
			FillConsoleOutputAttribute(hConsoleOutput, attr, 15, pos, &charsWritten);
			Sleep(100);
		}

		Sleep(1500);
		for (int i = 0; i <= 10; i++)
		{
			spriteWindow.Draw(hConsoleOutput, i + 11);
			WORD attr = BACKGROUND_BLUE | (i >= 7 ? BACKGROUND_GREEN | BACKGROUND_RED : 0) | windowFrameForeground;
			if (i == 0 || i == 10)
			{
				attr = FOREGROUND_RED | FOREGROUND_GREEN;
			}
			DWORD charsWritten;
			COORD pos;
			pos.X = (short)(spriteWindow.col + 2);
			pos.Y = (short)(spriteWindow.row + i);
			FillConsoleOutputAttribute(hConsoleOutput, attr, 15, pos, &charsWritten);
		}
		Sleep(500);
		for (int i = 0; i <= 10; i++)
		{
			spriteWindow.Draw(hConsoleOutput, i);
			WORD attr = BACKGROUND_BLUE | (i >= 7 ? BACKGROUND_GREEN | BACKGROUND_RED : 0) | windowFrameForeground;
			if (i == 0 || i == 10)
			{
				attr = FOREGROUND_RED | FOREGROUND_GREEN;
			}
			DWORD charsWritten;
			COORD pos;
			pos.X = (short)(spriteWindow.col + 2);
			pos.Y = (short)(spriteWindow.row + i);
			FillConsoleOutputAttribute(hConsoleOutput, attr, 15, pos, &charsWritten);
		}

		Sleep(1000);

		Theatrical::TypeText("to watch the glowing Autumn sunset", { 4, textRow + 2 });
		Theatrical::TypeText("melt into the horizons...", { 4, textRow + 3 });

		Sleep(1000);
		for (int i = 0; i <= 10; i++)
		{
			WORD attr = BACKGROUND_GREEN | BACKGROUND_RED | windowFrameForeground;
			if (i >= 7)
			{
				attr = BACKGROUND_INTENSITY | windowFrameForeground;
			}
			if (i == 0 || i == 10)
			{
				attr = FOREGROUND_RED | FOREGROUND_GREEN;
			}
			DWORD charsWritten;
			COORD pos;
			pos.X = (short)(spriteWindow.col + 2);
			pos.Y = (short)(spriteWindow.row + i);
			FillConsoleOutputAttribute(hConsoleOutput, attr, 15, pos, &charsWritten);
			Sleep(100);
		}

		while (true)
		{
			COORD pos = { Theatrical::screenMax.X - 20, Theatrical::screenMax.Y };
			Theatrical::WaitForKey("PRESS ANY KEY TO CONTINUE", pos);
			if (SoundManager::IsPlaying())
			{
				Theatrical::TypeTextCentered("BE PATIENT BRO. MUSIC HASNT FINISHED YET", pos);
				Theatrical::TypeTextCentered("                                        ", pos);
				continue;
			}
			break;
		}

	}
	{

		Theatrical::ClearScreen();
		Theatrical::ColorScreen(BACKGROUND_RED);
		SoundManager::Play("Tension", 255);

		Theatrical::TypeText("DING DONG!", { 4, 4 });
		Theatrical::TypeText("Someone is at the door.", { 4, 5 });

		Art::Sprite spriteDoor = Art::Sprite(2, Theatrical::screenMax.X - 27, Art::instrPictureDoor);
		for (int i = 0; i <= 20; i++)
		{
			spriteDoor.Draw(hConsoleOutput, i);
			Sleep(50);
		}
		Theatrical::TypeText("Who could it be?", { 4, 7 });
		Theatrical::TypeText("Who could possibly be visiting you", { 4, 8 });
		Theatrical::TypeText("bro out in the states?", { 4, 9 });
		Sleep(500);
		Theatrical::TypeText("Could it be...", { 4, 10 });
		Sleep(500);
		Theatrical::TypeText(" the evil chicken?!", { 15, 10 });
		Sleep(200);
		Theatrical::TypeText("                   ", { 15, 10 });
		Theatrical::TypeText(" the omae wa mou shindeiru guy?!!", { 15, 10 });
		Sleep(200);
		Theatrical::TypeText("                                 ", { 15, 10 });
		Theatrical::TypeText(" your mum?!!!!1!", { 15, 10 });
		Sleep(200);
		Theatrical::TypeText("                ", { 15, 10 });
		Theatrical::TypeText("...who knows...", { 15, 10 });
		Sleep(200);
		Theatrical::TypeText("What will you do?", { 4, 12 });
		Theatrical::TypeText(" ANSWER DOOR", { 10, 14 });
		Theatrical::TypeText(" JUMP OUT OF WINDOW", { 30, 14 });

		bool jumpWindow = true;
		while (true)
		{
			switch (jumpWindow)
			{
			case true:
				SetConsoleCursorPosition(hConsoleOutput, { 10, 15 });
				printf("             ");
				SetConsoleCursorPosition(hConsoleOutput, { 30, 15 });
				printf("====================");
				break;
			case false:
				SetConsoleCursorPosition(hConsoleOutput, { 10, 15 });
				printf("=============");
				SetConsoleCursorPosition(hConsoleOutput, { 30, 15 });
				printf("                    ");
				break;
			}
			WORD key = Theatrical::WaitForKey("CHOOSE = ARROW KEYS, SELECT = ENTER", { Theatrical::screenMax.X - 20, Theatrical::screenMax.Y });
			switch (key)
			{
			case VK_LEFT:
				jumpWindow = false;
				break;
			case VK_RIGHT:
				jumpWindow = true;
				break;
			case VK_RETURN:
				goto AFTER_THE_BIG_DECISION;
				break;
			}
		}
	AFTER_THE_BIG_DECISION:;

		if (jumpWindow)
		{
			Theatrical::ClearScreen();
			Theatrical::ColorScreen(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			SoundManager::Play("Die");
			Sleep(1000);
			Theatrical::TypeTextCentered("EVENT: TOMINOOBZ GOT SCARED TO DEATH.", { Theatrical::screenMid.X, Theatrical::screenMid.Y - 2 });
			Sleep(1000);
			Theatrical::WaitForKey("PRESS ANY KEY TO ACCEPT YOUR FATE AND SOCIAL STATUS");
			goto BEGINNING;
		}

	}
	{

		Theatrical::ClearScreen();
		Theatrical::ColorScreen(0);
		Sleep(500);
		Theatrical::ColorScreen(BACKGROUND_INTENSITY);
		Sleep(500);
		SoundManager::Stop();
		Theatrical::ColorScreen(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		Sleep(500);
		Theatrical::ColorScreen(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);

		SoundManager::Play("Opening", 1000);

		Theatrical::TypeTextCentered("QUEST: RUN THROUGH THE HALLWAY TO THE DOOR", { Theatrical::screenMid.X, Theatrical::screenMid.Y - 2 });
		Theatrical::TypeTextCentered("WITHOUT TRIPPING OVER ALL YOUR LITTER.", { Theatrical::screenMid.X, Theatrical::screenMid.Y - 1 });
		Theatrical::TypeTextCentered("ARE YOU READY?", { Theatrical::screenMid.X, Theatrical::screenMid.Y + 1 });

		Theatrical::WaitForKey("PRESS ANY KEY TO BEGIN", { Theatrical::screenMid.X, Theatrical::screenMid.Y + 3 });

		SoundManager::Play("Start");

		Theatrical::ClearScreen();

	}

	{
		const SHORT offsetX = 4;
		const SHORT offsetY = Theatrical::screenMid.Y;
		const SHORT height = 4;
		const SHORT width = Theatrical::screenMax.X - 8;
		SHORT ceilingY = 0;
		SHORT floorY = height - 1;
		SHORT heroX = 0;
		SHORT heroY = floorY;
		SHORT doorX = width - 1;
		SHORT doorY = floorY;
		SetConsoleCursorPosition(hConsoleOutput, { offsetX + doorX, offsetY + doorY });
		printf("D");
		const int litterCount = 6;
		SHORT litterX[litterCount];
		SHORT litterHeight[litterCount];
		SHORT litterRegionSize = width / (litterCount + 1) - 1;
		for (SHORT i = 0; i < litterCount; i++)
		{
			litterX[i] = litterRegionSize * (i + 1) + (SHORT)(litterRegionSize * (double)std::rand() / RAND_MAX);
			litterHeight[i] = std::rand() % 2 + 1;
			SetConsoleCursorPosition(hConsoleOutput, { offsetX + litterX[i], offsetY + height - 1 });
			printf("#");
			if (litterHeight[i] > 1)
			{
				SetConsoleCursorPosition(hConsoleOutput, { offsetX + litterX[i], offsetY + height - 2 });
				printf("#");
			}
		}
		for (SHORT x = 0; x < width; x++)
		{
			SetConsoleCursorPosition(hConsoleOutput, { offsetX + x, offsetY + height });
			printf("^");
		}
		SetConsoleCursorPosition(hConsoleOutput, { offsetX, offsetY + height + 2 });
		printf("USE ARROW KEYS TO MOVE YOURSELF (X) TO THE DOOR (D).");
		SetConsoleCursorPosition(hConsoleOutput, { offsetX, offsetY + height + 3 });
		printf("USE UP ARROW TO JUMP OVER OBSTACLES (#)");
		bool keyLeft = false;
		bool keyRight = false;
		bool keyUp = false;
		bool jumping = false;
		while (true)
		{
			DWORD numEvents;
			GetNumberOfConsoleInputEvents(hConsoleInput, &numEvents);
			if (numEvents)
			{
				DWORD eventCount;
				GetNumberOfConsoleInputEvents(hConsoleInput, &eventCount);
				if (eventCount)
				{
					INPUT_RECORD events[256];
					DWORD readCount;
					ReadConsoleInput(hConsoleInput, (PINPUT_RECORD)&events, 256, &readCount);
					for (DWORD i = 0; i < readCount; i++)
					{
						if (events[i].EventType != KEY_EVENT) continue;
						switch (events[i].Event.KeyEvent.wVirtualKeyCode)
						{
						case VK_UP:
							keyUp = events[i].Event.KeyEvent.bKeyDown;
							break;
						case VK_LEFT:
							keyLeft = events[i].Event.KeyEvent.bKeyDown;
							break;
						case VK_RIGHT:
							keyRight = events[i].Event.KeyEvent.bKeyDown;
							break;
						}
					}
				}
			}
			heroX += keyRight - keyLeft;
			if (heroX < 0) heroX = 0;
			if (heroX >= width) heroX = width - 1;
			if (heroY == floorY)
			{
				if (keyUp)
				{
					jumping = true;
					heroY--;
					SoundManager::Play("Jump");
				}
			}
			else
			{
				if (jumping && heroY == ceilingY)
				{
					jumping = false;
				}
				heroY -= jumping * 2 - 1;
			}
			SetConsoleCursorPosition(hConsoleOutput, { offsetX + heroX, offsetY + heroY });
			printf("X");
			SetConsoleCursorPosition(hConsoleOutput, Theatrical::screenMax);
			for (int i = 0; i < litterCount; i++)
			{
				if (heroX == litterX[i] && height - heroY <= litterHeight[i])
				{
					SoundManager::Play("Die");
					Sleep(1000);
					Theatrical::ClearScreen();
					Theatrical::ColorScreen(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					Sleep(1000);
					Theatrical::TypeTextCentered("EVENT: TOMINOOBZ TRIPPED TO HIS DEATH.", {Theatrical::screenMid.X, Theatrical::screenMid.Y-2});
					Sleep(1000);
					Theatrical::WaitForKey("PRESS ANY KEY TO ACCEPT YOUR FATE AND FITNESS LEVEL");
					goto BEGINNING;
				}
			}
			if (heroX == doorX && heroY == doorY)
			{
				break;
			}
			Sleep(1000 / 16);
			SetConsoleCursorPosition(hConsoleOutput, { offsetX + heroX, offsetY + heroY });
			printf(" ");
		}
		SoundManager::Play("Win");
		Sleep(1000);
	}
	{

		Theatrical::ClearScreen();
		Sleep(500);
		Theatrical::ColorScreen(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		Sleep(500);
		Theatrical::ColorScreen(BACKGROUND_INTENSITY);
		Sleep(500);
		Theatrical::ColorScreen(0);
		Sleep(500);
		Theatrical::ColorScreen(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Sleep(500);
		SoundManager::Play("Prokofiev3");
		Sleep(500);
		SHORT textRow = Theatrical::screenMid.Y;
		Theatrical::TypeText("Turns out it's the postman.", { 3, textRow - 3 });
		Art::Sprite spritePostman = Art::Sprite(textRow - 5, Theatrical::screenMax.X - 34, Art::instrPicturePostman);
		for (int i = 0; i <= 9; i++)
		{
			spritePostman.Draw(hConsoleOutput, i);
			Sleep(100);
		}
		Sleep(1000);
		Theatrical::TypeText("You receive a parcel!", { 3, textRow - 2 });
		Sleep(1000);
		Theatrical::WaitForKey("PRESS ANY KEY TO OPEN THE PARCEL", { Theatrical::screenMax.X - 18, Theatrical::screenMax.Y });
		Sleep(1000);
		Theatrical::TypeText("It's a DVD.", { 3, textRow - 1 });
		Sleep(1000);
		Theatrical::TypeText("You head over to the TV, insert the disk,", { 3, textRow });
		Theatrical::TypeText("and you lean back against your sofa", { 3, textRow + 1 });
		Sleep(1000);
		Theatrical::TypeText("as the video begins to play...", { 3, textRow + 2 });
		Sleep(500);
		Theatrical::WaitForKey("PRESS ANY KEY TO CONTINUE", { Theatrical::screenMax.X - 15, Theatrical::screenMax.Y });

	}

	Theatrical::ClearScreen();
	Sleep(500);
	SoundManager::Stop();
	Theatrical::ColorScreen(BACKGROUND_RED);
	Sleep(200);
	Theatrical::ColorScreen(BACKGROUND_GREEN);
	Sleep(200);
	Theatrical::ColorScreen(BACKGROUND_BLUE);
	Sleep(200);
	Theatrical::ColorScreen(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
	Sleep(1000);

	SoundManager::Play("Happy Slow");
	
	Art::Sprite spriteH  = Art::Sprite(3,  2, Art::instrLetterH);
	Art::Sprite spriteA  = Art::Sprite(3, 18, Art::instrLetterA);
	Art::Sprite spriteP1 = Art::Sprite(3, 34, Art::instrLetterP);
	Art::Sprite spriteP2 = Art::Sprite(3, 49, Art::instrLetterP);
	Art::Sprite spriteY  = Art::Sprite(3, 63, Art::instrLetterY);

	Art::Sprite sprite2  = Art::Sprite(12, 4, Art::instrNumber2);
	Art::Sprite sprite4  = Art::Sprite(12, 22, Art::instrNumber4);
	Art::Sprite spriteST = Art::Sprite(12, 40, Art::instrLetterSmallT);
	Art::Sprite spriteSH = Art::Sprite(12, 46, Art::instrLetterSmallH);

	Art::Sprite spriteDuck = Art::Sprite(17, 56, Art::instrPictureDuck);

	const int timeSep = 30;
	const int tailSize = 20;
	for (int i = 0; i < 500; i++)
	{
		spriteH .Draw(hConsoleOutput, i - timeSep * 0 - tailSize, " ");
		spriteA .Draw(hConsoleOutput, i - timeSep * 1 - tailSize, " ");
		spriteP1.Draw(hConsoleOutput, i - timeSep * 2 - tailSize, " ");
		spriteP2.Draw(hConsoleOutput, i - timeSep * 3 - tailSize, " ");
		spriteY .Draw(hConsoleOutput, i - timeSep * 4 - tailSize, " ");
		spriteH .Draw(hConsoleOutput, i - timeSep * 0);
		spriteA .Draw(hConsoleOutput, i - timeSep * 1);
		spriteP1.Draw(hConsoleOutput, i - timeSep * 2);
		spriteP2.Draw(hConsoleOutput, i - timeSep * 3);
		spriteY .Draw(hConsoleOutput, i - timeSep * 4);
		sprite2 .Draw(hConsoleOutput, i - timeSep * 5);
		sprite4 .Draw(hConsoleOutput, i - timeSep * 6);
		spriteST.Draw(hConsoleOutput, i - timeSep * 7);
		spriteSH.Draw(hConsoleOutput, i - timeSep * 7);
		spriteH .Draw(hConsoleOutput, i - timeSep * 0 - 2 * tailSize);
		spriteA .Draw(hConsoleOutput, i - timeSep * 1 - 2 * tailSize);
		spriteP1.Draw(hConsoleOutput, i - timeSep * 2 - 2 * tailSize);
		spriteP2.Draw(hConsoleOutput, i - timeSep * 3 - 2 * tailSize);
		spriteY .Draw(hConsoleOutput, i - timeSep * 4 - 2 * tailSize);
		spriteDuck.Draw(hConsoleOutput, (i - timeSep * 10) / 2);
		Sleep(50);
	}

	SoundManager::Play("Happy Fast", 1);

	std::vector<Art::Sprite> spriteEmojis;

	for (SHORT x = 4; x < Theatrical::screenMax.X - 8; x += 9)
		spriteEmojis.emplace_back(1, x, Art::instrPictureDancer);

	for (SHORT x = 8; x < Theatrical::screenMax.X - 8; x += 9)
		spriteEmojis.emplace_back(2, x, Art::instrPictureDancer);

	/*for (SHORT x = 4; x < Theatrical::screenMax.X - 8; x += 9)
		spriteEmojis.emplace_back(24, x, Art::instrPictureDancer);

	for (SHORT x = 8; x < Theatrical::screenMax.X - 8; x += 9)
		spriteEmojis.emplace_back(25, x, Art::instrPictureDancer);*/

	for (int i = 0; i < 63; i++)
	{
		WORD attributes = 0;
		if ((i-0) % 6 < 3) attributes |= BACKGROUND_RED;
		if ((i-2) % 6 < 3) attributes |= BACKGROUND_GREEN;
		if ((i-4) % 6 < 3) attributes |= BACKGROUND_BLUE;
//		if ((i-3) % 6 < 3) attributes |= FOREGROUND_RED;
//		if ((i-5) % 6 < 3) attributes |= FOREGROUND_GREEN;
//		if ((i-1) % 6 < 3) attributes |= FOREGROUND_BLUE;
		attributes |= BACKGROUND_INTENSITY;
		Theatrical::ColorScreen(attributes);

		for (int k = 0; k < 4; k++)
		{
			spriteDuck.Draw(hConsoleOutput, k + ((i + 1) % 2) * 4);
		}

		int j = 0;
		for (Art::Sprite& emoji : spriteEmojis)
		{
			int t1 = (j % 2)*10 + ((i-1) % 2) + 4;
			int t2 = (j % 2)*10 + (i % 2) + 4;
			emoji.Draw(hConsoleOutput, t1,"       ");
			if (emoji.row % 2)
			{
				emoji.col++;
				if (emoji.col > Theatrical::screenMax.X - 8)
					emoji.col = 4;
			}
			else
			{
				emoji.col--;
				if (emoji.col < 4)
					emoji.col = Theatrical::screenMax.X - 8;
			}
			emoji.Draw(hConsoleOutput, t2);
			j++;
		}
		Theatrical::TidyBorder();
		SoundManager::WaitTillNextBeat(4);
	}

	Theatrical::ClearScreen();
	Theatrical::ColorScreen(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	SetConsoleCursorPosition(hConsoleOutput, { Theatrical::screenMid.X - 3, Theatrical::screenMid.Y });
	printf("THE");
	SoundManager::WaitTillNextBeat(4);
	SetConsoleCursorPosition(hConsoleOutput, { Theatrical::screenMid.X - 3, Theatrical::screenMid.Y });
	printf("THE END");

	Sleep(1000);

	Theatrical::ClearScreen();
	SoundManager::Play("Toccata", 255);
	Theatrical::TypeTextCentered("OpenRCT2 Server:", { Theatrical::screenMid.X, Theatrical::screenMid.Y - 2 });
	Theatrical::TypeTextCentered("Wong Bros Tycoon", { Theatrical::screenMid.X, Theatrical::screenMid.Y - 1 });
	Theatrical::TypeTextCentered("wongbros.hopto.org:11753", { Theatrical::screenMid.X, Theatrical::screenMid.Y + 0 });
	Theatrical::TypeTextCentered("Available upon request - Add to favourites", { Theatrical::screenMid.X, Theatrical::screenMid.Y + 1 });
	Theatrical::TypeTextCentered("Requires password, and me turning on my computer", { Theatrical::screenMid.X, Theatrical::screenMid.Y + 2 });

	Sleep(2000);

	Theatrical::WaitForKey("PRESS ANY KEY TO EXIT", { Theatrical::screenMax.X - 15, Theatrical::screenMax.Y });

	Theatrical::ClearScreen();
	SoundManager::Play("Die");
	Sleep(1000);
	Theatrical::ColorScreen(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Sleep(1000);
	Theatrical::TypeTextCentered("EVENT: TOMINOOBZ GOT LOL'ED.", {Theatrical::screenMid.X, Theatrical::screenMid.Y-2});
	Sleep(3000);

	SoundManager::Teardown();

    return 0;
}
