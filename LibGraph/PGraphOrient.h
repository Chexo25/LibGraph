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
	vector<TArc*> vGORCArc;
	vector<PSommet<TArc>*> vGORCSommet;

//CONSTRUCTEURS ET DESTRUCTEURS
public :

	PGraphOrient<TArc>() 
	{

	}
	PGraphOrient(vector<TArc*> vGORCArc, vector<PSommet<TArc>*> vGORCSommet)
	{
		this->vGORCArc = vGORCArc;
		this->vGORCSommet = vGORCSommet;
	}
	~PGraphOrient()
	{
		vGORCArc.clear();
		vGORCSommet.clear();
	}


//METHODES

	//Getter de vGORCArc
	vector<TArc*>& GORGetvGORCArc() {
		return vGORCArc;
	}

/******************************************************************************************
	 * GORAjouterArc
	 * --------------------------------------------------------------------------------------
	 * Entrée : CArcGORNewArc, le nouvel arc que l'on veut ajouter au graphe
	 * Nécessite : Qu'il n'existe pas déjà un arc ayant le même sommet de départ et d'arrivée
	 * Que le sommet de départ et le sommet d'arrivée existent déjà dans le graphe
	 * Sortie : Rien
	 * Entraîne : L'arc spécifié est ajouté dans le graphe OU
	 * (EXCEPTION): arc déjà existant OU
	 * (EXCEPTION): le sommet de départ n'existe pas OU 
	 * (EXCEPTION): le sommet d'arrivée n'existe pas
 ******************************************************************************************/

	virtual void GORAjouterArc(TArc* CArcGORNewArc)
	{	
		if (CArcGORNewArc->ARCGetNumeroD() == CArcGORNewArc->ARCGetNumeroA())
		{
			throw invalid_argument("Sommet d'arrivee identique a celui de depart");
		}
		if (GORFindArc(CArcGORNewArc->ARCGetNumeroD(), CArcGORNewArc->ARCGetNumeroA()) != nullptr)
		{
			throw invalid_argument("Arc deja existant !");
		}
		if (GORFindSommet(CArcGORNewArc->ARCGetNumeroD()) == nullptr) 
		{
			throw invalid_argument("Sommet de depart non existant");
		}
		if (GORFindSommet(CArcGORNewArc->ARCGetNumeroA()) == nullptr) 
		{
			throw invalid_argument("Sommet d'arrivee non existant");
		}

		GORFindSommet(CArcGORNewArc->ARCGetNumeroD())->SOMAjoutArcD(CArcGORNewArc);
		GORFindSommet(CArcGORNewArc->ARCGetNumeroA())->SOMAjoutArcA(CArcGORNewArc);

		vGORCArc.push_back(CArcGORNewArc);
	}

/******************************************************************************************
	* GORModifierArc
	* --------------------------------------------------------------------------------------
	* Entrée : CArcGORArc, l'arc que l'on souhaite modifier, 
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

	virtual void GORModifierArc(TArc* CArcGORArc, unsigned int uiGORSommetD, unsigned int uiGORSommetA)
	{
		if (find(vGORCArc.begin(), vGORCArc.end(), CArcGORArc) == vGORCArc.end())
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

		unsigned int iNumSommetD = CArcGORArc->ARCGetNumeroD();
		unsigned int iNumSommetA = CArcGORArc->ARCGetNumeroA();

		PSommet<TArc>* ptrPSommetD = GORFindSommet(iNumSommetD);
		PSommet<TArc>* ptrPSommetA = GORFindSommet(iNumSommetA);

		ptrPSommetD->SOMSupprArcD(CArcGORArc);
		ptrPSommetA->SOMSupprArcA(CArcGORArc);

		CArcGORArc->ARCSetNumeroD(uiGORSommetD);
		CArcGORArc->ARCSetNumeroA(uiGORSommetA);

		PSommet<TArc>* ptrPSommetnewD = GORFindSommet(uiGORSommetD);
		PSommet<TArc>* ptrPSommetnewA = GORFindSommet(uiGORSommetA);

		ptrPSommetnewD->SOMAjoutArcD(CArcGORArc);
		ptrPSommetnewA->SOMAjoutArcA(CArcGORArc);

	}

/******************************************************************************************
	* GORSupprimerArc
	* --------------------------------------------------------------------------------------
	* Entrée : CArcGORArc, l'arc que l'on souhaite supprimer,
	* Nécessite : Que l'arc spécifié existe
	* Sortie : Rien
	* Entraîne : L'arc spécifié est supprimé dans le graphe OU
	* (EXCEPTION): arc non existant
******************************************************************************************/

	virtual void GORSupprimerArc(TArc* CArcGORArc)
	{
		if (find(vGORCArc.begin(), vGORCArc.end(), CArcGORArc) == vGORCArc.end())
		{
			throw invalid_argument("Arc non present dans le graphe");
		}

		unsigned int iNumSommetD = CArcGORArc->ARCGetNumeroD();
		unsigned int iNumSommetA = CArcGORArc->ARCGetNumeroA();

		PSommet<TArc>* ptrPSommetD = GORFindSommet(iNumSommetD);
		PSommet<TArc>* ptrPSommetA = GORFindSommet(iNumSommetA);

		ptrPSommetD->SOMSupprArcD(CArcGORArc);
		ptrPSommetA->SOMSupprArcA(CArcGORArc);

		auto aIterator = find(vGORCArc.begin(), vGORCArc.end(), CArcGORArc);
		vGORCArc.erase(aIterator);

	}

