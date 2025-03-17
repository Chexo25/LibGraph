#ifndef CSOMMET_H
#define CSOMMET_H

/************************************************************************************************
 * CLASSE : Classe pour définir des sommets
 ************************************************************************************************
 *
 * ROLE : Interface de la classe CSommet
 *        Cette classe permet de définir des sommets
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
	 * Entrée : Aucune
	 * Nécessite : Que le Sommet est un numéro (entier positif)
	 * Sortie : Un entier : Le numéro du Sommet
	 * Entraîne : Un entier est renvoyé OU 
	 * (EXCEPTION): Le Sommet n'a pas de numéro valide
	 ******************************************************************************************/
	unsigned int SOMGetNumero();

	/******************************************************************************************
	 * SOMSetNumero
	 * --------------------------------------------------------------------------------------
	 * Entrée : uiNumero, Le nouveau numéro du Sommet
	 * Nécessite : Que le numéro entré, soit un entier positif)
	 * Sortie : Aucune
	 * Entraîne : Le numéro du Sommet est mis à jour OU
	 * (EXCEPTION): La valeur entrée n'est pas valide
	 ******************************************************************************************/
	void SOMSetNumero(unsigned int uiNumero);

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
	void SOMAjoutArcD(CArc* NewArc);
	/******************************************************************************************
	 * SOMGetArcD
	 * --------------------------------------------------------------------------------------
	 * Entrée : Aucune
	 * Nécessite : Que vSOMArcD ne soit pas nulle
	 * Sortie : Le vector vSOMArcD
	 * Entraîne : Retourne vSOMArcD OU
	 * (EXCEPTION): vSOMArcD est nulle
	 ******************************************************************************************/
	vector<CArc*> SOMGetArcD();
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
	void SOMSupprArcD(CArc* Arc);

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
	void SOMAjoutArcA(CArc* NewArc);
	/******************************************************************************************
	 * SOMGetArcA
	 * --------------------------------------------------------------------------------------
	 * Entrée : Aucune
	 * Nécessite : Que vSOMArcA ne soit pas nulle
	 * Sortie : Le vector vSOMArcA
	 * Entraîne : Retourne vSOMArcA OU
	 * (EXCEPTION): vSOMArcA est nulle
	 ******************************************************************************************/
	vector<CArc*> SOMGetArcA();
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
	void SOMSupprArcA(CArc* Arc);


};


#endif