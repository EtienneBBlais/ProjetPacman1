/********
* Fichier: Fantome.h
* Auteur(s) : Etienne Bellerive-Blais
* Date : Fevrier 2023 (creation)
* Description:
********/
#pragma once
#include "Personnage.h"

class Fantome : public Personnage
{
public:
	virtual void determinerSensChoisi();
	Fantome(int x, int y, char symb);
};

Fantome::Fantome(int x, int y, char symb) : Personnage(x, y, symb)
{
	Personnage(x, y, symb);
	sensChoisi = nul;
}

void Fantome::determinerSensChoisi()
{
	if (sensPossible[sensChoisi] != nul)
		return;
	
	srand(time(0));
	int rand_int = rand() % 4;
	while (sensPossible[rand_int] == nul)
		rand_int = rand() % 4;

	sensChoisi = sensPossible[rand_int];			
}