/******************************************************************************************
	 * GORAjouterSommet
	 * --------------------------------------------------------------------------------------
	 * Entrée : CSommetGORNewSommet, le nouveau sommet que l'on veut ajouter au graphe
	 * Nécessite : Rien
	 * Sortie : Rien
	 * Entraîne : Le sommet spécifié est ajouté dans le graphe ou
	 * (EXCEPTION): Le numéro de sommet a déjà été attribué
 ******************************************************************************************/

	void GORAjouterSommet(PSommet<TArc>* CSommetGORNewSommet)
	{
		unsigned int uiNumSommet = CSommetGORNewSommet->SOMGetNumero();
		if (GORFindSommet(uiNumSommet) != nullptr) {
			throw invalid_argument("Sommet deja existant");
		}
		this->vGORCSommet.push_back(CSommetGORNewSommet);
	}

/******************************************************************************************
	* GORModifierSommet
	* --------------------------------------------------------------------------------------
	* Entrée : CSommetGORSommet, le sommet que l'on souhaite modifier, 
			   uiGORNumSommet, le nouveau numéro du sommet
	* Nécessite : Que le nouveau numéro de sommet ne soit pas déjà attribué
	* Sortie : Rien
	* Entraîne : Le numéro du sommet est modifié OU
	  (EXCEPTION): Le numéro de sommet a déjà été attribué
******************************************************************************************/

	void GORModifierSommet(PSommet<TArc>* CSommetGORSommet, unsigned int uiGORNumSommet)
	{
		if (GORFindSommet(uiGORNumSommet) != nullptr) {
			throw invalid_argument("Sommet deja existant");
		}

		CSommetGORSommet->SOMSetNumero(uiGORNumSommet);

		int iIterator;

		vector<TArc*> vArcD = CSommetGORSommet->SOMGetArcD();
		for (iIterator = 0; iIterator < vArcD.size(); iIterator++)
		{
			vArcD[iIterator]->ARCSetNumeroD(uiGORNumSommet);
		}

		vector<TArc*> vArcA = CSommetGORSommet->SOMGetArcA();
		for (iIterator = 0; iIterator < vArcA.size(); iIterator++)
		{
			vArcA[iIterator]->ARCSetNumeroA(uiGORNumSommet);
		}
	}

/******************************************************************************************
	* GORSupprimerSommet
	* --------------------------------------------------------------------------------------
	* Entrée : CSommetGORSommet, le sommet que l'on souhaite supprimer,
	* Nécessite : Que le sommet spécifié existe
	* Que les arcs reliés à ce sommet soient aussi supprimés
	* Sortie : Rien
	* Entraîne : Le sommet spécifié est supprimé dans le graphe OU
	* (EXCEPTION): sommet non existant 
******************************************************************************************/

	void GORSupprimerSommet(PSommet<TArc>* CSommetGORSommet)
	{
		if (find(vGORCSommet.begin(), vGORCSommet.end(), CSommetGORSommet) == vGORCSommet.end()) {
			throw invalid_argument("Sommet d'arrivee non existant");
		}

		int iIterator;
		vector<TArc*> vArcD = CSommetGORSommet->SOMGetArcD();
		vector<TArc*> vArcA = CSommetGORSommet->SOMGetArcA();

		for (iIterator = 0; iIterator < vArcD.size(); iIterator++)
		{
			GORSupprimerArc(vArcD[iIterator]);
		}

		for (iIterator = 0; iIterator < vArcA.size(); iIterator++)
		{
			GORSupprimerArc(vArcA[iIterator]);
		}

		auto aIterator = find(vGORCSommet.begin(), vGORCSommet.end(), CSommetGORSommet);
		vGORCSommet.erase(aIterator);
	}

