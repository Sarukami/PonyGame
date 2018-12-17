#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>

// Korjaa tarvittaessa oman luokkasi nimi t�h�n:
#include "Pony.h"

/*****************************************************************************************************
FileHandler on apuluokka, joka hoitaa tiedostosta lukemisen ja tiedostoon kirjoittamisen.
Kaikki tieto kirjoitetaan tekstimuotoisena, 1 tieto/rivi.
Luo luokasta olio ja anna parametrina kummankin tiedoston nimi. Tiedostot luodaan automaattisesti,
jos niit� ei viel� ole olemassa.

Luokka lukee ja kirjoittaa kahta tiedostoa. Toinen tiedosto on ponin tietoja varten.
Ponin saamat palkinnot ja ponin omistamat tavarat tallennetaan tiedostoon pelkill� id-numeroilla.
Voit hakea tavaroiden id-numerot erillisell� metodilla (getItemIDs())
Metodi ylikirjoittaa olemassa olevan tiedoston tai luo uuden tiedoston, jos sit� ei viel� ole olemassa.

Ponin saamat palkinnot kirjoitetaan erilliseen tiedostoon. Metodi kirjoittaa uusien palkintojen
tiedot olemassa olevan tiedoston loppuun tai luo uuden tiedoston, jos tiedostoa ei viel� ole olemassa.
*/
class FileHandler
{
public:
	// Konstruktori
	// Parametreina kahden tiedoston nimet. Tiedostot luodaan, jos niit� ei viel�
	// ole olemassa
	FileHandler();
	FileHandler(std::string prizesFilename, std::string filename_prizes );

	// Metodit tietojen tallentamiseen:
	void savePony( Pony *pony );
	void savePrize( Item *prize );
	
	// Metodit tiedostojen lukemiseen:
	Pony* loadPony();
	std::vector<Item*> loadPrizes();

	// Metodi, joka palauttaa ponin tavaroiden id-numerot:
	std::vector<int> getItemIDs(){ return itemIDs; }

	// Metodi, joka poistaa palkinnon tiedot tiedostosta:
	void removePrize( int prizeId );

private:
	// Ponin tiedot ja tavaroiden id:t kirjoitetaan omaan tiedostoon
	// Saatujen palkintojen tiedot kirjoitetaan toiseen tiedostoon
	std::string prizesFilename;
	std::string gameObjectFilename;
	
	// Ponin tavaroiden id:t luetaan tiedostosta
	// t�h�n vektoriin
	std::vector<int> itemIDs;

};


#endif
