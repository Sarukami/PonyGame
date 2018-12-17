#pragma once
#include <string>
#include "EventManager.h"
#include "Pony.h"
#include "Store.h"
#include "FileHandler.h"

class PonyGame
{
public:
	PonyGame();
	~PonyGame(void);

	void mainMenu();
	void menu();
protected:
	Store *store;
	Pony *pony;
	FileHandler *filehandler;
	EventManager *eventManager;
};