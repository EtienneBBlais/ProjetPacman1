/********
* Fichier: Protagoniste.h
* Auteur(s) : Etienne Bellerive-Blais
* Date : Fevrier 2023 (creation)
* Description: 
********/
#pragma once
#include "Personnage.h"
#include "Manette.h"

class Protagoniste : public Personnage
{
private:
	Manette *clavier = new Manette();
public:
	virtual void determinerSensChoisi();
	Protagoniste(int x, int y, char** matrice, char symb);
	bool IsDead();
};

Protagoniste::Protagoniste(int x, int y, char** matrice, char symb) : Personnage(x, y, matrice, symb)
{
	Personnage(x, y, matrice, symb);
}

void Protagoniste::determinerSensChoisi()
{
	SensEtat sensTemp = clavier->DeterminerSensClavier();
	
	if (sensPossible[sensTemp] == nul)
		sensTemp = nul;

	sensChoisi = sensTemp;
}

