#pragma once
#include <string>
#include <vector>
#include "Event.h"
#include "Pony.h"

class EventManager
{
public:
	EventManager();
	~EventManager(void);
	void printAllEvents();
	void enterCompetition(Pony *pony, int eventId);

protected:
	std::vector<Event*> events;
	Item *cup;
	Item *rose;
};

