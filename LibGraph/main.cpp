// LibGraph.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>

#include "CArc.h"
#include "PGraphOrient.h"
#include "PSommet.h"

using namespace std;


template <template <class, class> class TGraph, class TArc, template <class> class TSommet, TArc>
TGraph <TArc,TSommet<TArc>> * Lecturefichier(string sNomFichier)
{
    ifstream fFichier(sNomFichier);

    if (fFichier.is_open() != true)
    {
        throw invalid_argument("Le fichier n'est pas ouvert");
    }

    TGraph* NewGraph = new TGraph();
    string sBuffer;
    int iNbrSommet;
    int iNbrArc;
    int iIterator;

    getline(fFichier, sBuffer);
    iNbrSommet = (int)sBuffer.substr(10,sBuffer.size());

    getline(fFichier, sBuffer);
    iNbrArc = (int)sBuffer.substr(7, sBuffer.size());

    getline(fFichier, sBuffer);
    for (iIterator = 0; iIterator < iNbrSommet; iIterator++)
    {
        getline(fFichier, sBuffer);
        TSommet* NewSommet = new TSommet((unsigned int)sBuffer.substr(7, sBuffer.size()));
        NewGraph.GORAjouterSommet(NewSommet);
    }
    getline(fFichier, sBuffer);

    getline(fFichier, sBuffer);
    unsigned int uiSommetD;
    unsigned int uiSommetA;
    for (iIterator = 0; iIterator < iNbrSommet; iIterator++)
    {
        getline(fFichier, sBuffer);

        uiSommetD = (unsigned int)sBuffer.substr(6, sBuffer.find(",", 0));
        uiSommetA = (unsigned int)sBuffer.substr(sBuffer.find(",", 0)+4,sBuffer.size()); 

        TArc* NewArc = new TArc(uiSommetD, uiSommetA);

        NewGraph.GORAjouterArc(NewArc);
    }

    fFichier.close();

    return NewGraph;
}

int main()
{
    std::cout << "Hello World!\n";

    string sFichier = "TestLectureGraph.txt";
    Lecturefichier<PGraphOrient,CArc,PSommet>(sFichier); //Todo faire marcher cette appel
}

