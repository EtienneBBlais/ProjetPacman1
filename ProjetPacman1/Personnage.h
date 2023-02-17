#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<dos.h>   //for delay()
#include <windows.h>
#include <conio.h>
#include "coordonnee.h"
#include <ctime>

using namespace std;

enum SensEtat { haut, bas, droite, gauche, nul };

double tprecedent;


class Personnage
{
protected:
	SensEtat sensPossible[4];
	SensEtat sensChoisi;
	Coordonnee position;
public:
	Personnage(int x, int y, char** matrice);

	void determinerSensPossible(char** matrice);
	virtual void determinerSensChoisi();
	SensEtat getSens();
	void BougerPersonnage(char** matrice);
	double getTempsSecondes();
	double getTempsMs();
};

Personnage::Personnage(int x, int y, char** matrice)
{
	position.x = x;
	position.y = y;
	sensChoisi = nul;
	matrice[position.x][position.y] = 'F';
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

void Personnage::determinerSensChoisi()
{
	if (sensPossible[sensChoisi] != nul)
		return;


	srand(time(0));
	int rand_int = rand() % 4;
	while (sensPossible[rand_int] == nul)
	{
		rand_int = rand() % 4;
	}
	sensChoisi = sensPossible[rand_int];



}

void Personnage::BougerPersonnage(char** matrice)
{
	if (tprecedent + 100 < getTempsMs())
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

		matrice[position.x][position.y] = 'F';
		tprecedent += 100;
	}
}

double Personnage::getTempsSecondes()
{
	static time_t start_time = time(NULL);
	time_t current_time = time(NULL);
	double elapsed_seconds = difftime(current_time, start_time);
	return elapsed_seconds;
}

double Personnage::getTempsMs()
{
	static clock_t start_time = clock();
	clock_t current_time = clock();
	double elapsed_ticks = (double)(current_time - start_time);
	double elapsed_milliseconds = (elapsed_ticks / CLOCKS_PER_SEC) * 1000.0;
	return elapsed_milliseconds;
}
