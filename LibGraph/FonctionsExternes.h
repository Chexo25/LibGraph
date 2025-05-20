#ifndef FONCEXT_H
#define FONCEXT_H
/************************************************************************************************
 * FICHIER : Fichier contenant différentes fonctions utiles au bon fonctionnement de la librairie
 ************************************************************************************************
 *
 * ROLE : Contenir différentes fonctions externes aux graphes mais utiles à la librairie :
 *		  Permet de lire un fichier et d'en retourner un graphe
 *		  Permet d'afficher un graphe en utilisant différentes méthodes :
 *		  - Affichage des noeuds et des arcs
 *		  - Affichage de la matrice d'adjacence
 *		  Permet d'afficher les cliques maxima d'un graphe
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
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
     * Entrée : sNomFichier, un fichier
     * Nécessite : que le fichier spécifié existe
     * Sortie : Rien
     * Entraîne : L'ouverture du fichier et la lecture des lignes permettant l'affichge du graphe OU
     * (EXCEPTION): le fichier ne s'est pas ouvert correctement
******************************************************************************************/

template <template <class> class TGraph, class TArc>
TGraph<TArc>* Lecturefichier(const string sNomFichier);

/******************************************************************************************
	 * AFFAfficheSommetsEtArcs
	 * --------------------------------------------------------------------------------------
	 * Entrée : PGraphGraphe, un graphe
	 * Nécessite : que le graphe spécifié existe
	 * Sortie : Rien
	 * Entraîne : L'affichage de tous les noeuds et de tous les arcs du graphe spécifié OU
	 * (EXCEPTION): le graphe ne contient aucun sommet
 ******************************************************************************************/

template <class TGraph, class TArc>
void AfficheSommetsEtArcs(TGraph& PGraphGraphe);

/******************************************************************************************
	* AfficheMatriceAdjacence
	* --------------------------------------------------------------------------------------
	* Entrée : PGraphGraphe, un graphe
	* Nécessite : que le graphe spécifié existe
	* Sortie : Rien
	* Entraîne : L'affichage de la matrice d'adjacence du graphe spécifié OU
	* (EXCEPTION): le graphe ne contient aucun sommet
******************************************************************************************/

template <class TGraph, class TArc>
void AfficheMatriceAdjacence(TGraph& PGraphGraphe);

/******************************************************************************************
	* AfficherCliquesMaxima
	* --------------------------------------------------------------------------------------
	* Entrée : PGraphGraphe, un graphe
	* Nécessite : que le graphe spécifié existe
	* Sortie : Rien
	* Entraîne : L'affichage des différentes cliques maxima du graphe
******************************************************************************************/

template <class TGraph, class TArc>
void AfficheCliquesMaxima(TGraph& TGraphGraphe);

#include "FonctionsExternes.th"

#endif