#ifndef PGRAPHORIENT_H
#define PGRAPHORIENT_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour manipulations de base d'un graphe orient�
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PGraphOrient
 *		  Il permet d'effectuer des op�rations de base sur un graphe orient� ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 10/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 ************************************************************************************************/

#include <vector>

#include "PSommet.h"
#include "CArc.h"

using namespace std;

template <class TArc>
class PGraphOrient
{
	//ATTRIBUTS
private:
	vector<TArc*> vGORTArc;
	vector<PSommet<TArc>*> vGORPSommet;

	//CONSTRUCTEURS ET DESTRUCTEURS
public:

	PGraphOrient<TArc>();
	PGraphOrient(vector<TArc*> vGORTArc, vector<PSommet<TArc>*> vGORPSommet);
	~PGraphOrient();


	//METHODES

	//Getter de vGORTArc
	vector<TArc*>& GORGetvGORTArc();

/******************************************************************************************
	 * GORAjouterArc
	 * --------------------------------------------------------------------------------------
	 * Entr�e : TArcGORNewArc, le nouvel arc que l'on veut ajouter au graphe
	 * N�cessite : Qu'il n'existe pas d�j� un arc ayant le m�me sommet de d�part et d'arriv�e
	 * Que le sommet de d�part et le sommet d'arriv�e existent d�j� dans le graphe
	 * Sortie : Rien
	 * Entra�ne : L'arc sp�cifi� est ajout� dans le graphe OU
	 * (EXCEPTION): arc d�j� existant OU
	 * (EXCEPTION): le sommet de d�part n'existe pas OU 
	 * (EXCEPTION): le sommet d'arriv�e n'existe pas
 ******************************************************************************************/

	virtual void GORAjouterArc(TArc* TArcGORNewArc);

/******************************************************************************************
	* GORModifierArc
	* --------------------------------------------------------------------------------------
	* Entr�e : TArcGORArc, l'arc que l'on souhaite modifier, 
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

	virtual void GORModifierArc(TArc* TArcGORArc, unsigned int uiGORSommetD, unsigned int uiGORSommetA);

/******************************************************************************************
	* GORSupprimerArc
	* --------------------------------------------------------------------------------------
	* Entr�e : TArcGORArc, l'arc que l'on souhaite supprimer,
	* N�cessite : Que l'arc sp�cifi� existe
	* Sortie : Rien
	* Entra�ne : L'arc sp�cifi� est supprim� dans le graphe OU
	* (EXCEPTION): arc non existant
******************************************************************************************/

	virtual void GORSupprimerArc(TArc* TArcGORArc);

/******************************************************************************************
	 * GORAjouterSommet
	 * --------------------------------------------------------------------------------------
	 * Entr�e : PSommetGORNewSommet, le nouveau sommet que l'on veut ajouter au graphe
	 * N�cessite : Rien
	 * Sortie : Rien
	 * Entra�ne : Le sommet sp�cifi� est ajout� dans le graphe ou
	 * (EXCEPTION): Le num�ro de sommet a d�j� �t� attribu�
 ******************************************************************************************/

	void GORAjouterSommet(PSommet<TArc>* PSommetGORNewSommet);

/******************************************************************************************
	* GORModifierSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : PSommetGORSommet, le sommet que l'on souhaite modifier, 
			   uiGORNumSommet, le nouveau num�ro du sommet
	* N�cessite : Que le nouveau num�ro de sommet ne soit pas d�j� attribu�
	* Sortie : Rien
	* Entra�ne : Le num�ro du sommet est modifi� OU
	  (EXCEPTION): Le num�ro de sommet a d�j� �t� attribu�
******************************************************************************************/

	void GORModifierSommet(PSommet<TArc>* PSommetGORSommet, unsigned int uiGORNumSommet);

/******************************************************************************************
	* GORSupprimerSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : PSommetGORSommet, le sommet que l'on souhaite supprimer,
	* N�cessite : Que le sommet sp�cifi� existe
	* Que les arcs reli�s � ce sommet soient aussi supprim�s
	* Sortie : Rien
	* Entra�ne : Le sommet sp�cifi� est supprim� dans le graphe OU
	* (EXCEPTION): sommet non existant 
******************************************************************************************/

	void GORSupprimerSommet(PSommet<TArc>* PSommetGORSommet);

/******************************************************************************************
	* GORFindArc
	* --------------------------------------------------------------------------------------
	* Entr�e : uiGORNumSommetD, le sommet de d�part de l'arc recherch�,
	* uiGORNumSommetA, le sommet d'arriv�e de l'arc recherch�
	* N�cessite : Rien
	* Sortie : Un pointeur sur un type g�n�rique d'arcs
	* Entra�ne : L'affichage de l'arc recherch� s'il existe, NULL sinon OU
	* (EXCEPTION): Liste vide, ce qui renvoie NULL
******************************************************************************************/

	TArc* GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA);

/******************************************************************************************
	* GORFindSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : uiGORNumSommet, le sommet recherch�,
	* uiGORNumSommet, le num�ro de sommet recherch�
	* N�cessite : Rien
	* Sortie : Un pointeur sur un PSommet
	* Entra�ne : L'affichage du sommet recherch� s'il existe, NULL sinon OU
	* (EXCEPTION): Liste vide, ce qui renvoie NULL
******************************************************************************************/

	PSommet<TArc>* GORFindSommet(unsigned int uiGORNumSommet);

/******************************************************************************************
	* GORInverseAllArc
	* --------------------------------------------------------------------------------------
	* Entr�e : Rien
	* N�cessite : D'�tre appel�e sur un graphe orient�
	* Sortie : Rien
	* Entra�ne : L'inversion de tous les arcs du graphe
******************************************************************************************/

	//la m�thode est virtuelle afin d'emp�cher son utilisation sur un PGraph (inutile d'inverser un graphe non orient�)
	virtual void GORInverseAllArc();

/******************************************************************************************
	* GORGetArc
	* --------------------------------------------------------------------------------------
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Le vector vGORTArc
	* Entra�ne : Retourne vGORTArc OU
	* (EXCEPTION): vGORTArc est nulle
******************************************************************************************/

	vector<TArc*> GORGetArc();

/******************************************************************************************
	* GORGetSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Le vector vGORPSommet
	* Entra�ne : Retourne vGORPSommet OU
	* (EXCEPTION): vGORPSommet est nulle
******************************************************************************************/

	vector<PSommet<TArc>*> GORGetSommet();

};

#include "PGraphOrient.th"

#endif