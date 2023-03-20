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
        game,
        finPartie
    };
}

int main()
{
    Etape::ETAPES etape;
    etape = Etape::demanderVitesse;
    while (true)
    {
        Fantome** fantomes = new Fantome * [1];
        Protagoniste** protagonistes = new Protagoniste * [1];

        fantomes[0] = new Fantome(1, 1, 'F');

        protagonistes[0] = new Protagoniste(10, 1, 'P');
        

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
                fantomes[0]->vitesse = 100;
                etape = Etape::game;
                break;

            }
            if (inputClav == '2')
            {
                cout << "prout" << endl;
                fantomes[0]->vitesse = 150;
                etape = Etape::game;
                break;

            }
            if (inputClav == '3')
            {
                fantomes[0]->vitesse = 200;
                etape = Etape::game;
                break;

            }

        case Etape::game: {
            Niveau* niveau = new Niveau(2, 2, protagonistes, fantomes, "map.txt");
            while (!niveau->mort)
                niveau->Update();
            etape = Etape::finPartie; }
            break;
        //marche pas encore
        case Etape::finPartie:
            delete[]fantomes;
            fantomes[0] = NULL;
            delete[]protagonistes;
            protagonistes[0] = NULL;
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