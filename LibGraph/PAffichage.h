#ifndef CAFFICHAGE_H
#define CAFFICHAGE_H

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
 * VERSION : 0.0.3
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 24/04/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 *
 ************************************************************************************************/
#include "PGraphOrient.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

template <class TGraph, class TArc, class TSommet>
class PAffichage {
	
	//METHODES :

/******************************************************************************************
	 * AFFAfficheSommetsEtArcs
	 * --------------------------------------------------------------------------------------
	 * Entr�e : PGraphOrientAFFGraphe, un graphe orient�
	 * N�cessite : que le graphe sp�cifi� existe
	 * Sortie : Rien
	 * Entra�ne : L'affichage de tous les noeuds et de tous les arcs du graphe sp�cifi� OU
	 * (EXCEPTION): graphe sp�cifi� non existant
 ******************************************************************************************/
	
	void AFFAfficheSommetsEtArcs(TGraph TGraphAFFGraphe);

/******************************************************************************************
	* AFFAfficheMatriceAdjacence
	* --------------------------------------------------------------------------------------
	* Entr�e : PGraphOrientAFFGraphe, un graphe orient�
	* N�cessite : que le graphe sp�cifi� existe
	* Sortie : Rien
	* Entra�ne : L'affichage de la matrice d'adjacence du graphe sp�cifi� OU
	* (EXCEPTION): graphe sp�cifi� non existant
******************************************************************************************/
	
	void AFFAfficheMatriceAdjacence(TGraph TGraphAFFGraphe);
};

#endif