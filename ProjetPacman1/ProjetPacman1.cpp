// ProjetPacman1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>
#include<dos.h>   //for delay()
#include <windows.h>
#include <conio.h>
#include "Fantome.h"
#include "coordonnee.h"

using namespace std;

int nbLignes = 8;
int nbColonnes = 10;
char** matrice;



void lireMatrice(char** m)
{
    char sautDeLigne;
    string filename = "map.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file " << filename << std::endl;
    }

    for (int i = 0; i < nbLignes; i++)
    {
        for (int j = 0; j < nbColonnes; j++)
        {
            file.get(m[j][i]);
        }
        file.get(sautDeLigne);
    }

    file.close();
}

void AfficherMatrice(char** m)
{
    for (int i = 0; i < nbLignes; i++)
    {
        for (int j = 0; j < nbColonnes; j++)
        {
            cout << m[j][i];
        }
        cout << endl;
    }
}

int main()
{
    
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
    
    std::cout << "Hello World!\n";
    

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
    Fantome *fantome = new Fantome(1, 1, matrice);
    int compteur = 0;
    while (1)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
        
        
        AfficherMatrice(matrice);
        fantome->BougerPersonnage(matrice);
        cout << fantome->getTempsSecondes();
       
    }
    
}