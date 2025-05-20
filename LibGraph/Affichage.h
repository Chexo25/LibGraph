#ifndef AFFICHAGE_H
#define AFFICHAGE_H
/************************************************************************************************
 * FICHIER : Fichier contenant les diff�rentes fonctions d'affichage
 ************************************************************************************************
 *
 * ROLE : Contenir diff�rentes fonctions externes d'affichage :
 *		  Permet d'afficher un graphe en utilisant diff�rentes m�thodes :
 *		  - Affichage des noeuds et des arcs
 *		  - Affichage de la matrice d'adjacence
 *		  Permet d'afficher les cliques maxima d'un graphe
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 20/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
************************************************************************************************/

#include <unordered_map>
#include <vector>
#include <iomanip>
#include "PSommet.h"

using namespace std;

/******************************************************************************************
	 * AFFAfficheSommetsEtArcs
	 * --------------------------------------------------------------------------------------
	 * Entr�e : PGraphGraphe, un graphe
	 * N�cessite : que le graphe sp�cifi� existe
	 * Sortie : Rien
	 * Entra�ne : L'affichage de tous les noeuds et de tous les arcs du graphe sp�cifi� OU
	 * (EXCEPTION): le graphe ne contient aucun sommet
 ******************************************************************************************/

template <class TGraph, class TArc>
void AfficheSommetsEtArcs(TGraph& PGraphGraphe);

/******************************************************************************************
	* AfficheMatriceAdjacence
	* --------------------------------------------------------------------------------------
	* Entr�e : PGraphGraphe, un graphe
	* N�cessite : que le graphe sp�cifi� existe
	* Sortie : Rien
	* Entra�ne : L'affichage de la matrice d'adjacence du graphe sp�cifi� OU
	* (EXCEPTION): le graphe ne contient aucun sommet
******************************************************************************************/

template <class TGraph, class TArc>
void AfficheMatriceAdjacence(TGraph& PGraphGraphe);

/******************************************************************************************
	* AfficherCliquesMaxima
	* --------------------------------------------------------------------------------------
	* Entr�e : PGraphGraphe, un graphe
	* N�cessite : que le graphe sp�cifi� existe
	* Sortie : Rien
	* Entra�ne : L'affichage des diff�rentes cliques maxima du graphe
******************************************************************************************/

template <class TGraph, class TArc>
void AfficheCliquesMaxima(TGraph& TGraphGraphe);

#include "Affichage.th"

#endif