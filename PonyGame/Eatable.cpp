#include "Eatable.h"



Eatable::Eatable(std::string n, std::string d, int i, double p, double hp)
	: Item (n, d, i, p)
{
	healthPoints = hp;
}

Eatable::Eatable(const Eatable & e) : Item(e)
{
	healthPoints = e.healthPoints;
}


Eatable::~Eatable(void)
{
}

void Eatable::print()
{
	Item::print();
	std::cout << "HP: " << healthPoints << std::endl;
}

void Eatable::oneLinePrint()
{
	std::cout << "Name: " << name;
	std::cout << ", Details: " << details;
	std::cout << ", Id: " << id;
	std::cout << ", Price: " << price;
	std::cout << ", HP: " << healthPoints;
	std::cout << std::endl;
}

void Eatable::setHp(double newHp)
{
	healthPoints = newHp;
}

double Eatable::getHp()
{
	return healthPoints;
}