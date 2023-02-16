#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<dos.h>   //for delay()
#include <windows.h>
#include <conio.h>
#include "coordonnee.h"

using namespace std;

enum SensEtat { gauche, droite, haut, bas, nul };

class Fantome
{
private:
	SensEtat sensPossible[4];
	SensEtat sensChoisi;
	Coordonnee position;
public:
	Fantome(int x, int y);
	void determinerSensPossible(char** matrice);
	void determinerSensChoisi();
	SensEtat getSens();

};

Fantome::Fantome(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Fantome::determinerSensPossible(char** matrice)
{
	if (matrice[position.x][position.y + 1] != '#')
		sensPossible[0] = haut;
	else
		sensPossible[0] = nul;

	if (matrice[position.x][position.y - 1] != '#')
		sensPossible[1] = bas;
	else
		sensPossible[1] = nul;

	if (matrice[position.x+1][position.y] != '#')
		sensPossible[2] = droite;
	else
		sensPossible[2] = nul;

	if (matrice[position.x - 1][position.y] != '#')
		sensPossible[3] = gauche;
	else
		sensPossible[3] = nul;
}
