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
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
 * DATE : 08/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 *
 ************************************************************************************************/
#include "PGraphOrient.h"
#include "PSommet.h"

#include <unordered_map>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

template <class TGraph, class TArc>
class PAffichage {

public: 

/******************************************************************************************
	 * AFFAfficheSommetsEtArcs
	 * --------------------------------------------------------------------------------------
	 * Entrée : PGraphOrientAFFGraphe, un graphe orienté
	 * Nécessite : que le graphe spécifié existe
	 * Sortie : Rien
	 * Entraîne : L'affichage de tous les noeuds et de tous les arcs du graphe spécifié OU
	 * (EXCEPTION): le graphe ne contient aucun sommet
 ******************************************************************************************/
	
	void AFFAfficheSommetsEtArcs(TGraph& TGraphAFFGraphe)
	{
		printf("voici la liste des sommets du graphe :\n");
		vector<PSommet<TArc>*> vSommet = TGraphAFFGraphe.GORGetSommet();
		//Si le type n'est pas un graphe, le getter ne sera pas trouvé
		if (vSommet.empty()) 
		{
			throw invalid_argument("Le graphe ne contient aucun sommet");
		}
		size_t uiSizevSommet = vSommet.size();
		for (size_t uiIndex = 0; uiIndex < uiSizevSommet; uiIndex++)
		{
			cout << vSommet[uiIndex]->SOMGetNumero() << "\n" << endl;
		}
		printf("voici la liste des arcs du graphe, chaque arc est represente par son sommet de depart et son sommet d'arrivee\n");
		vector<TArc*> vArc = TGraphAFFGraphe.GORGetArc();
		size_t uiSizevArc = vArc.size();
		for (size_t uiIndex = 0; uiIndex < uiSizevArc; uiIndex++)
		{
			cout << "Arc" << uiIndex << " : " 
			<< vArc[uiIndex]->ARCGetNumeroD() << " -> " 
			<< vArc[uiIndex]->ARCGetNumeroA() << "\n" << endl;
		}
	}

/******************************************************************************************
	* AFFAfficheMatriceAdjacence
	* --------------------------------------------------------------------------------------
	* Entrée : PGraphOrientAFFGraphe, un graphe orienté
	* Nécessite : que le graphe spécifié existe
	* Sortie : Rien
	* Entraîne : L'affichage de la matrice d'adjacence du graphe spécifié OU
	* (EXCEPTION): le graphe ne contient aucun sommet
******************************************************************************************/
	
	void AFFAfficheMatriceAdjacence(TGraph& TGraphAFFGraphe)
	{
		//On récupère les vecteurs contenant les listes d'arcs et de sommets
		vector<TArc*> vArc = TGraphAFFGraphe.GORGetArc();
		vector<PSommet<TArc>*> vSommet = TGraphAFFGraphe.GORGetSommet();
		size_t nbLignesColonnes = vSommet.size();
		//Si nbLignesColonnes n'a pas été créé c'est que le type passe n'est pas un type graphe et le getter ne sera pas trouvé
		if (vSommet.empty()) {
			throw invalid_argument("Le graphe ne contient aucun sommet");
		}

		//On associe un index à un numéro de sommet dans la matrice
		unordered_map<unsigned int, int> indexMap;
		for (int uiIndex = 0; uiIndex < nbLignesColonnes; ++uiIndex) {
			indexMap[vSommet[uiIndex]->SOMGetNumero()] = uiIndex;
		}	

		//On remplit la matrice de 0, et on met des 1 la ou il y a bien un arc entre les sommets
		vector<vector<unsigned int>> vvuiMatrice(nbLignesColonnes, vector<unsigned int>(nbLignesColonnes, 0));
		for (size_t uiIndex = 0; uiIndex < vArc.size(); ++uiIndex) {
			TArc* TArcArc = vArc[uiIndex];
			size_t uiIndexLigne = indexMap[TArcArc->ARCGetNumeroD()];
			size_t uiIndexColonne = indexMap[TArcArc->ARCGetNumeroA()];
			vvuiMatrice[uiIndexLigne][uiIndexColonne] = 1;
		}

		//Affichage de la matrice

		cout << "\n    ";

		for (PSommet<TArc>* sommet : vSommet)
		{
			cout << setw(4) << sommet->SOMGetNumero();
		}

		cout << "\n    ";

		for (int i = 0; i < nbLignesColonnes; ++i)
		{
			cout << "----";
		}

		cout << "\n";

		for (int i = 0; i < nbLignesColonnes; ++i)
		{
			cout << setw(3) << vSommet[i]->SOMGetNumero() << "|";
			for (int j = 0; j < nbLignesColonnes; ++j)
			{
				cout << setw(4) << vvuiMatrice[i][j];
			}
			cout << "\n";
		}
	}
};

#endif