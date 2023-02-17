#pragma once
#pragma once
#include "Personnage.h"




class Protagoniste : public Personnage
{
public:
	virtual void determinerSensChoisi();
	Protagoniste(int x, int y, char** matrice);
};

Protagoniste::Protagoniste(int x, int y, char** matrice) : Personnage(x, y, matrice)
{
	Personnage(x, y, matrice);
}



void Protagoniste::determinerSensChoisi()
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

