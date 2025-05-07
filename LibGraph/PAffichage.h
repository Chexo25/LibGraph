#ifndef CAFFICHAGE_H
#define CAFFICHAGE_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour afficher un graphe de différentes manières
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PAffichage
 *		  Elle permet d'afficher un graphe en utilisant différentes méthodes : 
 *		  - Affichage des noeuds et des arcs
 *		  - Affichage de la matrice d'adjacence
 *
 ************************************************************************************************
 * VERSION : 0.0.6
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
 * DATE : 07/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 *
 ************************************************************************************************/
#include "PGraphOrient.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

template <class TGraph, class TArc, class TSommet>
class PAffichage {
	
	//METHODES :

/******************************************************************************************
	 * AFFAfficheSommetsEtArcs
	 * --------------------------------------------------------------------------------------
	 * Entrée : PGraphOrientAFFGraphe, un graphe orienté
	 * Nécessite : que le graphe spécifié existe
	 * Sortie : Rien
	 * Entraîne : L'affichage de tous les noeuds et de tous les arcs du graphe spécifié OU
	 * (EXCEPTION): graphe spécifié non existant
 ******************************************************************************************/
	
	void AFFAfficheSommetsEtArcs(TGraph TGraphAFFGraphe)
	{
		printf("voici la liste des sommets du graphe :\n");
		vector<TSommet*> vSommet = TGraphAFFGraphe.GORGetSommet();
		//Si le type n'est pas un graphe, le getter ne sera pas trouvé
		if (!vSommet) {
			throw invalid_argument("Le type passe pour la classe n'est pas un graphe");
		}
		unsigned int uiSizevSommet = vSommet.size();
		for (unsigned int uiIndex = 0; uiIndex < uiSizevSommet; uiIndex++)
		{
			cout << vSommet[uiIndex] << "\n" << endl;
		}
		printf("voici la liste des arcs du graphe, chaque arc est represente par son sommet de depart et son sommet d'arrivee\n");
		vector<TArc*> vArc = TGraphAFFGraphe.GORGetArc();
		unsigned int uiSizevArc = vArc.size();
		for (unsigned int uiIndex = 0; uiIndex < uiSizevArc; uiIndex++)
		{
			cout << "l'arc" << uiIndex << "est relie aux sommets" << vArc[uiIndex] << "\n" << endl;
		}
	}

/******************************************************************************************
	* AFFAfficheMatriceAdjacence
	* --------------------------------------------------------------------------------------
	* Entrée : PGraphOrientAFFGraphe, un graphe orienté
	* Nécessite : que le graphe spécifié existe
	* Sortie : Rien
	* Entraîne : L'affichage de la matrice d'adjacence du graphe spécifié OU
	* (EXCEPTION): graphe spécifié non existant
******************************************************************************************/
	
	void AFFAfficheMatriceAdjacence(const TGraph& TGraphAFFGraphe)
	{
		//On récupère les vecteurs contenant les listes d'arcs et de sommets
		vector<TArc*> vArc = TGraphAFFGraphe.GORGetArc();
		vector<TSommet> vSommet = TGraphAFFGraphe.GORGetSommet();
		unsigned int nbLignesColonnes = vSommet.size();
		//Si nbLignesColonnes n'a pas été créé c'est que le type passe n'est pas un type graphe et le getter ne sera pas trouvé
		if (!nbLignesColonnes) {
			throw invalid_argument("Le type passe pour la classe de graphe n'est pas le bon");
		}

		//On associe à un numéro de sommet un index pour la matrice
		unordered_map<TSommet, int> indexMap;
		for (unsigned int uiIndex = 0; uiIndex < nbLignesColonnes; ++uiIndex) {
			indexMap[vSommet[uiIndex]] = uiIndex;
		}

		//On remplit la matrice de 0, et on met des 1 la ou il y a bien un arc entre les sommets
		vector<vector<unsigned int>> vvuiMatrice(nbLignesColonnes, vector<unsigned int>(nbLignesColonnes, 0));
		for (unsigned int uiIndex = 0; uiIndex < vArc.size(); ++uiIndex) {
			TArc* TArcArc = vArc[uiIndex];
			unsigned int uiIndexLigne = indexMap[TArcArc.ARCgetSommetD()];
			unsigned int uiIndexColonne = indexMap[TArcArc.ARCgetSommetA()];
			vvuiMatrice[uiIndexLigne][uiIndexColonne] = 1;
		}

		//Affichage de la matrice

		cout << "\n    ";

		for (const TSommet& sommet : vSommet)
		{
			cout << setw(4) << sommet;
		}

		cout << "\n    ";

		for (int i = 0; i < nbLignesColonnes; ++i)
		{
			cout << "----";
		}

		cout << "\n";

		for (int i = 0; i < nbLignesColonnes; ++i)
		{
			cout << setw(3) << vSommet[i] << "|";
			for (int j = 0; j < nbLignesColonnes; ++j)
			{
				cout << setw(4) << vvuiMatrice[i][j];
			}
			cout << "\n";
		}
	}
};

#endif