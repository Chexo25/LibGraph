#ifndef PGRAPHORIENT_H
#define PGRAPHORIENT_H

/************************************************************************************************
 * CLASSE : Classe pour manipulations de base d'un graphe orient�
 ************************************************************************************************
 *
 * ROLE : Interface de la classe PGraphOrient
 *		  Elle permet d'effectuer des op�rations de base sur un graphe orient� ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 0.0.4
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 23/04/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 * 
 ************************************************************************************************/
#include <vector>
#include "PSommet.h"
#include "CArc.h"
using namespace std;

template<class TArc, class TSommet>
class PGraphOrient
{
//ATTRIBUTS
private :
	vector<TArc*> vGORCArc;
	vector<TSommet*> vGORCSommet;

//CONSTRUCTEURS ET DESTRUCTEURS
public :

	PGraphOrient(vector<TArc*> vGORCArc, vector<TSommet*> vGORCSommet);
	~PGraphOrient();


//METHODES

/******************************************************************************************
	 * GORAjouterArc
	 * --------------------------------------------------------------------------------------
	 * Entr�e : CArcGORNewArc, le nouvel arc que l'on veut ajouter au graphe
	 * N�cessite : Qu'il n'existe pas d�j� un arc ayant le m�me sommet de d�part et d'arriv�e
	 * Que le sommet de d�part et le sommet d'arriv�e existent d�j� dans le graphe
	 * Sortie : Rien
	 * Entra�ne : L'arc sp�cifi� est ajout� dans le graphe OU
	 * (EXCEPTION): arc d�j� existant OU
	 * (EXCEPTION): le sommet de d�part n'existe pas OU 
	 * (EXCEPTION): le sommet d'arriv�e n'existe pas
 ******************************************************************************************/

	void GORAjouterArc(TArc* CArcGORNewArc);

/******************************************************************************************
	* GORModifierArc
	* --------------------------------------------------------------------------------------
	* Entr�e : CArcGORArc, l'arc que l'on souhaite modifier, 
	* uiGORSommetD, le nouveau sommet de d�part de l'arc,
	* uiGORSommetA, le nouveau sommet d'arriv�e de l'arc.
	* N�cessite : Qu'il n'existe pas d�j� un arc ayant le m�me sommet de d�part et d'arriv�e
	* Que le nouveau sommet de d�part et le sommet d'arriv�e existent d�j� dans le graphe
	* Que le sommet d�arriv�e et de d�part restent diff�rents
	* Sortie : Rien
	* Entra�ne : L'arc sp�cifi� est modifi� dans le graphe OU
	* (EXCEPTION): arc d�j� existant OU
	* (EXCEPTION): le sommet de d�part ou d'arriv�e n'existe pas OU
	* (EXCEPTION) : SommetD et SommetA identiques
******************************************************************************************/

	void GORModifierArc(TArc* CArcGORArc, unsigned int uiGORSommetD, unsigned int uiGORSommetA);

/******************************************************************************************
	* GORSupprimerArc
	* --------------------------------------------------------------------------------------
	* Entr�e : CArcGORArc, l'arc que l'on souhaite supprimer,
	* N�cessite : Que l'arc sp�cifi� existe
	* Sortie : Rien
	* Entra�ne : L'arc sp�cifi� est supprim� dans le graphe OU
	* (EXCEPTION): arc non existant
******************************************************************************************/

	void GORSupprimerArc(TArc* CArcGORArc);

/******************************************************************************************
	 * GORAjouterSommet
	 * --------------------------------------------------------------------------------------
	 * Entr�e : CSommetGORNewSommet, le nouveau sommet que l'on veut ajouter au graphe
	 * N�cessite : Rien
	 * Sortie : Rien
	 * Entra�ne : Le sommet sp�cifi� est ajout� dans le graphe ou
	 * (EXCEPTION): Le num�ro de sommet a d�j� �t� attribu�
 ******************************************************************************************/

	void GORAjouterSommet(TSommet* CSommetGORNewSommet);

/******************************************************************************************
	* GORModifierSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : CSommetGORSommet, le sommet que l'on souhaite modifier, 
			   uiGORNumSommet, le nouveau num�ro du sommet
	* N�cessite : Que le nouveau num�ro de sommet ne soit pas d�j� attribu�
	* Sortie : Rien
	* Entra�ne : Le num�ro du sommet est modifi� OU
	  (EXCEPTION): Le num�ro de sommet a d�j� �t� attribu�
******************************************************************************************/

	void GORModifierSommet(TSommet* CSommetGORSommet, unsigned int uiGORNumSommet);

/******************************************************************************************
	* GORSupprimerSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : CSommetGORSommet, le sommet que l'on souhaite supprimer,
	* N�cessite : Que le sommet sp�cifi� existe
	* Que les arcs reli�s � ce sommet soient aussi supprim�s
	* Sortie : Rien
	* Entra�ne : Le sommet sp�cifi� est supprim� dans le graphe OU
	* (EXCEPTION): sommet non existant 
******************************************************************************************/

	void GORSupprimerSommet(TSommet* CSommetGORSommet);

/******************************************************************************************
	* GORFindArc
	* --------------------------------------------------------------------------------------
	* Entr�e : uiGORNumSommetD, le sommet de d�part de l'arc recherch�,
	* uiGORNumSommetA, le sommet d'arriv�e de l'arc recherch�
	* N�cessite : Rien
	* Entra�ne : L'affichage de l'arc recherch� s'il existe, NULL sinon
******************************************************************************************/

	TArc* GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA);

/******************************************************************************************
	* GORFindSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : uiGORNumSommet, le sommet recherch�,
	* uiGORNumSommet, le num�ro de sommet recherch�
	* N�cessite : Rien
	* Entra�ne : L'affichage du sommet recherch� s'il existe, NULL sinon
******************************************************************************************/

	TSommet* GORFindSommet(unsigned int uiGORNumSommet);

/******************************************************************************************
	* GORGetArc
	* --------------------------------------------------------------------------------------
	* Entr�e : Rien
	* Sortie : Le vector vGORCArc
	* Entra�ne : Retourne vGORCArc OU
	* (EXCEPTION): vGORCArc est nulle
******************************************************************************************/

	vector<TArc*> GORGetArc();

/******************************************************************************************
	* GORGetSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : Rien
	* Sortie : Le vector vGORCSommet
	* Entra�ne : Retourne vGORCSommet OU
	* (EXCEPTION): vGORCSommet est nulle
******************************************************************************************/

	vector<TSommet*> GORGetSommet();


};

#endif