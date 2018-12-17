#include <iostream>
#include "PonyGame.h"
#include "Pony.h"
#include "EventManager.h"
#include "Event.h"
#include "GameObject.h"
#include "Store.h"
#include "Eatable.h"
#include "Item.h"
#include "FileHandler.h"


PonyGame::PonyGame()
{
	filehandler = new FileHandler("Pony_save.txt", "Prizes_save.txt");
	eventManager = new EventManager();
	store = new Store();
}

PonyGame::~PonyGame(void)
{
	delete pony;
	delete filehandler;
	delete eventManager;
	delete store;
}

void PonyGame::mainMenu()
{
	int input;

	do
	{
		std::cout << ".-.-.Welcome.to.play.-.PonyGame.-.-." << std::endl;
		std::cout << std::endl;
		std::cout << "´----------------------------------´" << std::endl;
		std::cout << "|            Main Menu             |" << std::endl;
		std::cout << "´----------------------------------´" << std::endl;
		std::cout << "|  [1] New game                    |" << std::endl;
		std::cout << "|  [2] Continue                    |" << std::endl;
		std::cout << "|  [3] Save game                   |" << std::endl;
		std::cout << "|  [4] Load game                   |" << std::endl;
		std::cout << "|  [0] Quit                        |" << std::endl;
		std::cout << "´----------------------------------´" << std::endl;
		std::cout << "  -> ";
		std::cin >> input;

		switch (input)
		{
			case 1:
			{
				pony = new Pony("Silver", "The best pony", "Pony", 100.0, 50.0, 1);
				menu();
				break;
			}
			case 2:
			{
				if (pony == NULL)
				{
					pony = new Pony("Silver", "The best pony", "Pony", 100.0, 50.0, 1);
				}
				menu();
				break;
			}
			case 3:
			{
				filehandler->savePony(pony);

				for (unsigned i = 0; i < pony->getItems().size(); i++)
				{
					filehandler->savePrize(pony->getItems().at(i));
				}

				std::cout << "---Game Saved---" << std::endl;
				std::cout << std::endl;
				break;
			}
			case 4:
			{
				if (pony != NULL)
				{
					std::cout << "---Deleting old pony---" << std::endl;
					delete pony;
				}
				pony = filehandler->loadPony();
				std::vector<Item*> ponyItems = filehandler->loadPrizes();

				for (unsigned i = 0; i < ponyItems.size(); i++)
				{
					pony->giveItem(ponyItems.at(i));
				}

				std::cout << "---Game Loaded---" << std::endl;

				menu();
				break;
			}
			case 0:
			{
				break;
			}
		}
	} while (input != 0);
}

void PonyGame::menu()
{
	int choice;

	do 
	{
		std::cout << std::endl;
		std::cout << "´----------------------------------´" << std::endl;
		std::cout << "|               Menu               |" << std::endl;
		std::cout << "´----------------------------------´" << std::endl;
		std::cout << "|  [1] Pony info                   |" << std::endl;
		std::cout << "|  [2] Update info                 |" << std::endl;
		std::cout << "|  [3] Feed pony                   |" << std::endl;
		std::cout << "|  [4] Competition                 |" << std::endl;
		std::cout << "´----------------------------------´" << std::endl;
		std::cout << "|              Store               |" << std::endl;
		std::cout << "´----------------------------------´" << std::endl;
		std::cout << "|  [5] Items                       |" << std::endl;
		std::cout << "|  [6] Buy                         |" << std::endl;
		std::cout << "|  [7] Sell                        |" << std::endl;
		std::cout << "|  [0] Back                        |" << std::endl;
		std::cout << "´----------------------------------´" << std::endl;
		std::cout << "  -> ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
			case 1:
			{
				pony->print();
				break;
			}
			case 2:
			{
				pony->updateInfo();
				break;
			}
			case 3:
			{
				store->eatMenu(pony);

				break;
			}
			case 4:
			{
				int eventId;
				do
				{
					eventId = 0;
					eventManager->printAllEvents();
					std::cout << "Which event do you want to participate? [0] to exit" << std::endl << "  -> ";
					std::cin >> eventId;
					switch (eventId)
					{
						case 1:
						{
							eventManager->enterCompetition(pony, eventId);
							break;
						}
						case 2:
						{
							eventManager->enterCompetition(pony, eventId);
							break;
						}
						case 3:
						{
							eventManager->enterCompetition(pony, eventId);
							break;
						}
						case 0:
						{
							break;
						}
					}
				} while (eventId != 0);
				break;
			}
			case 5:
			{
				std::cout << "---Eatables---" << std::endl;
				store->printEatables();
				std::cout << std::endl;
				std::cout << "---Items---" << std::endl;
				store->printItems();
				std::cout << std::endl;
				break;
			}
			case 6:
			{
				store->buyMenu(pony);
				break;
			}
			case 7:
			{
				store->sellMenu(pony);
				break;
			}
			case 0:
			{
				break;
			}
		}
	} while (choice != 0);
}