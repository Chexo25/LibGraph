#ifndef PGRAPH_H
#define PGRAPH_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour manipulations de base d'un graphe non orient�
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PGraph
 *		  Il permet d'effectuer des op�rations de base sur un graphe non orient� ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
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
		* GORAjouterArc red�finie
		* --------------------------------------------------------------------------------------
		* Entr�e : CArcGRANewArc, le nouvel arc que l'on veut ajouter au graphe
		* N�cessite : Qu'il n'existe pas d�j� un arc ayant les m�mes sommets 1 et 2
		* Que les sommets 1 et 2 existent d�j� dans le graphe
		* Sortie : Rien
		* Entra�ne : L'arc sp�cifi� est ajout� dans le graphe OU
		* (EXCEPTION): arc d�j� existant OU
		* (EXCEPTION): le sommet 1 n'existe pas OU
		* (EXCEPTION): le sommet 2 n'existe pas
******************************************************************************************/

	virtual void GORAjouterArc(TArc* CArcGRANewArc);

/******************************************************************************************
	* GORModifierArc red�finie
	* --------------------------------------------------------------------------------------
	* Entr�e : TArcGRAArc, l'arc que l'on souhaite modifier,
	* uiGRASommetD, le nouveau sommet 1 de l'arc,
	* uiGRASommetA, le nouveau sommet 2 de l'arc.
	* N�cessite : Qu'il n'existe pas d�j� un arc ayant les m�mes sommets 1 et 2
	* Que le premier nouveau sommet et le second nouveau existent d�j� dans le graphe
	* Que le sommet 1 et 2 restent diff�rents
	* Sortie : Rien
	* Entra�ne : L'arc sp�cifi� est modifi� dans le graphe OU
	* (EXCEPTION): ancien arc non present dans le graphe OU
	* (EXCEPTION): arc d�j� existant OU
	* (EXCEPTION): le sommet 1 ou 2 n'existe pas OU
	* (EXCEPTION): sommets 1 et 2 identiques
******************************************************************************************/

	virtual void GORModifierArc(TArc* TArcGRAArc, unsigned int uiGRASommetD, unsigned int uiGRASommetA);


/******************************************************************************************
	* GORSupprimerArc red�finie
	* --------------------------------------------------------------------------------------
	* Entr�e : TArcGRAArc, l'arc que l'on souhaite supprimer,
	* N�cessite : Que l'arc sp�cifi� existe
	* Sortie : Rien
	* Entra�ne : L'arc sp�cifi� est supprim� dans le graphe OU
	* (EXCEPTION): arc non existant
******************************************************************************************/

	virtual void GORSupprimerArc(TArc* TArcGRAArc);

/******************************************************************************************
	* GORFindArc red�finie
	* --------------------------------------------------------------------------------------
	* Entr�e : uiGRANumSommetD, le premier sommet de l'arc recherch�,
	* uiGORNumSommetA, le second sommet de l'arc recherch�
	* N�cessite : Rien
	* Entra�ne : L'affichage de l'arc recherch� s'il existe, NULL sinon OU
	* (EXCEPTION): Liste vide, ce qui renvoie NULL OU
	* (EXCEPTION): Les deux sommets sp�cifi�s sont les m�mes, l'arc ne peut pas exister
******************************************************************************************/

	virtual TArc* GORFindArc(unsigned int uiGRANumSommetD, unsigned int uiGRANumSommetA);

/******************************************************************************************
* GORInverseAllArc red�finie
* --------------------------------------------------------------------------------------
* Entr�e : Rien
* N�cessite : D'�tre appel�e sur un graphe orient�
* Entra�ne : Un message d'erreur expliquant que cette m�thode ne peut �tre appel�e que sur un graphe orient�
******************************************************************************************/

	virtual void GORInverseAllArc();

};

#include "PGraph.th"

#endif