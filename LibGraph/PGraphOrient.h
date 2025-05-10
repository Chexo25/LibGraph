#ifndef PGRAPHORIENT_H
#define PGRAPHORIENT_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour manipulations de base d'un graphe orienté
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PGraphOrient
 *		  Il permet d'effectuer des opérations de base sur un graphe orienté ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
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
	 * Entrée : TArcGORNewArc, le nouvel arc que l'on veut ajouter au graphe
	 * Nécessite : Qu'il n'existe pas déjà un arc ayant le même sommet de départ et d'arrivée
	 * Que le sommet de départ et le sommet d'arrivée existent déjà dans le graphe
	 * Sortie : Rien
	 * Entraîne : L'arc spécifié est ajouté dans le graphe OU
	 * (EXCEPTION): arc déjà existant OU
	 * (EXCEPTION): le sommet de départ n'existe pas OU 
	 * (EXCEPTION): le sommet d'arrivée n'existe pas
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
	* Entrée : TArcGORArc, l'arc que l'on souhaite modifier, 
	* uiGORSommetD, le nouveau sommet de départ de l'arc,
	* uiGORSommetA, le nouveau sommet d'arrivée de l'arc.
	* Nécessite : Qu'il n'existe pas déjà un arc ayant le même sommet de départ et d'arrivée
	* Que le nouveau sommet de départ et le sommet d'arrivée existent déjà dans le graphe
	* Que le sommet d’arrivée et de départ restent différents
	* Sortie : Rien
	* Entraîne : L'arc spécifié est modifié dans le graphe OU
	* (EXCEPTION): arc déjà existant OU
	* (EXCEPTION): le sommet de départ ou d'arrivée n'existe pas OU
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
	* Entrée : TArcGORArc, l'arc que l'on souhaite supprimer,
	* Nécessite : Que l'arc spécifié existe
	* Sortie : Rien
	* Entraîne : L'arc spécifié est supprimé dans le graphe OU
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
	 * Entrée : PSommetGORNewSommet, le nouveau sommet que l'on veut ajouter au graphe
	 * Nécessite : Rien
	 * Sortie : Rien
	 * Entraîne : Le sommet spécifié est ajouté dans le graphe ou
	 * (EXCEPTION): Le numéro de sommet a déjà été attribué
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
	* Entrée : PSommetGORSommet, le sommet que l'on souhaite modifier, 
			   uiGORNumSommet, le nouveau numéro du sommet
	* Nécessite : Que le nouveau numéro de sommet ne soit pas déjà attribué
	* Sortie : Rien
	* Entraîne : Le numéro du sommet est modifié OU
	  (EXCEPTION): Le numéro de sommet a déjà été attribué
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
	* Entrée : PSommetGORSommet, le sommet que l'on souhaite supprimer,
	* Nécessite : Que le sommet spécifié existe
	* Que les arcs reliés à ce sommet soient aussi supprimés
	* Sortie : Rien
	* Entraîne : Le sommet spécifié est supprimé dans le graphe OU
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
	* Entrée : uiGORNumSommetD, le sommet de départ de l'arc recherché,
	* uiGORNumSommetA, le sommet d'arrivée de l'arc recherché
	* Nécessite : Rien
	* Sortie : Un pointeur sur un type générique d'arcs
	* Entraîne : L'affichage de l'arc recherché s'il existe, NULL sinon OU
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
	* Entrée : uiGORNumSommet, le sommet recherché,
	* uiGORNumSommet, le numéro de sommet recherché
	* Nécessite : Rien
	* Sortie : Un pointeur sur un PSommet
	* Entraîne : L'affichage du sommet recherché s'il existe, NULL sinon OU
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
	* Entrée : Rien
	* Nécessite : D'être appelée sur un graphe orienté
	* Sortie : Rien
	* Entraîne : L'inversion de tous les arcs du graphe
******************************************************************************************/

	//la méthode est virtuelle afin d'empêcher son utilisation sur un PGraph (inutile d'inverser un graphe non orienté)
	virtual void GORInverseAllArc()
	{
		for (PSommet<TArc>* sommet : vGORPSommet)
		{
			// On récupère les arcs à supprimer
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
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le vector vGORTArc
	* Entraîne : Retourne vGORTArc OU
	* (EXCEPTION): vGORTArc est nulle
******************************************************************************************/

	vector<TArc*> GORGetArc()
	{
		return vGORTArc;
	}

/******************************************************************************************
	* GORGetSommet
	* --------------------------------------------------------------------------------------
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le vector vGORPSommet
	* Entraîne : Retourne vGORPSommet OU
	* (EXCEPTION): vGORPSommet est nulle
******************************************************************************************/

	vector<PSommet<TArc>*> GORGetSommet()
	{
		return vGORPSommet;
	}

};

#endif