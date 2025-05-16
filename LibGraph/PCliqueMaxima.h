#ifndef PCLIQUE_MAXIMA_H
#define PCLIQUE_MAXIMA_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour les cliques d'un graphe
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PCliqueMaxima
 *		  Il permet de retrouver les cliques maxima au sein d'un graphes en utilisant diff�rentes m�thodes
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
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
	 * Entr�e : CLIvSommet, un vecteur de sommet 
	 * N�cessite : Que le vecteur de sommet sp�cifi� soit valide
	 * Sortie : Un bool�en : true ou false
	 * Entra�ne : Un bool�en true ou false indiquant si le vector de sommets sp�cifi� est une clique OU
	 * (EXCEPTION) : Le vector pass� en param�tre est vide
******************************************************************************************/

	bool CLIIsClique(const vector<PSommet<TArc>*>& CLIvSommet);

/******************************************************************************************
	* CLIEnuCliqueMax
	* -------------------------------------------------------------------------------------
	* Entr�e : CLIGraph
	* N�cessite : Que le vecteur de sommet sp�cifi� soit valide
	* Sortie : Un bool�en : true ou false
	* Entra�ne : Un bool�en true ou false indiquant si le vector de sommets sp�cifi� est une clique
******************************************************************************************/

	void CLIEnuCliqueMax(PGraph<TArc> CLIGraph, vector<PSommet<TArc>*> ListeSommet);

/******************************************************************************************
	* CLIResetCliqueMax
	* -------------------------------------------------------------------------------------
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Le vector repr�sentant les cliques maxima est vid�
******************************************************************************************/

	void CLIResetCliqueMax();

};

#include "PCliqueMaxima.th"
#endif