#pragma once
#include "Personnage.h"




class Fantome : public Personnage
{
public:
	virtual void determinerSensChoisi();
	Fantome(int x, int y, char** matrice);
};

Fantome::Fantome(int x, int y, char** matrice) : Personnage(x, y, matrice)
{
	Personnage(x, y, matrice);
}



void Fantome::determinerSensChoisi()
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

