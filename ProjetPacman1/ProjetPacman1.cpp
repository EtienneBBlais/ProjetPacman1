/********
* Fichier: ProjetPacman.cpp
* Auteur(s) : Etienne Bellerive-Blais
* Date : Fevrier 2023 (creation)
* Description: main
********/

#include <iostream>
#include <fstream>
#include <string>
#include<dos.h>   //for delay()
#include <windows.h>
#include <conio.h>
#include "Fantome.h"
#include "coordonnee.h"
#include "Clavier.h"
#include "Protagoniste.h"

using namespace std;
namespace Etape {

<<<<<<< HEAD
    enum ETAPES {
        demanderVitesse,
        game,
        finPartie
    };
=======
int nbLignes = 10;
int nbColonnes = 20;
char** matrice;
bool YouDead;

void lireMatrice(char** m)
{
    char sautDeLigne;
    string filename = "map.txt";
    ifstream file(filename);
    if (!file.is_open()) 
        std::cout << "Error opening file " << filename << std::endl;

    for (int i = 0; i < nbLignes; i++)
    {
        for (int j = 0; j < nbColonnes; j++)
            file.get(m[j][i]);
        file.get(sautDeLigne);
    }
    file.close();
}

void AfficherMatrice(char** m)
{
    for (int i = 0; i < nbLignes; i++)
    {
        for (int j = 0; j < nbColonnes; j++)
            cout << m[j][i];
        cout << endl;
    }
>>>>>>> parent of 73471dd (DeuxJoueur)
}

int main()
{
<<<<<<< HEAD
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

=======
    YouDead = false;
    //cache le curseur
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    SensEtat sens = gauche;
    char** matrice = new char* [nbColonnes];
    for (int i = 0; i < nbColonnes; i++) {
        matrice[i] = new char[nbLignes];
    }
    
    //initialisation et affichage initial de la matrice
    for (int i = 0; i < nbLignes; i++)
    {
        for (int j = 0; j < nbColonnes; j++)
        {
            matrice[j][i] = ' ';
            cout << matrice[j][i];
        }
        cout << endl;
    }
    lireMatrice(matrice);
    AfficherMatrice(matrice);
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    system("cls");
    Fantome *fantome = new Fantome(1, 1, matrice, 'F');
    Fantome* fantome2 = new Fantome(1, 1, matrice, 'F');

    Protagoniste* protagoniste = new Protagoniste(10, 1, matrice, 'P');
    int compteur = 0;
    while (YouDead == false)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
        if (fantome->getPosition().x == protagoniste->getPosition().x && fantome->getPosition().y == protagoniste->getPosition().y)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
            YouDead = true;
            AfficherMatrice(matrice);
            break;
        }
        AfficherMatrice(matrice);
        protagoniste->BougerPersonnage(matrice);
        if (fantome->getPosition().x == protagoniste->getPosition().x && fantome->getPosition().y == protagoniste->getPosition().y)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
            YouDead = true;
            AfficherMatrice(matrice);
            cout << endl << endl << "T'es mort. Meilleure chance la prochaine fois" << endl;
            break;
        }
        if (protagoniste->YouWin == true)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
            YouDead = true;
            AfficherMatrice(matrice);
            cout << endl << endl << "T'as gagne'. That's it Bro" << endl;
            break;
        }
        fantome->BougerPersonnage(matrice);
        cout << fantome->getTempsMs();
    }
      
>>>>>>> parent of 73471dd (DeuxJoueur)
}