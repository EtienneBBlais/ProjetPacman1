/********
* Fichier: Niveau.h
* Auteur(s) : Etienne Bellerive-Blais
* Date : Fevrier 2023 (creation)
* Description:
********/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <dos.h> 
#include <windows.h>
#include <conio.h>
#include "coordonnee.h"
#include <ctime>
#include "Fantome.h"
#include "coordonnee.h"
#include "Clavier.h"
#include "Protagoniste.h"

using namespace std;

class Niveau
{
protected:
	Protagoniste** protagonistes;
	Fantome** fantomes;
	string filename;
    
    int nbLignes = 10;
    int nbColonnes = 20;
    int nbProt;
    int nbfan;
    

    COORD cursorPosition;

public:
    char** matrice;
	Niveau();
	Niveau(int nbProt_, int nbfan_, Protagoniste** protagonistes_, Fantome** fantomes_, string filename_);
    void lireMatrice(char** m);
    void AfficherMatrice(char** m);
    void Update();
    bool mort = false;
};

Niveau::Niveau(int nbProt_, int nbfan_, Protagoniste** protagonistes_, Fantome** fantomes_, string filename_)
{
    protagonistes = protagonistes_;
    fantomes = fantomes_;
    filename = filename_;

    // Creation de la matrice
    matrice = new char* [nbColonnes];
    for (int i = 0; i < nbColonnes; i++)
        matrice[i] = new char[nbLignes];
    lireMatrice(matrice);
    AfficherMatrice(matrice);
    nbProt = nbProt_;
    nbfan = nbfan_;

    //cache le curseur
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
   
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    system("cls");

}


void Niveau::lireMatrice(char** m)
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

void Niveau::AfficherMatrice(char** m)
{
    
   
    for (int i = 0; i < nbLignes; i++)
    {
        for (int j = 0; j < nbColonnes; j++)
            cout << m[j][i];
        cout << endl;
    }
    if (mort == true)
    {
        cout << endl << "you dead" << endl;
    }
    
}

void Niveau::Update()
{
   

    for (int i = 0; i < nbfan; i++)
        fantomes[i]->BougerPersonnage(matrice);

    for (int i = 0; i < nbProt; i++)
    {
        protagonistes[i]->BougerPersonnage(matrice);
        for (int j = 0; j < nbfan; j++)
            if (protagonistes[i]->getPosition().x == fantomes[j]->getPosition().x && protagonistes[i]->getPosition().y == fantomes[j]->getPosition().y)
            {
                mort = true;
                break;
            }

    }
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    AfficherMatrice(matrice);
    
    



}
