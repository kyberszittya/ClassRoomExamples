// Labirintus.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

#include "Hero.h"
#include "Padloelem.h"
#include "Labirintus.h"
#include "common.h"

#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

bool isMovingCommand(const std::string& cmd)
{
	return cmd.compare("east") == 0 || cmd.compare("west") == 0 || cmd.compare("north") == 0 || cmd.compare("south") == 0;
}

void game()
{
	Hero hero("Gipsz Jakab");

	Labirintus labirintus(hero);

	labirintus.initializeNeighbors();
	labirintus.initHeroPosition(2, 2);

	std::string cmd;
	MovingDirection dir;

	while (true)
	{
		labirintus.print();
		std::cout << hero << '\n';
		std::cout << "command: ";
		std::cin >> cmd;
		if (isMovingCommand(cmd))
		{
			if (cmd.compare("east") == 0)
			{
				dir = MovingDirection::KELET;
			}
			else if (cmd.compare("west") == 0)
			{
				dir = MovingDirection::NYUGAT;
			}
			else if (cmd.compare("north") == 0)
			{
				dir = MovingDirection::ESZAK;
			}
			else if (cmd.compare("south") == 0)
			{
				dir = MovingDirection::DEL;
			}
			if (!hero.move(dir))
			{
				std::cout << "Invalid direction" << '\n';
			}
		}
		else if (cmd.compare("stay") == 0)
		{

		}
		else if (cmd.compare("exit"))
		{
			break;
		}

	}

	std::cout << "Bye!\n";
}

int main()
{
	game();
#ifdef _WIN32
	_CrtDumpMemoryLeaks();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
#endif // _WIN32
	return 0;
}

