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
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 10/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
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

//METHODES :

/******************************************************************************************
	 * ARCGetNumeroD
	 * --------------------------------------------------------------------------------------
	 * Entr�e : rien
	 * N�cessite : rien
	 * Sortie : Le num�ro de d�part de l'arc
	 * Entra�ne : Le num�ro de d�part de l'arc est affich�
 ******************************************************************************************/
	
	unsigned int ARCGetNumeroD();

/******************************************************************************************
	* ARCSetNumeroD
	* --------------------------------------------------------------------------------------
	* Entr�e : uiARCNum, un num�ro de d�part
	* N�cessite : rien
	* Sortie : rien
	* Entra�ne : Le num�ro de d�part de l'arc est modifi�
******************************************************************************************/

	void ARCSetNumeroD(unsigned int uiARCNum);

/******************************************************************************************
	* ARCGetNumeroA
	* --------------------------------------------------------------------------------------
	* Entr�e : rien
	* N�cessite : rien
	* Sortie : Le num�ro d'arriv�e de l'arc
	* Entra�ne : Le num�ro d'arriv�e de l'arc est affich�
******************************************************************************************/
	
	unsigned int ARCGetNumeroA();

/******************************************************************************************
	* ARCSetNumeroD
	* --------------------------------------------------------------------------------------
	* Entr�e : uiARCNum, un num�ro d'arriv�e
	* N�cessite : rien
	* Sortie : rien
	* Entra�ne : Le num�ro d'arriv�e de l'arc est modifi�
******************************************************************************************/
	
	void ARCSetNumeroA(unsigned int uiARCNum);

/******************************************************************************************
	* ARCInverseArc
	* --------------------------------------------------------------------------------------
	* Entr�e : rien
	* N�cessite : rien
	* Sortie : rien
	* Entra�ne : Le num�ro de d�part de l'arc devient son num�ro d'arriv�e et inversement
******************************************************************************************/

	CArc* ARCArcInverse();
};


#endif