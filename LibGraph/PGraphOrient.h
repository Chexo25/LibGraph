#ifndef PGRAPHORIENT_H
#define PGRAPHORIENT_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour manipulations de base d'un graphe orient�
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PGraphOrient
 *		  Il permet d'effectuer des op�rations de base sur un graphe orient� ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 10/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 ************************************************************************************************/

#include <vector>

#include "PSommet.h"
#include "CArc.h"

using namespace std;

template <class TArc>
class PGraphOrient
{
//ATTRIBUTS
private :
	vector<TArc*> vGORTArc;
	vector<PSommet<TArc>*> vGORPSommet;

//CONSTRUCTEURS ET DESTRUCTEURS
public :

	PGraphOrient<TArc>() 
	{

	}
	PGraphOrient(vector<TArc*> vGORTArc, vector<PSommet<TArc>*> vGORPSommet)
	{
		this->vGORTArc = vGORTArc;
		this->vGORPSommet = vGORPSommet;
	}
	~PGraphOrient()
	{
		vGORTArc.clear();
		vGORPSommet.clear();
	}


//METHODES

	//Getter de vGORTArc
	vector<TArc*>& GORGetvGORTArc() {
		return vGORTArc;
	}

/******************************************************************************************
	 * GORAjouterArc
	 * --------------------------------------------------------------------------------------
	 * Entr�e : TArcGORNewArc, le nouvel arc que l'on veut ajouter au graphe
	 * N�cessite : Qu'il n'existe pas d�j� un arc ayant le m�me sommet de d�part et d'arriv�e
	 * Que le sommet de d�part et le sommet d'arriv�e existent d�j� dans le graphe
	 * Sortie : Rien
	 * Entra�ne : L'arc sp�cifi� est ajout� dans le graphe OU
	 * (EXCEPTION): arc d�j� existant OU
	 * (EXCEPTION): le sommet de d�part n'existe pas OU 
	 * (EXCEPTION): le sommet d'arriv�e n'existe pas
 ******************************************************************************************/

	virtual void GORAjouterArc(TArc* TArcGORNewArc)
	{	
		if (TArcGORNewArc->ARCGetNumeroD() == TArcGORNewArc->ARCGetNumeroA())
		{
			throw invalid_argument("Sommet d'arrivee identique a celui de depart");
		}
		if (GORFindArc(TArcGORNewArc->ARCGetNumeroD(), TArcGORNewArc->ARCGetNumeroA()) != nullptr)
		{
			throw invalid_argument("Arc deja existant !");
		}
		if (GORFindSommet(TArcGORNewArc->ARCGetNumeroD()) == nullptr) 
		{
			throw invalid_argument("Sommet de depart non existant");
		}
		if (GORFindSommet(TArcGORNewArc->ARCGetNumeroA()) == nullptr) 
		{
			throw invalid_argument("Sommet d'arrivee non existant");
		}

		GORFindSommet(TArcGORNewArc->ARCGetNumeroD())->SOMAjoutArcD(TArcGORNewArc);
		GORFindSommet(TArcGORNewArc->ARCGetNumeroA())->SOMAjoutArcA(TArcGORNewArc);

		vGORTArc.push_back(TArcGORNewArc);
	}

/******************************************************************************************
	* GORModifierArc
	* --------------------------------------------------------------------------------------
	* Entr�e : TArcGORArc, l'arc que l'on souhaite modifier, 
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

	virtual void GORModifierArc(TArc* TArcGORArc, unsigned int uiGORSommetD, unsigned int uiGORSommetA)
	{
		if (find(vGORTArc.begin(), vGORTArc.end(), TArcGORArc) == vGORTArc.end())
		{
			throw invalid_argument("Arc non present dans le graphe");
		}
		if (uiGORSommetA == uiGORSommetD)
		{
			throw invalid_argument("Sommet d'arrivee identique a celui de depart");
		}
		if (GORFindArc(uiGORSommetD, uiGORSommetA) != nullptr)
		{
			throw invalid_argument("Arc deja existant");
		}
		if (GORFindSommet(uiGORSommetD) == nullptr) {
			throw invalid_argument("Sommet de depart non existant");
		}
		if (GORFindSommet(uiGORSommetA) == nullptr) {
			throw invalid_argument("Sommet d'arrivee non existant");
		}

		unsigned int iNumSommetD = TArcGORArc->ARCGetNumeroD();
		unsigned int iNumSommetA = TArcGORArc->ARCGetNumeroA();

		PSommet<TArc>* ptrPSommetD = GORFindSommet(iNumSommetD);
		PSommet<TArc>* ptrPSommetA = GORFindSommet(iNumSommetA);

		ptrPSommetD->SOMSupprArcD(TArcGORArc);
		ptrPSommetA->SOMSupprArcA(TArcGORArc);

		TArcGORArc->ARCSetNumeroD(uiGORSommetD);
		TArcGORArc->ARCSetNumeroA(uiGORSommetA);

		PSommet<TArc>* ptrPSommetnewD = GORFindSommet(uiGORSommetD);
		PSommet<TArc>* ptrPSommetnewA = GORFindSommet(uiGORSommetA);

		ptrPSommetnewD->SOMAjoutArcD(TArcGORArc);
		ptrPSommetnewA->SOMAjoutArcA(TArcGORArc);

	}

/******************************************************************************************
	* GORSupprimerArc
	* --------------------------------------------------------------------------------------
	* Entr�e : TArcGORArc, l'arc que l'on souhaite supprimer,
	* N�cessite : Que l'arc sp�cifi� existe
	* Sortie : Rien
	* Entra�ne : L'arc sp�cifi� est supprim� dans le graphe OU
	* (EXCEPTION): arc non existant
******************************************************************************************/

