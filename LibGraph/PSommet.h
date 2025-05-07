#ifndef CSOMMET_H
#define CSOMMET_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe permettant de définir des sommets
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PSommet
 *        Ce paton de classe permet de définir des sommets
 *		  ...
 *
 ************************************************************************************************
 * VERSION : 0.0.6
 * AUTEUR : Corentin BAILLE, Clement BOURDIER
 * DATE : 07/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 *
 ************************************************************************************************/
#include <vector>
#include "CArc.h"

using namespace std;

template<class TArc>
class PSommet
{
private:
	//ATTRIBUTS
	unsigned int uiSOMNumero;
	vector<TArc*> vSOMArcD;
	vector<TArc*> vSOMArcA;

public:
	//CONSTRUCTEUR ET DESTRUCTEUR
	PSommet(unsigned int uiSOMNewNumero)
	{
		uiSOMNumero = uiSOMNewNumero;
	}

	~PSommet()
	{
		for (TArc* arc : vSOMArcD) {
			delete arc;  //Supprime chaque arc de départ
		}
		vSOMArcD.clear();
		for (TArc* arc : vSOMArcA) {
			delete arc;  //Supprime chaque arc d'arrivée
		}
		vSOMArcA.clear();
	}

	//METHODES
	/******************************************************************************************
	 * SOMGetNumero
	 * --------------------------------------------------------------------------------------
	 * Entrée : Aucune
	 * Nécessite : Que le Sommet est un numéro (entier positif)
	 * Sortie : Un entier : Le numéro du Sommet
	 * Entraîne : Un entier est renvoyé
	 ******************************************************************************************/
	
	unsigned int SOMGetNumero()
	{
		return uiSOMNumero;
	}

	/******************************************************************************************
	 * SOMSetNumero
	 * --------------------------------------------------------------------------------------
	 * Entrée : uiNumero, Le nouveau numéro du Sommet
	 * Nécessite : Que le numéro entré, soit un entier positif
	 * Sortie : Aucune
	 * Entraîne : Le numéro du Sommet est mis à jour OU
	 * (EXCEPTION): La valeur entrée n'est pas valide
	 ******************************************************************************************/
	
	void SOMSetNumero(unsigned int uiSOMNewNumero)
	{
		uiSOMNumero = uiSOMNewNumero;
	}

	//Accesseur de vSOMArcD
	/******************************************************************************************
	 * SOMAjoutArcD
	 * --------------------------------------------------------------------------------------
	 * Entrée : NewArc, le pointeur de l'Arc à ajouter
	 * Nécessite : Que NewArc ne soit pas null
	 * Sortie : Aucune
	 * Entraîne : L'ajout du pointeur NewArc à vSOMArcD OU
	 * (EXCEPTION): Le pointeur n'est pas valide
	 ******************************************************************************************/
	
	void SOMAjoutArcD(TArc* ptrTArcSOMNouveauArc)
	{
		if (ptrTArcSOMNouveauArc != nullptr)
		{
			vSOMArcD.push_back(ptrTArcSOMNouveauArc);
		}
		else
		{
			throw invalid_argument("Pointeur d'Arc non valide");
		}
	}

	/******************************************************************************************
	 * SOMGetArcD
	 * --------------------------------------------------------------------------------------
	 * Entrée : Aucune
	 * Nécessite : Que vSOMArcD ne soit pas nulle
	 * Sortie : Le vector vSOMArcD
	 * Entraîne : Retourne vSOMArcD OU
	 * (EXCEPTION): vSOMArcD est nulle
	 ******************************************************************************************/
	
	vector<TArc*> SOMGetArcD()
	{
		if (vSOMArcD.empty())
		{
			throw invalid_argument("Vector vide");
		}
		else
		{
			return vSOMArcD;
		}
	}

	/******************************************************************************************
	 * SOMSupprArcD
	 * --------------------------------------------------------------------------------------
	 * Entrée : Arc, le pointeur de l'Arc à supprimer
	 * Nécessite : Que Arc ne soit pas null et présent dans vSOMArcD
	 * Sortie : Aucune
	 * Entraîne : La suppression du pointeur Arc de vSOMArcD OU
	 * (EXCEPTION): Le pointeur n'est pas valide OU
	 * (EXCEPTION): Le pointeur n'est pas dans vSOMArcD
	 ******************************************************************************************/
	
	void SOMSupprArcD(TArc* ptrTArcSOMArc)
	{
		auto iIterator = find(vSOMArcD.begin(), vSOMArcD.end(), ptrTArcSOMArc);
		if (iIterator != vSOMArcD.end())
		{
			vSOMArcD.erase(iIterator);
		}
		else
		{
			throw invalid_argument("Arc non existant dans la liste de depart !");
		}
	}

	//Accesseur de vSOMArcA
		/******************************************************************************************
	 * SOMAjoutArcA
	 * --------------------------------------------------------------------------------------
	 * Entrée : NewArc, le pointeur de l'Arc à ajouter
	 * Nécessite : Que NewArc ne soit pas null
	 * Sortie : Aucune
	 * Entraîne : L'ajout du pointeur NewArc à vSOMArcA OU
	 * (EXCEPTION): Le pointeur n'est pas valide
	 ******************************************************************************************/

	void SOMAjoutArcA(TArc* ptrTArcSOMNouveauArc)
	{
		if (ptrTArcSOMNouveauArc != nullptr)
		{
			vSOMArcA.push_back(ptrTArcSOMNouveauArc);
		}
		else
		{
			throw invalid_argument("Pointeur d'Arc non valide");
		}
	}

	/******************************************************************************************
	 * SOMGetArcA
	 * --------------------------------------------------------------------------------------
	 * Entrée : Aucune
	 * Nécessite : Que vSOMArcA ne soit pas nulle
	 * Sortie : Le vector vSOMArcA
	 * Entraîne : Retourne vSOMArcA OU
	 * (EXCEPTION): vSOMArcA est nulle
	 ******************************************************************************************/
	
	vector<TArc*> SOMGetArcA()
	{
		if (vSOMArcA.empty())
		{
			throw invalid_argument("Vector vide");
		}
		else
		{
			return vSOMArcA;
		}
	}

	/******************************************************************************************
	 * SOMSupprArcA
	 * --------------------------------------------------------------------------------------
	 * Entrée : Arc, le pointeur de l'Arc à supprimer
	 * Nécessite : Que Arc ne soit pas null et présent dans vSOMArcA
	 * Sortie : Aucune
	 * Entraîne : La suppression du pointeur Arc de vSOMArcA OU
	 * (EXCEPTION): Le pointeur n'est pas valide OU
	 * (EXCEPTION): Le pointeur n'est pas dans vSOMArcA
	 ******************************************************************************************/
	
	void SOMGetArcA()
	{
		if (vSOMArcA.empty())
		{
			throw invalid_argument("Vector vide");
		}
		else
		{
			return vSOMArcA;
		}
	}


};


#endif