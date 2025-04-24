#ifndef CAFFICHAGE_H
#define CAFFICHAGE_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour afficher un graphe de différentes manières
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PAffichage
 *		  Elle permet d'afficher un graphe en utilisant différentes méthodes : 
 *		  - Affichage des noeuds et des arcs
 *		  - Affichage de la matrice d'adjacence
 *
 ************************************************************************************************
 * VERSION : 0.0.3
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
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
	 * Entrée : PGraphOrientAFFGraphe, un graphe orienté
	 * Nécessite : que le graphe spécifié existe
	 * Sortie : Rien
	 * Entraîne : L'affichage de tous les noeuds et de tous les arcs du graphe spécifié OU
	 * (EXCEPTION): graphe spécifié non existant
 ******************************************************************************************/
	
	void AFFAfficheSommetsEtArcs(TGraph TGraphAFFGraphe);

/******************************************************************************************
	* AFFAfficheMatriceAdjacence
	* --------------------------------------------------------------------------------------
	* Entrée : PGraphOrientAFFGraphe, un graphe orienté
	* Nécessite : que le graphe spécifié existe
	* Sortie : Rien
	* Entraîne : L'affichage de la matrice d'adjacence du graphe spécifié OU
	* (EXCEPTION): graphe spécifié non existant
******************************************************************************************/
	
	void AFFAfficheMatriceAdjacence(TGraph TGraphAFFGraphe);
};

#endif