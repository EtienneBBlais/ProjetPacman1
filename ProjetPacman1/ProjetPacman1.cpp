/********
* Fichier: ProjetPacman.cpp
* Auteur(s) : Etienne Bellerive-Blais
* Date : Fevrier 2023 (creation)
* Description: main
********/

#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>   //for delay()
#include <windows.h>
#include <conio.h>
#include "Fantome.h"
#include "coordonnee.h"
#include "Clavier.h"
#include "Protagoniste.h"
#include "Niveau.h"

using namespace std;


int main()
{
    

    Fantome** fantomes = new Fantome*[2];
    Protagoniste** protagonistes = new Protagoniste*[2];

    fantomes[0] = new Fantome(1, 1, 'F');
    fantomes[1] = new Fantome(1, 2, 'F');

    protagonistes[0] = new Protagoniste(10, 1, 'P');
    protagonistes[1] = new Protagoniste(12, 1, 'S');



    Niveau* niveau = new Niveau(2,2,protagonistes, fantomes, "map.txt");

    while(!niveau->mort)
        niveau->Update();
}