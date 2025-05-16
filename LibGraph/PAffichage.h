#ifndef PAFFICHAGE_TH
#define PAFFICHAGE_TH

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour afficher un graphe de diff�rentes mani�res
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PAffichage
 *		  Elle permet d'afficher un graphe en utilisant diff�rentes m�thodes : 
 *		  - Affichage des noeuds et des arcs
 *		  - Affichage de la matrice d'adjacence
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 10/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 ************************************************************************************************/

#include "PGraphOrient.h"
#include "PSommet.h"
#include "PCliqueMaxima.h"

#include <unordered_map>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

template <class TGraph, class TArc>
class PAffichage {

public:

/******************************************************************************************
	 * AFFAfficheSommetsEtArcs
	 * --------------------------------------------------------------------------------------
	 * Entr�e : PGraphOrientAFFGraphe, un graphe orient�
	 * N�cessite : que le graphe sp�cifi� existe
	 * Sortie : Rien
	 * Entra�ne : L'affichage de tous les noeuds et de tous les arcs du graphe sp�cifi� OU
	 * (EXCEPTION): le graphe ne contient aucun sommet
 ******************************************************************************************/
	
	void AFFAfficheSommetsEtArcs(TGraph& TGraphAFFGraphe);

/******************************************************************************************
	* AFFAfficheMatriceAdjacence
	* --------------------------------------------------------------------------------------
	* Entr�e : PGraphOrientAFFGraphe, un graphe orient�
	* N�cessite : que le graphe sp�cifi� existe
	* Sortie : Rien
	* Entra�ne : L'affichage de la matrice d'adjacence du graphe sp�cifi� OU
	* (EXCEPTION): le graphe ne contient aucun sommet
******************************************************************************************/
	
	void AFFAfficheMatriceAdjacence(TGraph& TGraphAFFGraphe);

	void AFFAfficherCliquesMaxima(TGraph& TGraphAFFGraphe);
};

#include "PAffichage.th"

#endif