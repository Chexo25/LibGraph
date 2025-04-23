#ifndef CARC_H
#define CARC_H

/************************************************************************************************
 * CLASSE : Classe pour manipulations de base d'un arc dans un graphe
 ************************************************************************************************
 *
 * ROLE : Interface de la classe CArc
 *        Permet de manipuler un arc au sein d'un graphe.
 *		  Elle permet d'effectuer des manipulations de base d'un arc.
 *
 ************************************************************************************************
 * VERSION : 0.0.3
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
 * DATE : 02/04/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 *
 ************************************************************************************************/
#include <iostream>
#include <utility>
using namespace std; 

class CArc
{
//ATTRIBUTS :
private:
	unsigned int uiARCNumeroSommetD;
	unsigned int uiARCNumeroSommetA;

//CONSTRUCTEURS ET DESTRUCTEURS :
public:
	CArc(unsigned int uiARCNumD, unsigned int uiARCNumA);
	~CArc();

//METHODES :

/******************************************************************************************
	 * ARCGetNumeroD
	 * --------------------------------------------------------------------------------------
	 * Entrée : rien
	 * Nécessite : rien
	 * Sortie : Le numéro de départ de l'arc
	 * Entraîne : Le numéro de départ de l'arc est affiché
 ******************************************************************************************/
	
	unsigned int ARCGetNumeroD();

/******************************************************************************************
	* ARCSetNumeroD
	* --------------------------------------------------------------------------------------
	* Entrée : Un numéro de départ
	* Nécessite : rien
	* Sortie : rien
	* Entraîne : Le numéro de départ de l'arc est modifié
******************************************************************************************/

	void ARCSetNumeroD(unsigned int uiARCNum);

/******************************************************************************************
	* ARCGetNumeroA
	* --------------------------------------------------------------------------------------
	* Entrée : rien
	* Nécessite : rien
	* Sortie : Le numéro d'arrivée de l'arc
	* Entraîne : Le numéro d'arrivée de l'arc est affiché
******************************************************************************************/
	
	unsigned int ARCGetNumeroA();

/******************************************************************************************
	* ARCSetNumeroD
	* --------------------------------------------------------------------------------------
	* Entrée : Un numéro d'arrivée
	* Nécessite : rien
	* Sortie : rien
	* Entraîne : Le numéro d'arrivée de l'arc est modifié
******************************************************************************************/
	
	void ARCSetNumeroA(unsigned int uiARCNum);

/******************************************************************************************
	* ARCInverseArc
	* --------------------------------------------------------------------------------------
	* Entrée : rien
	* Nécessite : rien
	* Sortie : rien
	* Entraîne : Le numéro de départ de l'arc devient son numéro d'arrivée et inversement
******************************************************************************************/

	CArc* ARCArcInverse();
};


#endif