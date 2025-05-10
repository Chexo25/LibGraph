#ifndef PGRAPHORIENT_H
#define PGRAPHORIENT_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour manipulations de base d'un graphe orienté
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PGraphOrient
 *		  Il permet d'effectuer des opérations de base sur un graphe orienté ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
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
	 * Entrée : TArcGORNewArc, le nouvel arc que l'on veut ajouter au graphe
	 * Nécessite : Qu'il n'existe pas déjà un arc ayant le même sommet de départ et d'arrivée
	 * Que le sommet de départ et le sommet d'arrivée existent déjà dans le graphe
	 * Sortie : Rien
	 * Entraîne : L'arc spécifié est ajouté dans le graphe OU
	 * (EXCEPTION): arc déjà existant OU
	 * (EXCEPTION): le sommet de départ n'existe pas OU 
	 * (EXCEPTION): le sommet d'arrivée n'existe pas
 ******************************************************************************************/

	virtual void GORAjouterArc(TArc* TArcGORNewArc);

/******************************************************************************************
	* GORModifierArc
	* --------------------------------------------------------------------------------------
	* Entrée : TArcGORArc, l'arc que l'on souhaite modifier, 
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

	virtual void GORModifierArc(TArc* TArcGORArc, unsigned int uiGORSommetD, unsigned int uiGORSommetA);

/******************************************************************************************
	* GORSupprimerArc
	* --------------------------------------------------------------------------------------
	* Entrée : TArcGORArc, l'arc que l'on souhaite supprimer,
	* Nécessite : Que l'arc spécifié existe
	* Sortie : Rien
	* Entraîne : L'arc spécifié est supprimé dans le graphe OU
	* (EXCEPTION): arc non existant
******************************************************************************************/

	virtual void GORSupprimerArc(TArc* TArcGORArc);

/******************************************************************************************
	 * GORAjouterSommet
	 * --------------------------------------------------------------------------------------
	 * Entrée : PSommetGORNewSommet, le nouveau sommet que l'on veut ajouter au graphe
	 * Nécessite : Rien
	 * Sortie : Rien
	 * Entraîne : Le sommet spécifié est ajouté dans le graphe ou
	 * (EXCEPTION): Le numéro de sommet a déjà été attribué
 ******************************************************************************************/

	void GORAjouterSommet(PSommet<TArc>* PSommetGORNewSommet);

/******************************************************************************************
	* GORModifierSommet
	* --------------------------------------------------------------------------------------
	* Entrée : PSommetGORSommet, le sommet que l'on souhaite modifier, 
			   uiGORNumSommet, le nouveau numéro du sommet
	* Nécessite : Que le nouveau numéro de sommet ne soit pas déjà attribué
	* Sortie : Rien
	* Entraîne : Le numéro du sommet est modifié OU
	  (EXCEPTION): Le numéro de sommet a déjà été attribué
******************************************************************************************/

	void GORModifierSommet(PSommet<TArc>* PSommetGORSommet, unsigned int uiGORNumSommet);

/******************************************************************************************
	* GORSupprimerSommet
	* --------------------------------------------------------------------------------------
	* Entrée : PSommetGORSommet, le sommet que l'on souhaite supprimer,
	* Nécessite : Que le sommet spécifié existe
	* Que les arcs reliés à ce sommet soient aussi supprimés
	* Sortie : Rien
	* Entraîne : Le sommet spécifié est supprimé dans le graphe OU
	* (EXCEPTION): sommet non existant 
******************************************************************************************/

	void GORSupprimerSommet(PSommet<TArc>* PSommetGORSommet);

/******************************************************************************************
	* GORFindArc
	* --------------------------------------------------------------------------------------
	* Entrée : uiGORNumSommetD, le sommet de départ de l'arc recherché,
	* uiGORNumSommetA, le sommet d'arrivée de l'arc recherché
	* Nécessite : Rien
	* Sortie : Un pointeur sur un type générique d'arcs
	* Entraîne : L'affichage de l'arc recherché s'il existe, NULL sinon OU
	* (EXCEPTION): Liste vide, ce qui renvoie NULL
******************************************************************************************/

	TArc* GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA);

/******************************************************************************************
	* GORFindSommet
	* --------------------------------------------------------------------------------------
	* Entrée : uiGORNumSommet, le sommet recherché,
	* uiGORNumSommet, le numéro de sommet recherché
	* Nécessite : Rien
	* Sortie : Un pointeur sur un PSommet
	* Entraîne : L'affichage du sommet recherché s'il existe, NULL sinon OU
	* (EXCEPTION): Liste vide, ce qui renvoie NULL
******************************************************************************************/

	PSommet<TArc>* GORFindSommet(unsigned int uiGORNumSommet);

/******************************************************************************************
	* GORInverseAllArc
	* --------------------------------------------------------------------------------------
	* Entrée : Rien
	* Nécessite : D'être appelée sur un graphe orienté
	* Sortie : Rien
	* Entraîne : L'inversion de tous les arcs du graphe
******************************************************************************************/

	//la méthode est virtuelle afin d'empêcher son utilisation sur un PGraph (inutile d'inverser un graphe non orienté)
	virtual void GORInverseAllArc();

/******************************************************************************************
	* GORGetArc
	* --------------------------------------------------------------------------------------
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le vector vGORTArc
	* Entraîne : Retourne vGORTArc OU
	* (EXCEPTION): vGORTArc est nulle
******************************************************************************************/

	vector<TArc*> GORGetArc();

/******************************************************************************************
	* GORGetSommet
	* --------------------------------------------------------------------------------------
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le vector vGORPSommet
	* Entraîne : Retourne vGORPSommet OU
	* (EXCEPTION): vGORPSommet est nulle
******************************************************************************************/

	vector<PSommet<TArc>*> GORGetSommet();

};

#include "PGraphOrient.th"

#endif