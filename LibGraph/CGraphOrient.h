#ifndef CGRAPHORIENT_H
#define CGRAPHORIENT_H

/************************************************************************************************
 * CLASSE : Classe pour manipulations de base d'un graphe orienté
 ************************************************************************************************
 *
 * ROLE : Interface de la classe CGraphOrient
 *		  Elle permet d'effectuer des opérations de base sur un graphe orienté ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 0.0.2
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
 * DATE : 17/03/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 * 
 ************************************************************************************************/
#include <vector>
#include "CSommet.h"
#include "CArc.h"
using namespace std;

class CGraphOrient
{
//ATTRIBUTS
private :
	vector<CArc*> vGORCArc;
	vector<CSommet*> vGORCSommet;

//CONSTRUCTEURS ET DESTRUCTEURS
public :
	CGraphOrient();
	CGraphOrient(vector<CArc*> vGORCArc, vector<CArc*> vGORCSommet);
	~CGraphOrient();


//METHODES

/******************************************************************************************
	 * GORAjouterArc
	 * --------------------------------------------------------------------------------------
	 * Entrée : CArcGORNewArc, le nouvel arc que l'on veut ajouter au graphe
	 * Nécessite : Qu'il n'existe pas déjà un arc ayant le même sommet de départ et d'arrivée
	 * Que le sommet de départ et le sommet d'arrivée existent déjà dans le graphe
	 * Sortie : Rien
	 * Entraîne : L'arc spécifié est ajouté dans le graphe OU
	 * (EXCEPTION): arc déjà existant OU
	 * (EXCEPTION): le sommet de départ n'existe pas OU 
	 * (EXCEPTION): le sommet d'arrivée n'existe pas
 ******************************************************************************************/

	void GORAjouterArc(CArc CArcGORNewArc);

/******************************************************************************************
	* GORModifierArc
	* --------------------------------------------------------------------------------------
	* Entrée : CArcGORArc, l'arc que l'on souhaite modifier, 
	* uiGORSommetD, le nouveau sommet de départ de l'arc,
	* uiGORSommetA, le nouveau sommet d'arrivée de l'arc.
	* Nécessite : Qu'il n'existe pas déjà un arc ayant le même sommet de départ et d'arrivée
	* Que le nouveau sommet de départ et le sommet d'arrivée existent déjà dans le graphe
	* Que le sommet d’arrivée et de départ restent différents
	* Sortie : Rien
	* Entraîne : L'arc spécifié est modifié dans le graphe OU
	* (EXCEPTION): arc déjà existant OU
	* (EXCEPTION): le sommet de départ ou d'arrivée n'existe pas OU
	* (EXCEPTION) : SommetD et SommetA identiques
******************************************************************************************/

	void GORModifierArc(CArc CArcGORArc, unsigned int uiGORSommetD, unsigned int uiGORSommetA);

/******************************************************************************************
	* GORSupprimerArc
	* --------------------------------------------------------------------------------------
	* Entrée : CArcGORArc, l'arc que l'on souhaite supprimer,
	* Nécessite : Que l'arc spécifié existe
	* Sortie : Rien
	* Entraîne : L'arc spécifié est supprimé dans le graphe OU
	* (EXCEPTION): arc non existant
******************************************************************************************/

	void GORSupprimerArc(CArc CArcGORArc);

/******************************************************************************************
	 * GORAjouterSommet
	 * --------------------------------------------------------------------------------------
	 * Entrée : CSommetGORNewSommet, le nouveeau sommet que l'on veut ajouter au graphe
	 * Nécessite : Rien
	 * Sortie : Rien
	 * Entraîne : Le sommet spécifié est ajouté dans le graphe
 ******************************************************************************************/

	void GORAjouterSommet(CSommet CSommetGORNewSommet);

/******************************************************************************************
	* GORModifierSommet
	* --------------------------------------------------------------------------------------
	* Entrée : CSommetGORSommet, le sommet que l'on souhaite modifier, 
			   uiGORNumSommet, le nouveau numéro du sommet
	* Nécessite : Que le nouveau numéro de sommet ne soit pas déjà attribué
	* Sortie : Rien
	* Entraîne : Le numéro du sommet est modifié OU
	  (EXCEPTION): Le numéro de sommet a déjà été attribué
******************************************************************************************/

	void GORModifierSommet(CSommet CSommetGORSommet, unsigned int uiGORNumSommet);

/******************************************************************************************
	* GORSupprimerSommet
	* --------------------------------------------------------------------------------------
	* Entrée : CSommetGORSommet, le sommet que l'on souhaite supprimer,
	* Nécessite : Que le sommet spécifié existe
	* Que les arcs reliés à ce sommet soient aussi supprimés
	* Sortie : Rien
	* Entraîne : Le sommet spécifié est supprimé dans le graphe OU
	* (EXCEPTION): sommet non existant OU
	* (EXCEPTION): suppression des arcs impossibles
******************************************************************************************/

	void GORSupprimerSommet(CSommet CSommetGORSommet);

/******************************************************************************************
	* GORFindArc
	* --------------------------------------------------------------------------------------
	* Entrée : uiGORNumSommetD, le sommet de départ de l'arc recherché,
	* uiGORNumSommetA, le sommet d'arrivée de l'arc recherché
	* Nécessite : Rien
	* Entraîne : L'affichage de l'arc recherché s'il existe, NULL sinon
******************************************************************************************/

	CArc GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA);

/******************************************************************************************
	* GORFindSommet
	* --------------------------------------------------------------------------------------
	* Entrée : uiGORNumSommet, le sommet recherché,
	* uiGORNumSommet, le numéro de sommet recherché
	* Nécessite : Rien
	* Entraîne : L'affichage du sommet recherché s'il existe, NULL sinon
******************************************************************************************/

	CSommet GORFindSommet(unsigned int uiGORNumSommet);
};

#endif