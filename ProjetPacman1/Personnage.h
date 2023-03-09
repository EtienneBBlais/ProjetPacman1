/********
* Fichier: Personnage.h
* Auteur(s) : Etienne Bellerive-Blais
* Date : Fevrier 2023 (creation)
* Description:
********/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <dos.h> 
#include <windows.h>
#include <conio.h>
#include "coordonnee.h"
#include <ctime>

using namespace std;

enum SensEtat { haut, bas, droite, gauche, nul };

class Personnage
{
protected:
	SensEtat sensPossible[4];
	SensEtat sensChoisi;
	Coordonnee position;
	char symbole;
	double tprecedent = 0;
	
public:
	Personnage(int x, int y, char symb);

	void determinerSensPossible(char** matrice);
	virtual void determinerSensChoisi();
	SensEtat getSens();
	void BougerPersonnage(char** matrice);
	Coordonnee getPosition();
	double getTempsMs();
	int vitesse = 150;
};

Personnage::Personnage(int x, int y, char symb)
{
	position.x = x;
	position.y = y;
	sensChoisi = nul;
	
	symbole = symb;
}

void Personnage::determinerSensPossible(char** matrice)
{
	if (matrice[position.x][position.y - 1] != '#')
		sensPossible[0] = haut;
	else
		sensPossible[0] = nul;

	if (matrice[position.x][position.y + 1] != '#')
		sensPossible[1] = bas;
	else
		sensPossible[1] = nul;

	if (matrice[position.x + 1][position.y] != '#')
		sensPossible[2] = droite;
	else
		sensPossible[2] = nul;

	if (matrice[position.x - 1][position.y] != '#')
		sensPossible[3] = gauche;
	else
		sensPossible[3] = nul;
}

SensEtat Personnage::getSens()
{
	return sensChoisi;
}

void Personnage::determinerSensChoisi(){}

void Personnage::BougerPersonnage(char** matrice)
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

		matrice[position.x][position.y] = symbole;
		tprecedent += vitesse;
	}
}



double Personnage::getTempsMs()
{
	static clock_t start_time = clock();
	clock_t current_time = clock();
	double elapsed_ticks = (double)(current_time - start_time);
	double elapsed_milliseconds = (elapsed_ticks / CLOCKS_PER_SEC) * 1000.0;
	return elapsed_milliseconds;
}

Coordonnee Personnage::getPosition()
{
	return position;
}