	virtual void GORSupprimerArc(TArc* TArcGORArc)
	{
		if (find(vGORTArc.begin(), vGORTArc.end(), TArcGORArc) == vGORTArc.end())
		{
			throw invalid_argument("Arc non present dans le graphe");
		}

		unsigned int iNumSommetD = TArcGORArc->ARCGetNumeroD();
		unsigned int iNumSommetA = TArcGORArc->ARCGetNumeroA();

		PSommet<TArc>* ptrPSommetD = GORFindSommet(iNumSommetD);
		PSommet<TArc>* ptrPSommetA = GORFindSommet(iNumSommetA);

		ptrPSommetD->SOMSupprArcD(TArcGORArc);
		ptrPSommetA->SOMSupprArcA(TArcGORArc);

		auto aIterator = find(vGORTArc.begin(), vGORTArc.end(), TArcGORArc);
		vGORTArc.erase(aIterator);

	}

/******************************************************************************************
	 * GORAjouterSommet
	 * --------------------------------------------------------------------------------------
	 * Entr�e : PSommetGORNewSommet, le nouveau sommet que l'on veut ajouter au graphe
	 * N�cessite : Rien
	 * Sortie : Rien
	 * Entra�ne : Le sommet sp�cifi� est ajout� dans le graphe ou
	 * (EXCEPTION): Le num�ro de sommet a d�j� �t� attribu�
 ******************************************************************************************/

	void GORAjouterSommet(PSommet<TArc>* PSommetGORNewSommet)
	{
		unsigned int uiNumSommet = PSommetGORNewSommet->SOMGetNumero();
		if (GORFindSommet(uiNumSommet) != nullptr) {
			throw invalid_argument("Sommet deja existant");
		}
		this->vGORPSommet.push_back(PSommetGORNewSommet);
	}

/******************************************************************************************
	* GORModifierSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : PSommetGORSommet, le sommet que l'on souhaite modifier, 
			   uiGORNumSommet, le nouveau num�ro du sommet
	* N�cessite : Que le nouveau num�ro de sommet ne soit pas d�j� attribu�
	* Sortie : Rien
	* Entra�ne : Le num�ro du sommet est modifi� OU
	  (EXCEPTION): Le num�ro de sommet a d�j� �t� attribu�
******************************************************************************************/

	void GORModifierSommet(PSommet<TArc>* PSommetGORSommet, unsigned int uiGORNumSommet)
	{
		if (GORFindSommet(uiGORNumSommet) != nullptr) {
			throw invalid_argument("Sommet deja existant");
		}

		PSommetGORSommet->SOMSetNumero(uiGORNumSommet);

		int iIterator;

		vector<TArc*> vArcD = PSommetGORSommet->SOMGetArcD();
		for (iIterator = 0; iIterator < vArcD.size(); iIterator++)
		{
			vArcD[iIterator]->ARCSetNumeroD(uiGORNumSommet);
		}

		vector<TArc*> vArcA = PSommetGORSommet->SOMGetArcA();
		for (iIterator = 0; iIterator < vArcA.size(); iIterator++)
		{
			vArcA[iIterator]->ARCSetNumeroA(uiGORNumSommet);
		}
	}

/******************************************************************************************
	* GORSupprimerSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : PSommetGORSommet, le sommet que l'on souhaite supprimer,
	* N�cessite : Que le sommet sp�cifi� existe
	* Que les arcs reli�s � ce sommet soient aussi supprim�s
	* Sortie : Rien
	* Entra�ne : Le sommet sp�cifi� est supprim� dans le graphe OU
	* (EXCEPTION): sommet non existant 
******************************************************************************************/

