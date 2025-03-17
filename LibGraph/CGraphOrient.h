#ifndef CGRAPHORIENT_H
#define CGRAPHORIENT_H

/************************************************************************************************
 * CLASSE : Classe pour manipulations de base d'un graphe orienté
 ************************************************************************************************
 *
 * ROLE : Interface de la classe CGraphOrient
 *        Cette classe permet de manipuler un graphe orienté
 *		  Elle permet d'effectuer des opérations de base sur un graphe orienté
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
 * GORAjouterCArc
 * --------------------------------------------------------------------------------------
 * Entrée : CArcGORNewArc, le nouvel arc que l'on veut ajouter au graphe
 * Nécessite : Qu'il n'existe pas déjà un arc ayant le même sommet de départ et d'arrivée
 * Que le sommet de départ et le sommet d'arrivée existent déjà dans le graphe
 * Sortie : Rien
 * Entraîne : L'arc spécifié est ajouté dans le graphe OU
 * (EXCEPTION): arc déjà existant OU
 * (EXCEPTION): le sommet de départ  ou d'arrivée n'existe pas
 ******************************************************************************************/

	void GORAjouterArc(CArc CArcGORNewArc);

/******************************************************************************************
	* GORAjouterCArc
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

	void GORSupprimerArc(CArc CArcGORArc);

	void GORAjouterSommet(CSommet CSommetGORNewSommet);

	void GORModifierSommet(CSommet CSommetGORSommet, unsigned int uiGORNumSommet);

	void GORSupprimerSommet(CSommet CSommetGORSommet);

	CArc GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA);

	CSommet GORFindSommet(unsigned int uiGORNumSommet);
};


#endif

//todo : faire les commentaires tkindt friendly
