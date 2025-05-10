/************************************************************************************************
 * FICHIER : main.cpp, l'exécution du programme commence et se termine ici
 ************************************************************************************************
 *
 * ROLE : Main d'où tout le programme peut être lancé.
 *        Contient aussi la fonction de lecture de fichier
 *        Le main utilise les méthodes de la template PAffichage pour afficher les graphes
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
 * DATE : 10/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 ************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "CArc.h"
#include "PGraphOrient.h"
#include "PGraph.h"
#include "PSommet.h"
#include "PAffichage.h"

using namespace std;

template <template <class> class TGraph,class TArc>

/******************************************************************************************
     * Lecturefichier
     * --------------------------------------------------------------------------------------
     * Entrée : sNomFichier, un fichier
     * Nécessite : que le fichier spécifié existe
     * Sortie : Rien
     * Entraîne : L'ouverture du fichier et la lecture des lignes permettant l'affichge du graphe OU
     * (EXCEPTION): le fichier ne s'est pas ouvert correctement
 ******************************************************************************************/

TGraph<TArc> * Lecturefichier(const string sNomFichier)
{
    ifstream fFichier(sNomFichier);

    if (fFichier.is_open() != true)
    {
        throw invalid_argument("Le fichier n'est pas ouvert");
    }

    TGraph<TArc> * NewGraph = new TGraph<TArc>();
    string sBuffer;
    int iNbrSommet;
    int iNbrArc;
    int iIterator;

    PSommet<TArc>* NewSommet;

    getline(fFichier, sBuffer);
    iNbrSommet = stoul(sBuffer.substr(10,sBuffer.size()));

    getline(fFichier, sBuffer);
    iNbrArc = stoul(sBuffer.substr(7, sBuffer.size()));

    getline(fFichier, sBuffer);
    for (iIterator = 0; iIterator < iNbrSommet; iIterator++)
    {
        getline(fFichier, sBuffer);
        string Num = sBuffer.substr(7, sBuffer.size());
		unsigned int uiNum = stoul(Num);
        NewSommet = new PSommet<TArc>(uiNum);
        NewGraph->GORAjouterSommet(NewSommet);
    }

    getline(fFichier, sBuffer);

    getline(fFichier, sBuffer);
    unsigned int uiSommetD;
    unsigned int uiSommetA;
    for (iIterator = 0; iIterator < iNbrArc; iIterator++)
    {
        getline(fFichier, sBuffer);

        uiSommetD = stoul(sBuffer.substr(6, sBuffer.find(",", 0)));
        uiSommetA = stoul(sBuffer.substr(sBuffer.find(",", 0)+6,sBuffer.size()));

        TArc* NewArc = new TArc(uiSommetD, uiSommetA);

        NewGraph->GORAjouterArc(NewArc);
    }

    fFichier.close();

    return NewGraph;
}

int main()
{
    const string sFichier = "TestLectureGraph.txt";
    try {
        //PGraph<CArc>* Graph = Lecturefichier<PGraph, CArc>(sFichier); //Graphe non orienté
        //PAffichage<PGraph<CArc>, CArc> affichage;
        PGraphOrient<CArc>* Graph = Lecturefichier<PGraphOrient, CArc>(sFichier); //Graphe orienté
        PAffichage<PGraphOrient<CArc>, CArc> affichage;

        cout << "affichage avant inversion\n" << endl;
        
        affichage.AFFAfficheSommetsEtArcs(*Graph); //appeler la méthode d'affichage des sommets et arcs du graphe
        affichage.AFFAfficheMatriceAdjacence(*Graph); //appeler la méthode d'affichage de la matrice d'adjacence du graphe
        
        Graph->GORInverseAllArc();
        
        cout << "\naffichage apres inversion\n" << endl;
        
        affichage.AFFAfficheSommetsEtArcs(*Graph); //appeler la méthode d'affichage des sommets et arcs du graphe
        affichage.AFFAfficheMatriceAdjacence(*Graph); //appeler la méthode d'affichage de la matrice d'adjacence du graphe
        
        delete Graph;
    }
    catch (const exception& e) {
        cerr << "Erreur : " << e.what() << endl;
    }
    return 0;
}