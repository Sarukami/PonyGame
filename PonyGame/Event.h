#pragma once
#include <string>


class Event
{
public:
	Event(std::string n, int i);
	Event(const Event& e);
	~Event(void);
	void print();
	void oneLinePrint();

	void setName(std::string newName);
	std::string getName();

	void setId(int newId);
	int getId();

protected:
	std::string name;
	int id;
};

