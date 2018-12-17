#include <vector>
#include "Pony.h"
#include "GameObject.h"
#include "PonyGame.h"



Pony::Pony()
{
	name = "Silver";
	details = "The best pony";
	breed = "Pony";
	health = 100;
	points = 50;
	id = 1;

	items = std::vector<Item*>();
	eatables = std::vector<Eatable*>();
}

Pony::Pony(std::string n, std::string d, std::string b, double h, double p, int i) : GameObject(n, d, i)
{
	health = h;
	points = p;
	breed = b;

	items = std::vector<Item*>();
	eatables = std::vector<Eatable*>();
}

Pony::~Pony(void)
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		delete items.at(i);
	}

	for (unsigned i = 0; i < eatables.size(); i++)
	{
		delete eatables.at(i);
	}
}

void Pony::print()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Details: " << details << std::endl;
	std::cout << "Breed: " << breed << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Points: " << points << std::endl;
	std::cout << "Id: " << id << std::endl;
	std::cout << std::endl << "You have these items: " << std::endl;
	printItemsOneLine();
	std::cout << std::endl << "You have these eatables: " << std::endl;
	printEatablesOneLine();
}

void Pony::printItems()
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		items[i]->print();
		std::cout << std::endl;
	}
}

void Pony::printItemsOneLine()
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		items[i]->oneLinePrint();
	}
}

void Pony::printEatablesOneLine()
{
	for (unsigned i = 0; i < eatables.size(); i++)
	{
		eatables[i]->oneLinePrint();
	}
}

void Pony::updateInfo()
{
	std::cout << "Name: ";
	std::cin >> name;

	std::cout << "Breed: ";
	std::cin >> breed;

	std::cout << "Health: ";
	std::cin >> health;

	std::cout << "Points: ";
	std::cin >> points;
}

void Pony::setHealth(double newHealth)
{
	health = newHealth;
}

double Pony::getHealth()
{
	return health;
}

void Pony::setPoints(double newPoints)
{
	points = newPoints;
}

double Pony::getPoints()
{
	return points;
}

void Pony::setBreed(std::string newBreed)
{
	breed = newBreed;
}

std::string Pony::getBreed()
{
	return breed;
}

std::vector<Item*> Pony::getItems()
{
	return items;
}

void Pony::giveItem(Item *item)
{
	items.push_back(item);
	std::cout << name << " received " << item->getName() << std::endl;
}

void Pony::buyItem(Item *item)
{
	points -= item->getPrice();
	items.push_back(item);
	std::cout << name << " bought " << item->getName() << " for " << item->getPrice() << std::endl;
	std::cout << "You still have " << getPoints() << " points" << std::endl;
}

void Pony::sellItem(int itemId, double conversion)
{
	bool found = false;

	for (unsigned i = 0; i < items.size(); i++)
	{
		if (itemId == items.at(i)->getId() && !found)
		{

			points += items.at(i)->getPrice() * conversion;
			items.erase(items.begin() + i);
			found = true;
		}
	}
	if (!found)
	{
		std::cout << "Invalid item ID" << std::endl;
		return;
	}
}

std::vector<Eatable*> Pony::getEatables()
{
	return eatables;
}

void Pony::giveEatable(Eatable * eatable)
{
	eatables.push_back(eatable);
	std::cout << name << " received " << eatable->getName() << std::endl;
}

void Pony::eatEatable(int eatableId)
{
	bool found = false;

	for (unsigned i = 0; i < eatables.size(); i++)
	{
		if (eatableId == eatables.at(i)->getId() && !found)
		{
			health += eatables.at(i)->getHp();

			std::cout << name << " feels refreshed by eating " << eatables.at(i)->getName() << std::endl;
			std::cout << name << " now has " << health << " hp" << std::endl;
			eatables.erase(eatables.begin() + i);
			found = true;
		}
	}
	if (!found)
	{
		std::cout << "Invalid eatable ID" << std::endl;
		return;
	}
}

void Pony::buyEatable(Eatable * eatable)
{
	points -= eatable->getPrice();
	eatables.push_back(eatable);
	std::cout << name << " bought " << eatable->getName() << " for " << eatable->getPrice() << std::endl;
	std::cout << "You still have " << getPoints() << " points" << std::endl;
}

void Pony::sellEatable(int eatableId, double conversion)
{
	bool found = false;

	for (unsigned i = 0; i < eatables.size(); i++)
	{
		if (eatableId == eatables.at(i)->getId() && !found)
		{
			points += eatables.at(i)->getPrice() * conversion;
			eatables.erase(eatables.begin() + i);
			found = true;
		}
	}
	if (!found)
	{
		std::cout << "Invalid eatable ID" << std::endl;
		return;
	}
}

