/********
* Fichier: Protagoniste.h
* Auteur(s) : Etienne Bellerive-Blais
* Date : Fevrier 2023 (creation)
* Description: 
********/
#pragma once
#include "Personnage.h"
#include "Clavier.h"

class Protagoniste : public Personnage
{
private:
	Clavier *clavier = new Clavier();
	char symbol;
public:
	virtual void determinerSensChoisi();
	Protagoniste(int x, int y, char symb);
	bool IsDead();
	void BougerPersonnage(char** matrice);
	bool YouWin = false;
};

Protagoniste::Protagoniste(int x, int y, char symb) : Personnage(x, y, symb)
{
	Personnage(x, y, symb);
	symbol = symb;
}

void Protagoniste::determinerSensChoisi()
{
	SensEtat sensTemp = clavier->DeterminerSensClavier(symbol);
	
	if (sensPossible[sensTemp] == nul)
		sensTemp = nul;

	sensChoisi = sensTemp;
}

void Protagoniste::BougerPersonnage(char** matrice)
{
	if (tprecedent + vitesse < getTempsMs())
	{

		determinerSensPossible(matrice);
		determinerSensChoisi();
		matrice[position.x][position.y] = ' ';
		if (sensChoisi == gauche)
			position.x--;
		if (sensChoisi == droite)
			position.x++;
		if (sensChoisi == haut)
			position.y--;
		if (sensChoisi == bas)
			position.y++;

		if (matrice[position.x][position.y] == '>')
			YouWin = true;
		matrice[position.x][position.y] = symbole;
		tprecedent += vitesse;
	}
}

