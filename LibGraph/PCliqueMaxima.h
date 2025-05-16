#ifndef PCLIQUE_MAXIMA_H
#define PCLIQUE_MAXIMA_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour les cliques d'un graphe
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PCliqueMaxima
 *		  Il permet de retrouver les cliques maxima au sein d'un graphes en utilisant différentes méthodes
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
 * DATE : 10/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 ************************************************************************************************/

#include "PSommet.h"
#include "PGraph.h"
#include <vector>

template <class TArc>
class PClique_max
{

private:
	//ATTRIBUTS

	vector<vector<PSommet<TArc>*>> vvCliques_Max;
	size_t stTailleMaxClique;

public:
	//CONSTRUCTEURS

	PClique_max();
	~PClique_max();

	//GETTERS ET SETTERS

	vector<vector<PSommet<TArc>*>> CLIGetVvCliquesMax();

	//METHODES

/******************************************************************************************
	 * CLIIsClique
	 * --------------------------------------------------------------------------------------
	 * Entrée : CLIvSommet, un vecteur de sommet 
	 * Nécessite : Que le vecteur de sommet spécifié soit valide
	 * Sortie : Un booléen : true ou false
	 * Entraîne : Un booléen true ou false indiquant si le vector de sommets spécifié est une clique OU
	 * (EXCEPTION) : Le vector passé en paramètre est vide
******************************************************************************************/

	bool CLIIsClique(const vector<PSommet<TArc>*>& CLIvSommet);

/******************************************************************************************
	* CLIEnuCliqueMax
	* -------------------------------------------------------------------------------------
	* Entrée : CLIGraph
	* Nécessite : Que le vecteur de sommet spécifié soit valide
	* Sortie : Un booléen : true ou false
	* Entraîne : Un booléen true ou false indiquant si le vector de sommets spécifié est une clique
******************************************************************************************/

	void CLIEnuCliqueMax(PGraph<TArc> CLIGraph, vector<PSommet<TArc>*> ListeSommet);

/******************************************************************************************
	* CLIResetCliqueMax
	* -------------------------------------------------------------------------------------
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Le vector représentant les cliques maxima est vidé
******************************************************************************************/

	void CLIResetCliqueMax();

};

#include "PCliqueMaxima.th"
#endif