/******************************************************************************************
	* GORFindArc
	* --------------------------------------------------------------------------------------
	* Entrée : uiGORNumSommetD, le sommet de départ de l'arc recherché,
	* uiGORNumSommetA, le sommet d'arrivée de l'arc recherché
	* Nécessite : Rien
	* Entraîne : L'affichage de l'arc recherché s'il existe, NULL sinon OU
	* (EXCEPTION): Liste vide, ce qui renvoie NULL
******************************************************************************************/

	TArc* GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA)
	{
		TArc* ptrTArcArcTrouve = nullptr;
		size_t iIterator = 0;
		if (vGORCArc.empty() == false)
		{
			do
			{
				if (vGORCArc[iIterator]->ARCGetNumeroD() == uiGORNumSommetD && vGORCArc[iIterator]->ARCGetNumeroA() == uiGORNumSommetA)
				{
					ptrTArcArcTrouve = vGORCArc[iIterator];
				}
				iIterator++;
			} while (iIterator < vGORCArc.size() && ptrTArcArcTrouve == nullptr);
		}
		return ptrTArcArcTrouve;
	}

/******************************************************************************************
	* GORFindSommet
	* --------------------------------------------------------------------------------------
	* Entrée : uiGORNumSommet, le sommet recherché,
	* uiGORNumSommet, le numéro de sommet recherché
	* Nécessite : Rien
	* Entraîne : L'affichage du sommet recherché s'il existe, NULL sinon OU
	* (EXCEPTION): Liste vide, ce qui renvoie NULL
******************************************************************************************/

	PSommet<TArc>* GORFindSommet(unsigned int uiGORNumSommet)
	{
		PSommet<TArc>* ptrPSommetSommetTrouve = nullptr;
		size_t iIterator = 0;
		if (vGORCSommet.empty() == false)
		{
			do
			{
				if (vGORCSommet[iIterator]->SOMGetNumero() == uiGORNumSommet)
				{
					ptrPSommetSommetTrouve = vGORCSommet[iIterator];
				}
				iIterator++;
			} while (iIterator < vGORCSommet.size() && ptrPSommetSommetTrouve == nullptr);
		}
		return ptrPSommetSommetTrouve;
	}

/******************************************************************************************
	* GORInverseAllArc
	* --------------------------------------------------------------------------------------
	* Entrée : Rien
	* Nécessite : D'être appelée sur un graphe orienté
	* Entraîne : L'inversion de tous les arcs du graphe
******************************************************************************************/

	//la méthode est virtuelle afin d'empêcher son utilisation sur un PGraph (inutile d'inverser un graphe non orienté)
	virtual void GORInverseAllArc()
	{
		for (PSommet<TArc>* sommet : vGORCSommet)
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
		vector<TArc*> anciensArcs = vGORCArc;

		// On vide le vector d'arcs pour lui donner les arcs inverses
		vGORCArc.clear();
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
				vGORCArc.push_back(arcInverse);
			}
			//On supprime l'ancien arc
			delete arc; 
		}

	}

/******************************************************************************************
	* GORGetArc
	* --------------------------------------------------------------------------------------
	* Entrée : Rien
	* Sortie : Le vector vGORCArc
	* Entraîne : Retourne vGORCArc OU
	* (EXCEPTION): vGORCArc est nulle
******************************************************************************************/

	vector<TArc*> GORGetArc()
	{
		return vGORCArc;
	}

/******************************************************************************************
	* GORGetSommet
	* --------------------------------------------------------------------------------------
	* Entrée : Rien
	* Sortie : Le vector vGORCSommet
	* Entraîne : Retourne vGORCSommet OU
	* (EXCEPTION): vGORCSommet est nulle
******************************************************************************************/

	vector<PSommet<TArc>*> GORGetSommet()
	{
		return vGORCSommet;
	}

/******************************************************************************************
	* GORHasSommets
	* --------------------------------------------------------------------------------------
	* Entrée : Rien
	* Sortie : Un booléen
	* Entraîne : Retourne un booléen qui définit si un graphe contient des sommets ou non
******************************************************************************************/

	bool GORHasSommets() const {
		return !vGORCSommet.empty();
	}

/******************************************************************************************
	* GORHasArcs
	* --------------------------------------------------------------------------------------
	* Entrée : Rien
	* Sortie : Un booléen
	* Entraîne : Retourne un booléen qui définit si un graphe contient des arcs ou non
******************************************************************************************/

	bool GORHasArcs() const {
		return !vGORCArc.empty();
	}

};

#endif