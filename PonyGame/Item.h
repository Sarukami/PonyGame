#pragma once
#include "GameObject.h"

class Item : public GameObject
{
public:
	Item(std::string n, std::string d, int i, double p);
	Item(const Item &i);
	virtual ~Item(void);

	void print();
	void oneLinePrint();

	void setPrice(double newPrice);
	double getPrice();
protected:
	double price;
};

