#include <vector>
#include <string>
#include "Store.h"

Store::Store()
{

	Eatable *Carrot = new Eatable("Carrot", "Ponies like these", 1, 1.99, 5.0);
	Eatable *Potato = new Eatable("Potato", "Good ol' potatoes", 2, 0.95, 2.5);

	Item *Sadle = new Item("Sadle", "For more confortable rides", 1, 12.99);
	Item *Brush = new Item("Brush", "Made for ponies", 2, 7.99);
	Item *LazerRifle = new Item("LazerRifle", "Tool of mass destruction", 3, 6.99);

	eatables.push_back(Carrot);
	eatables.push_back(Potato);
	items.push_back(Sadle);
	items.push_back(Brush);
	items.push_back(LazerRifle); 
}


Store::~Store()
{
	for (unsigned i = 0; i < eatables.size(); i++)
	{
		delete eatables.at(i);
	}
	for (unsigned i = 0; i < items.size(); i++)
	{
		delete items.at(i);
	}
}

void Store::printItems()
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		items.at(i)->oneLinePrint();
	}
}

void Store::printEatables()
{
	for (unsigned i = 0; i < eatables.size(); i++)
	{
		eatables.at(i)->oneLinePrint();
	}
}

void Store::buyMenu(Pony *pony)
{
	int buyOption;
	bool looping = true;

	std::cout << "´----------------------------------´" << std::endl;
	std::cout << "|            Buy items             |" << std::endl;
	std::cout << "´----------------------------------´" << std::endl;
	std::cout << "|  [1] Items                       |" << std::endl;
	std::cout << "|  [2] Eatables                    |" << std::endl;
	std::cout << "|  [0] Back                        |" << std::endl;
	std::cout << "´----------------------------------´" << std::endl;
	std::cout << "  -> ";
	std::cin >> buyOption;

	while (looping)
	{
		switch (buyOption)
		{
			case 1:
			{
				buyItem(pony);
				looping = false;
				break;
			}
			case 2:
			{
				buyEatable(pony);
				looping = false;
				break;
			}
			case 0:
			{
				looping = false; 
				break;
			}
		}
	}
	return;
}

void Store::buyItem(Pony *pony)
{
	int tempId;

	std::cout << "Which item do you want to buy? " << std::endl << "  -> ";
	std::cin >> tempId;

	Item *item = getItem(tempId);
	if (item->getId() == -1)
	{
		std::cout << "Invalid item id" << std::endl;
		delete item;
		return;
	}

	double ponyPoints = pony->getPoints();

	if (ponyPoints - item->getPrice() < 0)
	{
		std::cout << "Not enough points to buy item " << item->getName() << std::endl;
		delete item;
		return;
	}
	
	pony->buyItem(item);
	return;
}

void Store::buyEatable(Pony *pony)
{
	int tempId;

	std::cout << "Which eatable do you want to buy? " << std::endl << "  -> ";
	std::cin >> tempId;

	Eatable *eatable = getEatable(tempId);
	if (eatable->getId() == -1)
	{
		std::cout << "Invalid eatable id" << std::endl;
		delete eatable;
		return;
	}

	double ponyPoints = pony->getPoints();

	if (ponyPoints - eatable->getPrice() < 0)
	{
		std::cout << "Not enough points to buy eatable " << eatable->getName() << std::endl;
		delete eatable;
		return;
	}

	pony->buyEatable(eatable);
	return;
}

void Store::sellMenu(Pony * pony)
{
	int sellOption;
	bool looping = true;

	std::cout << "´----------------------------------´" << std::endl;
	std::cout << "|           Sell items             |" << std::endl;
	std::cout << "´----------------------------------´" << std::endl;
	std::cout << "|  [1] Items                       |" << std::endl;
	std::cout << "|  [2] Eatables                    |" << std::endl;
	std::cout << "|  [0] Back                        |" << std::endl;
	std::cout << "´----------------------------------´" << std::endl;
	std::cout << "  -> ";
	std::cin >> sellOption;

	while (looping)
	{
		switch (sellOption)
		{
		case 1:
		{
			sellItem(pony);
			looping = false;
			break;
		}
		case 2:
		{
			sellEatable(pony);
			looping = false;
			break;
		}
		case 0:
		{
			looping = false;
			break;
		}
		}
	}
	return;
}

void Store::sellItem(Pony * pony)
{
	int tempId;

	std::cout << "Which item do you want to sell? " << std::endl;

	if (pony->getItems().size() == 0)
	{
		std::cout << "You have no items to sell, baka!" << std::endl;
		return;
	}

	pony->printItemsOneLine();
	std::cout << "  -> ";
	std::cin >> tempId;

	pony->sellItem(tempId, 0.5);

	return;
}

void Store::sellEatable(Pony * pony)
{
	int tempId;

	std::cout << "Which eatable do you want to sell? " << std::endl;

	if (pony->getEatables().size() == 0 )
	{ 
		std::cout << "You have no eatables to sell, baka!" << std::endl;
		return;
	}

	pony->printEatablesOneLine();
	std::cout << "  -> ";
	std::cin >> tempId;

	pony->sellEatable(tempId, 0.5);

	return;
}

void Store::eatMenu(Pony * pony)
{
	int tempId;

	std::cout << "Which eatable do you want to feed? " << std::endl;

	if (pony->getEatables().size() == 0)
	{
		std::cout << "You have no eatables to feed, baka!" << std::endl;
		return;
	}
	pony->printEatablesOneLine();
	std::cout << "  -> ";
	std::cin >> tempId;

	Eatable *eatable = getEatable(tempId);

	if (eatable->getId() == -1)
	{
		std::cout << "Invalid eatable id" << std::endl;
		delete eatable;
		return;
	}

	pony->eatEatable(eatable->getId());

	delete eatable;
	return;
}

Item* Store::getItem(int itemId)
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		if (itemId == items.at(i)->getId())
		{
			return new Item(*items.at(i));
		}
	}
	std::cout << "No item with id " << itemId << " found" << std::endl;
	return new Item("Error", "Error", -1, 0);
}

Eatable* Store::getEatable(int eatableId)
{
	for (unsigned i = 0; i < eatables.size(); i++)
	{
		if (eatableId == eatables.at(i)->getId())
		{
			return new Eatable(*eatables.at(i));
		}
	}
	std::cout << "No eatables with id " << eatableId << " found" << std::endl;
	return new Eatable("Error", "Error", -1, 0, 0);
}