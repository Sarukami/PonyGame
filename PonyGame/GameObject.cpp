#include <iostream>
#include <string>
#include "GameObject.h"


GameObject::GameObject()
{
	name = "Default";
	details = "Default";
	id = 10;
}

GameObject::GameObject(std::string n, std::string d, int i)
{
	name = n;
	details = d;
	id = i;
}

GameObject::GameObject(const GameObject &g)
{
	name = g.name;
	details = g.details;
	id = g.id;
}

GameObject::~GameObject(void)
{
}

void GameObject::print()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Details: " << details << std::endl;
	std::cout << "Id: " << id << std::endl;
}

void GameObject::oneLinePrint()
{
	std::cout << "Name: " << name;
	std::cout << ", Details: " << details;
	std::cout << ", Id: " << id;
}

void GameObject::setName(std::string newName)
{
	name = newName;
}

std::string GameObject::getName()
{
	return name;
}

void GameObject::setDetails(std::string newDetails)
{
	details = newDetails;
}

std::string GameObject::getDetails()
{
	return details;
}

void GameObject::setId(int newId)
{
	id = newId;
}

int GameObject::getId()
{
	return id;
}