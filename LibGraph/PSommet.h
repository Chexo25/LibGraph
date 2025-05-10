#ifndef PSOMMET_H
#define PSOMMET_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe permettant de d�finir des sommets
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PSommet
 *        Ce paton de classe permet de d�finir des sommets
 *		  Il permet des manipulations de base sur un sommet
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEUR : Corentin BAILLE, Clement BOURDIER
 * DATE : 10/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
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
	//CONSTRUCTEURS ET DESTRUCTEUR
	PSommet();
	PSommet(unsigned int uiSOMNewNumero);
	~PSommet();

	//METHODES
	/******************************************************************************************
	 * SOMGetNumero
	 * --------------------------------------------------------------------------------------
	 * Entr�e : Aucune
	 * N�cessite : Que le Sommet est un num�ro (entier positif)
	 * Sortie : Un entier : Le num�ro du Sommet
	 * Entra�ne : Un entier est renvoy�
	 ******************************************************************************************/
	
	unsigned int SOMGetNumero();

	/******************************************************************************************
	 * SOMSetNumero
	 * --------------------------------------------------------------------------------------
	 * Entr�e : uiNumero, Le nouveau num�ro du Sommet
	 * N�cessite : Que le num�ro entr�, soit un entier positif
	 * Sortie : Aucune
	 * Entra�ne : Le num�ro du Sommet est mis � jour OU
	 * (EXCEPTION): La valeur entr�e n'est pas valide
	 ******************************************************************************************/
	
	void SOMSetNumero(unsigned int uiSOMNewNumero);

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
	
	void SOMAjoutArcD(TArc* ptrTArcSOMNouveauArc);

	/******************************************************************************************
	 * SOMGetArcD
	 * --------------------------------------------------------------------------------------
	 * Entr�e : Aucune
	 * N�cessite : Que vSOMArcD ne soit pas nulle
	 * Sortie : Le vector vSOMArcD
	 * Entra�ne : Retourne vSOMArcD OU
	 * (EXCEPTION): vSOMArcD est nulle
	 ******************************************************************************************/
	
	vector<TArc*> SOMGetArcD();	

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
	
	void SOMSupprArcD(TArc* ptrTArcSOMArc);

	/******************************************************************************************
	 * SOMAjoutArcA
	 * --------------------------------------------------------------------------------------
	 * Entr�e : NewArc, le pointeur de l'Arc � ajouter
	 * N�cessite : Que NewArc ne soit pas null
	 * Sortie : Aucune
	 * Entra�ne : L'ajout du pointeur NewArc � vSOMArcA OU
	 * (EXCEPTION): Le pointeur n'est pas valide
	 ******************************************************************************************/

	void SOMAjoutArcA(TArc* ptrTArcSOMNouveauArc);

	/******************************************************************************************
	 * SOMGetArcA
	 * --------------------------------------------------------------------------------------
	 * Entr�e : Aucune
	 * N�cessite : Que vSOMArcA ne soit pas nulle
	 * Sortie : Le vector vSOMArcA
	 * Entra�ne : Retourne vSOMArcA OU
	 * (EXCEPTION): vSOMArcA est nulle
	 ******************************************************************************************/
	
	vector<TArc*> SOMGetArcA();

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
	
	void SOMSupprArcA(TArc* ptrTArcSOMArc);

};

#include "PSommet.th"

#endif