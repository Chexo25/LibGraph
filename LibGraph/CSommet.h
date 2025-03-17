#ifndef CSOMMET_H
#define CSOMMET_H

/************************************************************************************************
 * CLASSE : Classe pour d�finir des sommets
 ************************************************************************************************
 *
 * ROLE : Interface de la classe CSommet
 *        Cette classe permet de d�finir des sommets
 *		  ...
 *
 ************************************************************************************************
 * VERSION : 0.0.2
 * AUTEUR : Corentin BAILLE, Clement BOURDIER
 * DATE : 17/03/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 *
 ************************************************************************************************/
#include <vector>

#include "CArc.h"

using namespace std;

class CSommet
{
private:
	//ATTRIBUTS
	unsigned int uiSOMNumero;
	vector<CArc*> vSOMArcD;
	vector<CArc*> vSOMArcA;

public:
	//CONSTRUCTEUR ET DESTRUCTEUR
	CSommet(unsigned int uiNumero);
	~CSommet();

	//Accesseur de uiSOMNumero
	/******************************************************************************************
	 * SOMGetNumero
	 * --------------------------------------------------------------------------------------
	 * Entr�e : Aucune
	 * N�cessite : Que le Sommet est un num�ro (entier positif)
	 * Sortie : Un entier : Le num�ro du Sommet
	 * Entra�ne : Un entier est renvoy� OU 
	 * (EXCEPTION): Le Sommet n'a pas de num�ro valide
	 ******************************************************************************************/
	unsigned int SOMGetNumero();

	/******************************************************************************************
	 * SOMSetNumero
	 * --------------------------------------------------------------------------------------
	 * Entr�e : uiNumero, Le nouveau num�ro du Sommet
	 * N�cessite : Que le num�ro entr�, soit un entier positif)
	 * Sortie : Aucune
	 * Entra�ne : Le num�ro du Sommet est mis � jour OU
	 * (EXCEPTION): La valeur entr�e n'est pas valide
	 ******************************************************************************************/
	void SOMSetNumero(unsigned int uiNumero);

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
	void SOMAjoutArcD(CArc* NewArc);
	/******************************************************************************************
	 * SOMGetArcD
	 * --------------------------------------------------------------------------------------
	 * Entr�e : Aucune
	 * N�cessite : Que vSOMArcD ne soit pas nulle
	 * Sortie : Le vector vSOMArcD
	 * Entra�ne : Retourne vSOMArcD OU
	 * (EXCEPTION): vSOMArcD est nulle
	 ******************************************************************************************/
	vector<CArc*> SOMGetArcD();
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
	void SOMSupprArcD(CArc* Arc);

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
	void SOMAjoutArcA(CArc* NewArc);
	/******************************************************************************************
	 * SOMGetArcA
	 * --------------------------------------------------------------------------------------
	 * Entr�e : Aucune
	 * N�cessite : Que vSOMArcA ne soit pas nulle
	 * Sortie : Le vector vSOMArcA
	 * Entra�ne : Retourne vSOMArcA OU
	 * (EXCEPTION): vSOMArcA est nulle
	 ******************************************************************************************/
	vector<CArc*> SOMGetArcA();
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
	void SOMSupprArcA(CArc* Arc);


};


#endif