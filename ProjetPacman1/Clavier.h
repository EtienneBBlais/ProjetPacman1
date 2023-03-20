/********
* Fichier: Clavier.h
* Auteur(s) : Etienne Bellerive-Blais
* Date : Fevrier 2023 (creation)
* Description:
********/
#pragma once
#include <chrono>
#include <thread>

class Clavier
{
public:
	Clavier();
	SensEtat DeterminerSensClavier(char symb);
private:
	SensEtat sens;
	
};

Clavier::Clavier()
{
	sens = nul;
}

SensEtat Clavier::DeterminerSensClavier(char symb)
{

	if (symb == 'P')
	{
		if (GetKeyState('W') & 0x8000)
			sens = haut;
		if (GetKeyState('S') & 0x8000)
			sens = bas;
		if (GetKeyState('D') & 0x8000)
			sens = droite;
		if (GetKeyState('A') & 0x8000)
			sens = gauche;
	}
	else if (symb == 'S')
	{
		if (GetKeyState('I') & 0x8000)
			sens = haut;
		if (GetKeyState('K') & 0x8000)
			sens = bas;
		if (GetKeyState('L') & 0x8000)
			sens = droite;
		if (GetKeyState('J') & 0x8000)
			sens = gauche;
	}
		
	return sens;	
}



