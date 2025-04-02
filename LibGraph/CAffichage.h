#ifndef CAFFICHAGE_H
#define CAFFICHAGE_H

/************************************************************************************************
 * CLASSE : Classe pour affichage d'un graphe
 ************************************************************************************************
 *
 * ROLE : Interface de la classe CAffichage
 *		  Elle permet d'afficher un graphe en utilisant diff�rentes m�thodes : 
 *		  - Affichage des noeuds et des arcs
 *		  - Affichage de la matrice d'adjacence
 *
 ************************************************************************************************
 * VERSION : 0.0.2
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
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
	 * Entr�e : PGraphOrientAFFGraphe, un graphe orient�
	 * N�cessite : que le graphe sp�cifi� existe
	 * Sortie : Rien
	 * Entra�ne : L'affichage de tous les noeuds et de tous les arcs du graphe sp�cifi� OU
	 * (EXCEPTION): graphe sp�cifi� non existant
 ******************************************************************************************/

	void AFFAfficheNoeudsEtArcs(PGraphOrient PGraphOrientAFFGraphe);

/******************************************************************************************
	* AFFAfficheMatriceAdjacence
	* --------------------------------------------------------------------------------------
	* Entr�e : PGraphOrientAFFGraphe, un graphe orient�
	* N�cessite : que le graphe sp�cifi� existe
	* Sortie : Rien
	* Entra�ne : L'affichage de la matrice d'adjacence du graphe sp�cifi� OU
	* (EXCEPTION): graphe sp�cifi� non existant
******************************************************************************************/

	void AFFAfficheMatriceAdjacence(PGraphOrient PGraphOrientAFFGraphe);
};

#endif