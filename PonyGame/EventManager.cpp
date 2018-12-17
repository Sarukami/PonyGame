#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "EventManager.h"
#include "Event.h"
#include "PonyGame.h"
#include "Pony.h"




EventManager::EventManager()
{
	Event *gp = new Event( "Grand Prix", 1 );
	Event *dash = new Event( "500m dash", 2 );
	Event *beauty = new Event( "Beauty competition", 3 );

	events.push_back(gp);
	events.push_back(dash);
	events.push_back(beauty);

	cup = new Item("Cup", "1st place", 10, 25);
	rose = new Item("Rose", "For a good effort", 11, 4);
}


EventManager::~EventManager(void)
{
	for (unsigned i = 0; i < events.size(); i++)
	{
		delete events.at(i);
	}
}

void EventManager::printAllEvents()
{
	for (unsigned i = 0; i < events.size(); i++)
	{
		events.at(i)->oneLinePrint();
	}
}

void EventManager::enterCompetition(Pony *pony, int eventId)
{
	srand (time(NULL));
	int tempR = rand() % 3 + 1;

	if (eventId == 1)
	{
		std::cout << "Welcome to Grand Prix!" << std::endl;

		switch (tempR)
		{
			case 1:
			{
				std::cout << "Congratulations! You won the grand prize!" << std::endl;
				pony->giveItem(new Item(*cup));
				break;
			}
			case 2:
			{
				std::cout << "For good effort you win this!" << std::endl;
				pony->giveItem(new Item(*rose));
				break;
			}
			case 3:
			{
				std::cout << "Too bad you lost. Better luck next time!" << std::endl;
				break;
			}
			default: {}
		}
	}
	else if (eventId == 2)
	{
		std::cout << "500m dash!" << std::endl;

		switch (tempR)
		{
		case 1:
		{
			std::cout << "Congratulations! You won the 500m dash, you get a prize!" << std::endl;
			pony->giveItem(new Item(*cup));
			break;
		}
		case 2:
		{
			std::cout << "For good effort you win this!" << std::endl;
			pony->giveItem(new Item(*rose));
			break;
		}
		case 3:
		{
			std::cout << "Too bad you lost. Better luck next time!" << std::endl;
			break;
		}
		default: {}
		}
	}
	else if (eventId == 3)
	{
		std::cout << "Beauty competition!" << std::endl;

		switch (tempR)
		{
		case 1:
		{
			std::cout << "Congratulations! You won the beuaty competition, you get a prize!" << std::endl;
			pony->giveItem(new Item(*cup));
			break;
		}
		case 2:
		{
			std::cout << "For good effort you win this!" << std::endl;
			pony->giveItem(new Item(*rose));
			break;
		}
		case 3:
		{
			std::cout << "Too bad you lost. Better luck next time!" << std::endl;
			break;
		}
		default: {}
		}
	}
}