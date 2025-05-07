#ifndef CSOMMET_H
#define CSOMMET_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe permettant de d�finir des sommets
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PSommet
 *        Ce paton de classe permet de d�finir des sommets
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
			delete arc;  //Supprime chaque arc de d�part
		}
		vSOMArcD.clear();
		for (TArc* arc : vSOMArcA) {
			delete arc;  //Supprime chaque arc d'arriv�e
		}
		vSOMArcA.clear();
	}

	//METHODES
	/******************************************************************************************
	 * SOMGetNumero
	 * --------------------------------------------------------------------------------------
	 * Entr�e : Aucune
	 * N�cessite : Que le Sommet est un num�ro (entier positif)
	 * Sortie : Un entier : Le num�ro du Sommet
	 * Entra�ne : Un entier est renvoy�
	 ******************************************************************************************/
	
	unsigned int SOMGetNumero()
	{
		return uiSOMNumero;
	}

	/******************************************************************************************
	 * SOMSetNumero
	 * --------------------------------------------------------------------------------------
	 * Entr�e : uiNumero, Le nouveau num�ro du Sommet
	 * N�cessite : Que le num�ro entr�, soit un entier positif
	 * Sortie : Aucune
	 * Entra�ne : Le num�ro du Sommet est mis � jour OU
	 * (EXCEPTION): La valeur entr�e n'est pas valide
	 ******************************************************************************************/
	
	void SOMSetNumero(unsigned int uiSOMNewNumero)
	{
		uiSOMNumero = uiSOMNewNumero;
	}

	//Accesseur de vSOMArcD
	/******************************************************************************************
	 * SOMAjoutArcD
	 * --------------------------------------------------------------------------------------
	 * Entr�e : NewArc, le pointeur de l'Arc � ajouter
	 * N�cessite : Que NewArc ne soit pas null
	 * Sortie : Aucune
	 * Entra�ne : L'ajout du pointeur NewArc � vSOMArcD OU
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
	 * Entr�e : Aucune
	 * N�cessite : Que vSOMArcD ne soit pas nulle
	 * Sortie : Le vector vSOMArcD
	 * Entra�ne : Retourne vSOMArcD OU
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
	 * Entr�e : Arc, le pointeur de l'Arc � supprimer
	 * N�cessite : Que Arc ne soit pas null et pr�sent dans vSOMArcD
	 * Sortie : Aucune
	 * Entra�ne : La suppression du pointeur Arc de vSOMArcD OU
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
	 * Entr�e : NewArc, le pointeur de l'Arc � ajouter
	 * N�cessite : Que NewArc ne soit pas null
	 * Sortie : Aucune
	 * Entra�ne : L'ajout du pointeur NewArc � vSOMArcA OU
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
	 * Entr�e : Aucune
	 * N�cessite : Que vSOMArcA ne soit pas nulle
	 * Sortie : Le vector vSOMArcA
	 * Entra�ne : Retourne vSOMArcA OU
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
	 * Entr�e : Arc, le pointeur de l'Arc � supprimer
	 * N�cessite : Que Arc ne soit pas null et pr�sent dans vSOMArcA
	 * Sortie : Aucune
	 * Entra�ne : La suppression du pointeur Arc de vSOMArcA OU
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