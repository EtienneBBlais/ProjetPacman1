/********
* Fichier: Manette.h
* Auteur(s) : Etienne Bellerive-Blais
* Date : Fevrier 2023 (creation)
* Description:
********/
#pragma once
#include <chrono>
#include <thread>

class Manette
{
public:
	Manette();
	SensEtat DeterminerSensClavier();
private:
	SensEtat sens;
	
};

Manette::Manette()
{
	sens = nul;
}

SensEtat Manette::DeterminerSensClavier()
{
	if (GetKeyState('W') & 0x8000)
		sens = haut;
	if (GetKeyState('S') & 0x8000)
		sens = bas;
	if (GetKeyState('D') & 0x8000)
		sens = droite;
	if (GetKeyState('A') & 0x8000)
		sens = gauche;
		
	return sens;
	
}



