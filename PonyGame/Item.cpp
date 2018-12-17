#include "Item.h"
#include "GameObject.h"



Item::Item(std::string n, std::string d, int i, double p)
	: GameObject (n, d, i)
{
	price = p;
}

Item::Item(const Item & i) : GameObject(i)
{
	price = i.price;
}


Item::~Item(void)
{
}

void Item::print()
{
	GameObject::print();
	std::cout << "Price: " << price << std::endl;
}

void Item::oneLinePrint()
{
	std::cout << "Name: " << name;
	std::cout << ", Details: " << details;
	std::cout << ", Id: " << id;
	std::cout << ", Price: " << price;
	std::cout << std::endl;
}

void Item::setPrice(double newPrice)
{
	price = newPrice;
}

double Item::getPrice()
{
	return price;
}