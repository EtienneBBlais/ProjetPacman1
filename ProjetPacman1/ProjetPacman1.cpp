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

namespace Etape {

    enum ETAPES {
        demanderVitesse,
        gameFacile,
        gameMoyen,
        gameDifficile,
        finPartie
    };
}

int main()
{

    Etape::ETAPES etape;
    etape = Etape::demanderVitesse;
    
    while (true)
    {
        int inputClav;
        int inputClav2;

        switch (etape) {
        case Etape::demanderVitesse:
            cout << "Choisir la vitesse voulu pour commencer la partie" << endl;
            cout << "1: lent" << endl;
            cout << "2:moyen" << endl;
            cout << "3:rapide" << endl;
            inputClav = 0;
 
          
            //attend clavier appuye
            while (_kbhit()) {
                _getch();
            }
            while (!_kbhit()) {}
            inputClav = _getch();
            if (inputClav == '1')
            {
              
                etape = Etape::gameFacile;
                break;

            }
            if (inputClav == '2')
            {
              
                etape = Etape::gameMoyen;
                break;

            }
            if (inputClav == '3')
            {
                etape = Etape::gameDifficile;
                break;
            }
            else {
                etape = Etape::demanderVitesse;
                break;
            }

        case Etape::gameFacile:
        {
            Fantome** fantomes = new Fantome * [2];
            Protagoniste** protagonistes = new Protagoniste * [2];

            fantomes[0] = new Fantome(1, 1, 'F');
            fantomes[1] = new Fantome(1, 2, 'F');
            fantomes[0]->vitesse = 100;
            fantomes[1]->vitesse = 100;

            protagonistes[0] = new Protagoniste(10, 1, 'P');
            protagonistes[1] = new Protagoniste(12, 1, 'S');



            Niveau* niveau = new Niveau(2, 2, protagonistes, fantomes, "map.txt");

            while (!niveau->mort)
                niveau->Update();
               
            
        }  
            break;

        case Etape::gameMoyen:
        {
            Fantome** fantomes = new Fantome * [2];
            Protagoniste** protagonistes = new Protagoniste * [2];

            fantomes[0] = new Fantome(1, 1, 'F');
            fantomes[1] = new Fantome(1, 2, 'F');
            fantomes[0]->vitesse = 100;
            fantomes[1]->vitesse = 100;

            protagonistes[0] = new Protagoniste(10, 1, 'P');
            protagonistes[1] = new Protagoniste(12, 1, 'S');



            Niveau* niveau = new Niveau(2, 2, protagonistes, fantomes, "map.txt");

            while (!niveau->mort)
                niveau->Update();
            
            etape = Etape::finPartie;
        }
        break;

        case Etape::gameDifficile:
        {
            Fantome** fantomes = new Fantome * [2];
            Protagoniste** protagonistes = new Protagoniste * [2];

            fantomes[0] = new Fantome(1, 1, 'F');
            fantomes[1] = new Fantome(1, 2, 'F');
            fantomes[0]->vitesse = 100;
            fantomes[1]->vitesse = 100;

            protagonistes[0] = new Protagoniste(10, 1, 'P');
            protagonistes[1] = new Protagoniste(12, 1, 'S');



            Niveau* niveau = new Niveau(2, 2, protagonistes, fantomes, "map.txt");

            while (!niveau->mort)
                niveau->Update();
           
            etape = Etape::finPartie;
           
        }
        break;

        case Etape::finPartie:
            inputClav2 = 0;
            //attend clavier appuye
            while (_kbhit()) {
                _getch();
            }
            while (!_kbhit()) {}
            inputClav2 = _getch();
            cout << inputClav2 << endl;
            if (inputClav2 == '8')
            {
                etape = Etape::demanderVitesse;
                break;
            }
        }
    }
}