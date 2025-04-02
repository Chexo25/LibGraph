#ifndef CAFFICHAGE_H
#define CAFFICHAGE_H

/************************************************************************************************
 * CLASSE : Classe pour affichage d'un graphe
 ************************************************************************************************
 *
 * ROLE : Interface de la classe CAffichage
 *		  Elle permet d'afficher un graphe en utilisant différentes méthodes : 
 *		  - Affichage des noeuds et des arcs
 *		  - Affichage de la matrice d'adjacence
 *
 ************************************************************************************************
 * VERSION : 0.0.2
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
 * DATE : 02/04/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 *
 ************************************************************************************************/

#include "CGraphOrient.h"
using namespace std;

class CAffichage {
	
	//METHODES :

/******************************************************************************************
	 * AFFAfficheNoeudsEtArcs
	 * --------------------------------------------------------------------------------------
	 * Entrée : PGraphOrientAFFGraphe, un graphe orienté
	 * Nécessite : que le graphe spécifié existe
	 * Sortie : Rien
	 * Entraîne : L'affichage de tous les noeuds et de tous les arcs du graphe spécifié OU
	 * (EXCEPTION): graphe spécifié non existant
 ******************************************************************************************/

	void AFFAfficheNoeudsEtArcs(PGraphOrient PGraphOrientAFFGraphe);

/******************************************************************************************
	* AFFAfficheMatriceAdjacence
	* --------------------------------------------------------------------------------------
	* Entrée : PGraphOrientAFFGraphe, un graphe orienté
	* Nécessite : que le graphe spécifié existe
	* Sortie : Rien
	* Entraîne : L'affichage de la matrice d'adjacence du graphe spécifié OU
	* (EXCEPTION): graphe spécifié non existant
******************************************************************************************/

	void AFFAfficheMatriceAdjacence(PGraphOrient PGraphOrientAFFGraphe);
};

#endif