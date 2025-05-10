#ifndef PGRAPH_H
#define PGRAPH_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour manipulations de base d'un graphe non orienté
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PGraph
 *		  Il permet d'effectuer des opérations de base sur un graphe non orienté ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
 * DATE : 10/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 ************************************************************************************************/

#include "PGraphOrient.h"

template <class TArc>
class PGraph : public PGraphOrient<TArc>
{

public:

	//METHODES

/******************************************************************************************
		* GORAjouterArc redéfinie
		* --------------------------------------------------------------------------------------
		* Entrée : CArcGRANewArc, le nouvel arc que l'on veut ajouter au graphe
		* Nécessite : Qu'il n'existe pas déjà un arc ayant les mêmes sommets 1 et 2
		* Que les sommets 1 et 2 existent déjà dans le graphe
		* Sortie : Rien
		* Entraîne : L'arc spécifié est ajouté dans le graphe OU
		* (EXCEPTION): arc déjà existant OU
		* (EXCEPTION): le sommet 1 n'existe pas OU
		* (EXCEPTION): le sommet 2 n'existe pas
******************************************************************************************/

	virtual void GORAjouterArc(TArc* CArcGRANewArc);

/******************************************************************************************
	* GORModifierArc redéfinie
	* --------------------------------------------------------------------------------------
	* Entrée : TArcGRAArc, l'arc que l'on souhaite modifier,
	* uiGRASommetD, le nouveau sommet 1 de l'arc,
	* uiGRASommetA, le nouveau sommet 2 de l'arc.
	* Nécessite : Qu'il n'existe pas déjà un arc ayant les mêmes sommets 1 et 2
	* Que le premier nouveau sommet et le second nouveau existent déjà dans le graphe
	* Que le sommet 1 et 2 restent différents
	* Sortie : Rien
	* Entraîne : L'arc spécifié est modifié dans le graphe OU
	* (EXCEPTION): ancien arc non present dans le graphe OU
	* (EXCEPTION): arc déjà existant OU
	* (EXCEPTION): le sommet 1 ou 2 n'existe pas OU
	* (EXCEPTION): sommets 1 et 2 identiques
******************************************************************************************/

	virtual void GORModifierArc(TArc* TArcGRAArc, unsigned int uiGRASommetD, unsigned int uiGRASommetA);


/******************************************************************************************
	* GORSupprimerArc redéfinie
	* --------------------------------------------------------------------------------------
	* Entrée : TArcGRAArc, l'arc que l'on souhaite supprimer,
	* Nécessite : Que l'arc spécifié existe
	* Sortie : Rien
	* Entraîne : L'arc spécifié est supprimé dans le graphe OU
	* (EXCEPTION): arc non existant
******************************************************************************************/

	virtual void GORSupprimerArc(TArc* TArcGRAArc);

/******************************************************************************************
	* GORFindArc redéfinie
	* --------------------------------------------------------------------------------------
	* Entrée : uiGRANumSommetD, le premier sommet de l'arc recherché,
	* uiGORNumSommetA, le second sommet de l'arc recherché
	* Nécessite : Rien
	* Entraîne : L'affichage de l'arc recherché s'il existe, NULL sinon OU
	* (EXCEPTION): Liste vide, ce qui renvoie NULL OU
	* (EXCEPTION): Les deux sommets spécifiés sont les mêmes, l'arc ne peut pas exister
******************************************************************************************/

	virtual TArc* GORFindArc(unsigned int uiGRANumSommetD, unsigned int uiGRANumSommetA);

/******************************************************************************************
* GORInverseAllArc redéfinie
* --------------------------------------------------------------------------------------
* Entrée : Rien
* Nécessite : D'être appelée sur un graphe orienté
* Entraîne : Un message d'erreur expliquant que cette méthode ne peut être appelée que sur un graphe orienté
******************************************************************************************/

	virtual void GORInverseAllArc();

};

#include "PGraph.th"

#endif