	void GORSupprimerSommet(PSommet<TArc>* PSommetGORSommet)
	{
		if (find(vGORPSommet.begin(), vGORPSommet.end(), PSommetGORSommet) == vGORPSommet.end()) {
			throw invalid_argument("Sommet d'arrivee non existant");
		}

		int iIterator;
		vector<TArc*> vArcD = PSommetGORSommet->SOMGetArcD();
		vector<TArc*> vArcA = PSommetGORSommet->SOMGetArcA();

		for (iIterator = 0; iIterator < vArcD.size(); iIterator++)
		{
			GORSupprimerArc(vArcD[iIterator]);
		}

		for (iIterator = 0; iIterator < vArcA.size(); iIterator++)
		{
			GORSupprimerArc(vArcA[iIterator]);
		}

		auto aIterator = find(vGORPSommet.begin(), vGORPSommet.end(), PSommetGORSommet);
		vGORPSommet.erase(aIterator);
	}

/******************************************************************************************
	* GORFindArc
	* --------------------------------------------------------------------------------------
	* Entr�e : uiGORNumSommetD, le sommet de d�part de l'arc recherch�,
	* uiGORNumSommetA, le sommet d'arriv�e de l'arc recherch�
	* N�cessite : Rien
	* Sortie : Un pointeur sur un type g�n�rique d'arcs
	* Entra�ne : L'affichage de l'arc recherch� s'il existe, NULL sinon OU
	* (EXCEPTION): Liste vide, ce qui renvoie NULL
******************************************************************************************/

	TArc* GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA)
	{
		TArc* ptrTArcArcTrouve = nullptr;
		size_t stIterator = 0;
		if (vGORTArc.empty() == false)
		{
			do
			{
				if (vGORTArc[stIterator]->ARCGetNumeroD() == uiGORNumSommetD && vGORTArc[stIterator]->ARCGetNumeroA() == uiGORNumSommetA)
				{
					ptrTArcArcTrouve = vGORTArc[stIterator];
				}
				stIterator++;
			} while (stIterator < vGORTArc.size() && ptrTArcArcTrouve == nullptr);
		}
		return ptrTArcArcTrouve;
	}

/******************************************************************************************
	* GORFindSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : uiGORNumSommet, le sommet recherch�,
	* uiGORNumSommet, le num�ro de sommet recherch�
	* N�cessite : Rien
	* Sortie : Un pointeur sur un PSommet
	* Entra�ne : L'affichage du sommet recherch� s'il existe, NULL sinon OU
	* (EXCEPTION): Liste vide, ce qui renvoie NULL
******************************************************************************************/

	PSommet<TArc>* GORFindSommet(unsigned int uiGORNumSommet)
	{
		PSommet<TArc>* ptrPSommetSommetTrouve = nullptr;
		size_t stIterator = 0;
		if (vGORPSommet.empty() == false)
		{
			do
			{
				if (vGORPSommet[stIterator]->SOMGetNumero() == uiGORNumSommet)
				{
					ptrPSommetSommetTrouve = vGORPSommet[stIterator];
				}
				stIterator++;
			} while (stIterator < vGORPSommet.size() && ptrPSommetSommetTrouve == nullptr);
		}
		return ptrPSommetSommetTrouve;
	}

/******************************************************************************************
	* GORInverseAllArc
	* --------------------------------------------------------------------------------------
	* Entr�e : Rien
	* N�cessite : D'�tre appel�e sur un graphe orient�
	* Sortie : Rien
	* Entra�ne : L'inversion de tous les arcs du graphe
******************************************************************************************/

	//la m�thode est virtuelle afin d'emp�cher son utilisation sur un PGraph (inutile d'inverser un graphe non orient�)
	virtual void GORInverseAllArc()
	{
		for (PSommet<TArc>* sommet : vGORPSommet)
		{
			// On r�cup�re les arcs � supprimer
			vector<TArc*> vArcD = sommet->SOMGetArcD();
			vector<TArc*> vArcA = sommet->SOMGetArcA();

			for (TArc* arc : vArcD)
			{
				sommet->SOMSupprArcD(arc);
			}
			for (TArc* arc : vArcA)
			{
				sommet->SOMSupprArcA(arc);
			}
		}

		//On garde les anciens arcs pour pouvoir les remplacer
		vector<TArc*> anciensArcs = vGORTArc;

		//On vide le vector d'arcs pour lui donner les arcs inverses
		vGORTArc.clear();
		for (TArc* arc : anciensArcs)
		{
			TArc* arcInverse = arc->ARCArcInverse();

			unsigned int numD = arcInverse->ARCGetNumeroD();
			unsigned int numA = arcInverse->ARCGetNumeroA();

			PSommet<TArc>* sommetD = this->GORFindSommet(numD);
			PSommet<TArc>* sommetA = this->GORFindSommet(numA);

			if (sommetD && sommetA)
			{
				sommetD->SOMAjoutArcD(arcInverse);
				sommetA->SOMAjoutArcA(arcInverse);
				vGORTArc.push_back(arcInverse);
			}
			delete arc; 
		}

	}

/******************************************************************************************
	* GORGetArc
	* --------------------------------------------------------------------------------------
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Le vector vGORTArc
	* Entra�ne : Retourne vGORTArc OU
	* (EXCEPTION): vGORTArc est nulle
******************************************************************************************/

	vector<TArc*> GORGetArc()
	{
		return vGORTArc;
	}

/******************************************************************************************
	* GORGetSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Le vector vGORPSommet
	* Entra�ne : Retourne vGORPSommet OU
	* (EXCEPTION): vGORPSommet est nulle
******************************************************************************************/

	vector<PSommet<TArc>*> GORGetSommet()
	{
		return vGORPSommet;
	}

};

#endif