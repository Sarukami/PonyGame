#include <iostream>
#include "Event.h"



Event::Event(std::string n, int i)
{
	name = n;
	id = i;
}

Event::Event(const Event& e)
{
	name = e.name;
	id = e.id;
}


Event::~Event(void)
{
}

void Event::print()
{
	std::cout << "Event name: " << name << std::endl;
	std::cout << "Event id: " << id << std::endl;
	std::cout << std::endl;
}

void Event::oneLinePrint()
{
	std::cout << "Event name: " << name;
	std::cout << ", Event id: " << id << std::endl;
}

void Event::setName(std::string newName)
{
	name = newName;
}

std::string Event::getName()
{
	return name;
}

void Event::setId(int newId)
{
	id = newId;
}

int Event::getId()
{
	return id;
}