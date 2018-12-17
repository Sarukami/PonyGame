#pragma once
#include <vector>
#include <string>
#include "Eatable.h"
#include "Item.h"
#include "Pony.h"


class Store
{
public:
	Store();
	~Store();

	void printItems();
	void printEatables();

	void buyMenu(Pony *pony);
	void buyItem(Pony *pony);
	void buyEatable(Pony *pony);

	void sellMenu(Pony *pony);
	void sellItem(Pony *pony);
	void sellEatable(Pony *pony);

	void eatMenu(Pony *pony);

	Item* getItem(int itemId);
	Eatable* getEatable(int eatableId);
protected:
	std::vector<Item*> items;
	std::vector<Eatable*> eatables;
};

