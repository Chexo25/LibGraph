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

#include "CArc.h"
#include "PGraphOrient.h"
#include "PGraph.h"
#include "PSommet.h"
#include "PCliqueMaxima.h"
#include "Affichage.h"
#include "LectureFichier.h"

using namespace std;

int main()
{
    const string sFichier = "TestLectureGraph.txt";
    try {
        PGraph<CArc>* pGraph = Lecturefichier<PGraph, CArc>(sFichier);
        AfficheMatriceAdjacence<PGraph<CArc>, CArc>(*pGraph);
        AfficheCliquesMaxima<PGraph<CArc>, CArc>(*pGraph);

        delete pGraph;
    }
    catch (const exception& e) {
        cerr << "Erreur : " << e.what() << endl;
    }

    return 0;
}
