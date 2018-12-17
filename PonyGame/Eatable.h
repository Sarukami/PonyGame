#pragma once
#include "Item.h"

class Eatable :
	public Item
{
public:
	Eatable(std::string n, std::string d, int i, double p, double hp);
	Eatable(const Eatable &e);
	~Eatable(void);

	void print();
	void oneLinePrint();

	void setHp(double newHp);
	double getHp();

protected:
	double healthPoints;
};