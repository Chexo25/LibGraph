#ifndef CGRAPHORIENT_H
#define CGRAPHORIENT_H

/************************************************************************************************
 * CLASSE : Classe pour manipulations de base d'un graphe orient�
 ************************************************************************************************
 *
 * ROLE : Interface de la classe CGraphOrient
 *        Cette classe permet de manipuler un graphe orient�
 *		  Elle permet d'effectuer des op�rations de base sur un graphe orient�
 *
 ************************************************************************************************
 * VERSION : 0.0.2
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 17/03/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 * 
 ************************************************************************************************/
#include <vector>
#include "CSommet.h"
#include "CArc.h"
using namespace std;

class CGraphOrient
{
//ATTRIBUTS
private :
	vector<CArc*> vGORCArc;
	vector<CSommet*> vGORCSommet;

//CONSTRUCTEURS ET DESTRUCTEURS
public :
	CGraphOrient();
	CGraphOrient(vector<CArc*> vGORCArc, vector<CArc*> vGORCSommet);
	~CGraphOrient();


//METHODES

/******************************************************************************************
 * GORAjouterCArc
 * --------------------------------------------------------------------------------------
 * Entr�e : CArcGORNewArc, le nouvel arc que l'on veut ajouter au graphe
 * N�cessite : Qu'il n'existe pas d�j� un arc ayant le m�me sommet de d�part et d'arriv�e
 * Que le sommet de d�part et le sommet d'arriv�e existent d�j� dans le graphe
 * Sortie : Rien
 * Entra�ne : L'arc sp�cifi� est ajout� dans le graphe OU
 * (EXCEPTION): arc d�j� existant OU
 * (EXCEPTION): le sommet de d�part  ou d'arriv�e n'existe pas
 ******************************************************************************************/

	void GORAjouterArc(CArc CArcGORNewArc);

/******************************************************************************************
	* GORAjouterCArc
	* --------------------------------------------------------------------------------------
	* Entr�e : CArcGORArc, l'arc que l'on souhaite modifier, 
	* uiGORSommetD, le nouveau sommet de d�part de l'arc,
	* uiGORSommetA, le nouveau sommet d'arriv�e de l'arc.
	* N�cessite : Qu'il n'existe pas d�j� un arc ayant le m�me sommet de d�part et d'arriv�e
	* Que le nouveau sommet de d�part et le sommet d'arriv�e existent d�j� dans le graphe
	* Que le sommet d�arriv�e et de d�part restent diff�rents
	* Sortie : Rien
	* Entra�ne : L'arc sp�cifi� est modifi� dans le graphe OU
	* (EXCEPTION): arc d�j� existant OU
	* (EXCEPTION): le sommet de d�part ou d'arriv�e n'existe pas OU
	* (EXCEPTION) : SommetD et SommetA identiques
******************************************************************************************/

	void GORModifierArc(CArc CArcGORArc, unsigned int uiGORSommetD, unsigned int uiGORSommetA);

	void GORSupprimerArc(CArc CArcGORArc);

	void GORAjouterSommet(CSommet CSommetGORNewSommet);

	void GORModifierSommet(CSommet CSommetGORSommet, unsigned int uiGORNumSommet);

	void GORSupprimerSommet(CSommet CSommetGORSommet);

	CArc GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA);

	CSommet GORFindSommet(unsigned int uiGORNumSommet);
};


#endif

//todo : faire les commentaires tkindt friendly
