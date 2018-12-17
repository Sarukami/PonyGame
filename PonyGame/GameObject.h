#pragma once
#include <string>
#include <iostream>


class GameObject
{
public:
	GameObject();
	GameObject(std::string n, std::string d, int i);
	GameObject(const GameObject &g);
	virtual ~GameObject(void);

	virtual void print()=0;
	void oneLinePrint();

	void setName(std::string newName);
	std::string getName();

	void setDetails(std::string newDetails);
	std::string getDetails();

	void setId(int newId);
	int getId();

protected:
	std::string name;
	std::string details;
	int id;
};

