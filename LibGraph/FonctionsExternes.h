#ifndef FONCEXT_H
#define FONCEXT_H
/************************************************************************************************
 * FICHIER : Fichier contenant diff�rentes fonctions utiles au bon fonctionnement de la librairie
 ************************************************************************************************
 *
 * ROLE : Contenir diff�rentes fonctions externes aux graphes mais utiles � la librairie :
 *		  Permet de lire un fichier et d'en retourner un graphe
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

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include "PSommet.h"

using namespace std;

/******************************************************************************************
     * Lecturefichier
     * --------------------------------------------------------------------------------------
     * Entr�e : sNomFichier, un fichier
     * N�cessite : que le fichier sp�cifi� existe
     * Sortie : Rien
     * Entra�ne : L'ouverture du fichier et la lecture des lignes permettant l'affichge du graphe OU
     * (EXCEPTION): le fichier ne s'est pas ouvert correctement
******************************************************************************************/

template <template <class> class TGraph, class TArc>
TGraph<TArc>* Lecturefichier(const string sNomFichier);

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

#include "FonctionsExternes.th"

#endif