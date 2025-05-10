#ifndef PAFFICHAGE_H
#define PAFFICHAGE_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour afficher un graphe de diff�rentes mani�res
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PAffichage
 *		  Elle permet d'afficher un graphe en utilisant diff�rentes m�thodes : 
 *		  - Affichage des noeuds et des arcs
 *		  - Affichage de la matrice d'adjacence
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 10/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
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
	 * Entr�e : PGraphOrientAFFGraphe, un graphe orient�
	 * N�cessite : que le graphe sp�cifi� existe
	 * Sortie : Rien
	 * Entra�ne : L'affichage de tous les noeuds et de tous les arcs du graphe sp�cifi� OU
	 * (EXCEPTION): le graphe ne contient aucun sommet
 ******************************************************************************************/
	
	void AFFAfficheSommetsEtArcs(TGraph& TGraphAFFGraphe)
	{
		vector<PSommet<TArc>*> vSommet = TGraphAFFGraphe.GORGetSommet();
		vector<TArc*> vArc = TGraphAFFGraphe.GORGetArc();
		size_t stSizevArc = vArc.size();
		
		printf("voici la liste des sommets du graphe :\n");

		//Si le type n'est pas un graphe, le getter ne sera pas trouv�
		if (vSommet.empty()) 
		{
			throw logic_error("Le graphe ne contient aucun sommet");
		}
		if (vArc.empty()) 
		{
			throw logic_error("Le graphe ne contient aucun arc");
		}
		size_t stSizevSommet = vSommet.size();
		for (size_t stIndex = 0; stIndex < stSizevSommet; stIndex++)
		{
			cout << vSommet[stIndex]->SOMGetNumero() << "\n" << endl;
		}
		printf("Voici la liste des arcs du graphe, "
			   "chaque arc est represente par son sommet de depart et son sommet d'arrivee.\n" 
			   "Dans le cas d'un graphe non oriente, " 
			   "il existera un arc allant du sommet de depart a celui d'arrivee " 
			   "et un allant du sommet d'arrivee a celui de depart.\n");
		for (size_t stIndex = 0; stIndex < stSizevArc; stIndex++)
		{
			cout << "Arc" << stIndex << " : " 
			<< vArc[stIndex]->ARCGetNumeroD() << " -> " 
			<< vArc[stIndex]->ARCGetNumeroA() << "\n" << endl;
		}
	}

/******************************************************************************************
	* AFFAfficheMatriceAdjacence
	* --------------------------------------------------------------------------------------
	* Entr�e : PGraphOrientAFFGraphe, un graphe orient�
	* N�cessite : que le graphe sp�cifi� existe
	* Sortie : Rien
	* Entra�ne : L'affichage de la matrice d'adjacence du graphe sp�cifi� OU
	* (EXCEPTION): le graphe ne contient aucun sommet
******************************************************************************************/
	
	void AFFAfficheMatriceAdjacence(TGraph& TGraphAFFGraphe)
	{
		//On r�cup�re les vecteurs contenant les listes d'arcs et de sommets
		vector<TArc*> vArc = TGraphAFFGraphe.GORGetArc();
		vector<PSommet<TArc>*> vSommet = TGraphAFFGraphe.GORGetSommet();
		size_t stNbLignesColonnes = vSommet.size();
		//Si stNbLignesColonnes n'a pas �t� cr�� c'est que le type passe n'est pas un type graphe et le getter ne sera pas trouv�
		if (vSommet.empty()) {
			throw logic_error("Le graphe ne contient aucun sommet");
		}
		if (vArc.empty()) {
			throw logic_error("Le graphe ne contient aucun arc");
		}

		//On associe un index � un num�ro de sommet dans la matrice, 
		//afin que les num�ros de sommets puissent �tre diff�rents des index de colonnes de la matric
		unordered_map<unsigned int, int> unIndexMap;
		for (int stIndex = 0; stIndex < stNbLignesColonnes; ++stIndex) {
			unIndexMap[vSommet[stIndex]->SOMGetNumero()] = stIndex;
		}	

		//On remplit la matrice de 0, et on met des 1 la ou il y a bien un arc entre les sommets
		vector<vector<unsigned int>> vvuiMatrice(stNbLignesColonnes, vector<unsigned int>(stNbLignesColonnes, 0));
		for (size_t stIndex = 0; stIndex < vArc.size(); ++stIndex) {
			TArc* TArcArc = vArc[stIndex];
			size_t stIndexLigne = unIndexMap[TArcArc->ARCGetNumeroD()];
			size_t stIndexColonne = unIndexMap[TArcArc->ARCGetNumeroA()];
			vvuiMatrice[stIndexLigne][stIndexColonne] = 1;
		}

		//Affichage console de la matrice
		cout << "\n    ";

		for (PSommet<TArc>* sommet : vSommet)
		{
			cout << setw(4) << sommet->SOMGetNumero();
		}

		cout << "\n    ";

		for (int i = 0; i < stNbLignesColonnes; ++i)
		{
			cout << "----";
		}

		cout << "\n";

		for (int i = 0; i < stNbLignesColonnes; ++i)
		{
			cout << setw(3) << vSommet[i]->SOMGetNumero() << "|";
			for (int j = 0; j < stNbLignesColonnes; ++j)
			{
				cout << setw(4) << vvuiMatrice[i][j];
			}
			cout << "\n";
		}
	}
};

#endif