// LibGraph.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>

#include "CArc.h"
#include "PGraphOrient.h"
#include "PSommet.h"

using namespace std;

template <template <class> class TGraph,class TArc>

TGraph<TArc> Lecturefichier(const string sNomFichier)
{
    ifstream fFichier(sNomFichier);

    if (fFichier.is_open() != true)
    {
        throw invalid_argument("Le fichier n'est pas ouvert");
    }

    TGraph<TArc>* NewGraph = new TGraph<TArc>();
    string sBuffer;
    int iNbrSommet;
    int iNbrArc;
    int iIterator;

    getline(fFichier, sBuffer);
    iNbrSommet = stoul(sBuffer.substr(10,sBuffer.size()));

    getline(fFichier, sBuffer);
    iNbrArc = stoul(sBuffer.substr(7, sBuffer.size()));

    getline(fFichier, sBuffer);
    for (iIterator = 0; iIterator < iNbrSommet; iIterator++)
    {
        getline(fFichier, sBuffer);
        PSommet<TArc> NewSommet = new PSommet<TArc>(stoul(sBuffer.substr(7, sBuffer.size())));
        NewGraph.GORAjouterSommet(NewSommet);
    }
    getline(fFichier, sBuffer);

    getline(fFichier, sBuffer);
    unsigned int uiSommetD;
    unsigned int uiSommetA;
    for (iIterator = 0; iIterator < iNbrSommet; iIterator++)
    {
        getline(fFichier, sBuffer);

        uiSommetD = stoul(sBuffer.substr(6, sBuffer.find(",", 0)));
        uiSommetA = stoul(sBuffer.substr(sBuffer.find(",", 0)+4,sBuffer.size()));

        TArc* NewArc = new TArc(uiSommetD, uiSommetA);

        NewGraph.GORAjouterArc(NewArc);
    }

    fFichier.close();

    return NewGraph;
}

int main()
{
    cout << "Hello World!\n";

    const string sFichier = "TestLectureGraph.txt";
    PGraphOrient<CArc> Graph = Lecturefichier<PGraphOrient, CArc>(sFichier);//Todo faire marcher cette appel

    return 0;
}

//todo : enlever les pointeurs parce que Hugo l'a dit (mettre des . à la place des -> aussi du coup)