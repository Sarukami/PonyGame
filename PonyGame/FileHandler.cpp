#include "FileHandler.h"
#include "Pony.h"

#include <fstream>
#include <iostream>
#include <time.h>


FileHandler::FileHandler()
{
}

// Konstruktorin toteutus
FileHandler::FileHandler( std::string filename_go, std::string filename_prizes )
{
	gameObjectFilename = filename_go;
	prizesFilename = filename_prizes;
}

// Metodi tallentaa yksittäisen uuden palkinnon tiedot
// tiedoston loppuun. Tiedosto avataan append-muodossa,
// olemassa olevia palkintoja ei ylikirjoiteta
void FileHandler::savePrize( Item* prize )
{
	std::ofstream myFile(prizesFilename, std::ios::app );

	if (myFile)
	{
		myFile << prize->getName() << std::endl;
		myFile << prize->getDetails() << std::endl;
		myFile << prize->getPrice() << std::endl;
		myFile << prize->getId() << std::endl;

		myFile.close();
	}
}

// Metodi poistaa annetun id:n perusteella ko. palkinnon
// tiedostosta
void FileHandler::removePrize(int prizeId)
{
	// Luetaan palkinnot tiedostosta:
	std::vector<Item*> prizes = loadPrizes();

	std::vector<Item*>::iterator it = prizes.begin();
	bool removed = false;

	// Poistetaan annettu palkinto vektorista:
	while (it != prizes.end())
	{
		if( prizeId == (*it)->getId() )
		{
			it = prizes.erase(it);
			removed = true;
			break;
		}
		else
		{
			it++;
		}
	}

	// Ylikirjoitetaan tiedosto, jos ko. numerolla löytyi palkinto:
	if( removed )
		{
		std::ofstream myFile(prizesFilename);

		if (myFile)
		{
			for (unsigned i = 0; i < prizes.size(); i++)
			{
				myFile << prizes[i]->getName() << std::endl;
				myFile << prizes[i]->getDetails() << std::endl;
				myFile << prizes[i]->getPrice() << std::endl;
				myFile << prizes[i]->getId() << std::endl;
			}

			myFile.close();
		}
	}
}

// Metodi lukee palkintojen tiedot tiedostosta ja palauttaa
// ne vektorissa
std::vector<Item*> FileHandler::loadPrizes()
{
	std::vector<Item*> prizes;

	// Väliaikaiset muuttujat, joita tarvitaan tiedon lukemisessa
	std::string name, details;
	int id;
	double price;

	// Avataan tiedosto
	std::ifstream myFile( prizesFilename );

	if (myFile)
	{
		while( myFile.peek() != EOF )
		{
			// Luetaan attribuuttien arvot...
			getline( myFile, name, '\n');
			getline( myFile, details, '\n');
			myFile >> price;
			myFile >> id;

			// .. luodaan Item-olio
			Item *prize = new Item( name, details, price, id );		
			prizes.push_back(prize);

			// Hävitetään rivinvaihto puskurista
			myFile.ignore();
			
		}

		myFile.close();
	}	

	return prizes;
}


// Metodi kirjoittaa ponin tiedot tiedostoon.
// Ponin tavaroista kirjoitetaan pelkkä id.
// Metodi ylikirjoittaa olemassa olevan tiedoston, jos sellainen on.
void FileHandler::savePony(Pony *pony)
{
	std::ofstream myFile( gameObjectFilename );

	if (myFile)
	{
		// Kirjoitetaan ponin perustiedot tiedostoon
		myFile << pony->getName() << std::endl;
		myFile << pony->getDetails() << std::endl;
		myFile << pony->getBreed() << std::endl;
		myFile << pony->getId() << std::endl;
		myFile << pony->getHealth() << std::endl;
		myFile << pony->getPoints() << std::endl;

		// Haetaan ponin tavarat
		std::vector<Item*> items = pony->getItems();

		// Kirjoitetaan tavaroiden id-numerot tiedostoon
		for (unsigned i = 0; i < items.size(); i++ )
		{
			myFile << items[i]->getId() << std::endl;
		}

		myFile.close();
	}
}

// Metodi lataa ponin perustiedot tiedostosta.
// Tavaroiden id-numerot pitää kysyä erillisellä metodilla.
Pony* FileHandler::loadPony()
{
	Pony *pony = new Pony;

	// Väliaikaiset muuttujat, joita tarvitaan tiedon lukemisessa
	std::string name, details, breed;
	int id;
	double health, points;

	// Avataan tiedosto
	std::ifstream myFile( gameObjectFilename );

	if( myFile )
	{
		// Luetaan attribuuttien arvot...
		getline( myFile, name, '\n' );
		getline( myFile, details, '\n' );
		getline( myFile, breed, '\n' );
		myFile >> id;
		myFile >> health;
		myFile >> points;

		// Luetaan tavaroiden id-numerot:
		int tmp;

		while( myFile >> tmp )
		{
			// tallennetaan numero vektoriin
			itemIDs.push_back(tmp);
		}

		// .. luodaan Pony-olio
		pony = new Pony( name, details, breed, health, points, id );

		myFile.close();
	}

	return pony;
}