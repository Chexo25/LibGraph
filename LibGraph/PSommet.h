#ifndef PSOMMET_H
#define PSOMMET_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe permettant de définir des sommets
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PSommet
 *        Ce paton de classe permet de définir des sommets
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
	 * Entrée : Aucune
	 * Nécessite : Que le Sommet est un numéro (entier positif)
	 * Sortie : Un entier : Le numéro du Sommet
	 * Entraîne : Un entier est renvoyé
	 ******************************************************************************************/
	
	unsigned int SOMGetNumero();

	/******************************************************************************************
	 * SOMSetNumero
	 * --------------------------------------------------------------------------------------
	 * Entrée : uiNumero, Le nouveau numéro du Sommet
	 * Nécessite : Que le numéro entré, soit un entier positif
	 * Sortie : Aucune
	 * Entraîne : Le numéro du Sommet est mis à jour OU
	 * (EXCEPTION): La valeur entrée n'est pas valide
	 ******************************************************************************************/
	
	void SOMSetNumero(unsigned int uiSOMNewNumero);

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
	
	void SOMAjoutArcD(TArc* ptrTArcSOMNouveauArc);

	/******************************************************************************************
	 * SOMGetArcD
	 * --------------------------------------------------------------------------------------
	 * Entrée : Aucune
	 * Nécessite : Que vSOMArcD ne soit pas nulle
	 * Sortie : Le vector vSOMArcD
	 * Entraîne : Retourne vSOMArcD OU
	 * (EXCEPTION): vSOMArcD est nulle
	 ******************************************************************************************/
	
	vector<TArc*> SOMGetArcD();	

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
	
	void SOMSupprArcD(TArc* ptrTArcSOMArc);

	/******************************************************************************************
	 * SOMAjoutArcA
	 * --------------------------------------------------------------------------------------
	 * Entrée : NewArc, le pointeur de l'Arc à ajouter
	 * Nécessite : Que NewArc ne soit pas null
	 * Sortie : Aucune
	 * Entraîne : L'ajout du pointeur NewArc à vSOMArcA OU
	 * (EXCEPTION): Le pointeur n'est pas valide
	 ******************************************************************************************/

	void SOMAjoutArcA(TArc* ptrTArcSOMNouveauArc);

	/******************************************************************************************
	 * SOMGetArcA
	 * --------------------------------------------------------------------------------------
	 * Entrée : Aucune
	 * Nécessite : Que vSOMArcA ne soit pas nulle
	 * Sortie : Le vector vSOMArcA
	 * Entraîne : Retourne vSOMArcA OU
	 * (EXCEPTION): vSOMArcA est nulle
	 ******************************************************************************************/
	
	vector<TArc*> SOMGetArcA();

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
	
	void SOMSupprArcA(TArc* ptrTArcSOMArc);

};

#include "PSommet.th"

#endif