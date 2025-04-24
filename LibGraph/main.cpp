// LibGraph.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}




// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.



template <class TGraph,class TSommet,class TArc>
TGraph* Lecturefichier(string sNomFichier)
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