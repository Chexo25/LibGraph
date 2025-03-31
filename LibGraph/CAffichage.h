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
 * VERSION : 0.0.1
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 31/03/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 *
 ************************************************************************************************/

#include "CGraphOrient.h"

class CAffichage {
	
	//METHODES :

/******************************************************************************************
	 * AFFAfficheNoeudsEtArcs
	 * --------------------------------------------------------------------------------------
	 * Entr�e : CGraphOrientAFFGraphe, un graphe orient�
	 * N�cessite : que le graphe sp�cifi� existe
	 * Sortie : Rien
	 * Entra�ne : L'affichage de tous les noeuds et de tous les arcs du graphe sp�cifi� OU
	 * (EXCEPTION): graphe sp�cifi� non existant
 ******************************************************************************************/

	void AFFAfficheNoeudsEtArcs(CGraphOrient CGraphOrientAFFGraphe);

/******************************************************************************************
	* AFFAfficheMatriceAdjacence
	* --------------------------------------------------------------------------------------
	* Entr�e : CGraphOrientAFFGraphe, un graphe orient�
	* N�cessite : que le graphe sp�cifi� existe
	* Sortie : Rien
	* Entra�ne : L'affichage de la matrice d'adjacence du graphe sp�cifi� OU
	* (EXCEPTION): graphe sp�cifi� non existant
******************************************************************************************/

	void AFFAfficheMatriceAdjacence(CGraphOrient CGraphOrientAFFGraphe);
};

#endif