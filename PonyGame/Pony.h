#pragma once
#include <string>
#include <vector>
#include "GameObject.h"
#include "Item.h"
#include "Eatable.h"


class Pony : public GameObject
{
public:
	Pony();
	Pony(std::string n, std::string d, std::string b, double h, double p, int i);
	~Pony(void);

	void print();
	void printItems();
	void printItemsOneLine();
	void printEatablesOneLine();
	void updateInfo();

	void setHealth(double newHealth);
	double getHealth();

	void setPoints(double newPoints);
	double getPoints();

	void setBreed(std::string newBreed);
	std::string getBreed();

	std::vector<Item*>getItems();
	void giveItem(Item *item);

	void buyItem(Item *item);
	void sellItem(int itemId, double conversion);

	std::vector<Eatable*>getEatables();
	void giveEatable(Eatable *eatable);

	void eatEatable(int eatableId);

	void buyEatable(Eatable *eatable);
	void sellEatable(int eatableId, double conversion);

protected:
	double health;
	double points;
	std::string breed;
	std::vector<Item*> items;
	std::vector<Eatable*> eatables;
};