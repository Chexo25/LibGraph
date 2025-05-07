#ifndef PGRAPHORIENT_H
#define PGRAPHORIENT_H

/************************************************************************************************
 * CLASSE : Classe pour manipulations de base d'un graphe orient�
 ************************************************************************************************
 *
 * ROLE : Interface de la classe PGraphOrient
 *		  Elle permet d'effectuer des op�rations de base sur un graphe orient� ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 0.0.6
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 07/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 * 
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
	
	template<class TArc>
	PGraphOrient() {

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

/******************************************************************************************
	 * GORAjouterArc
	 * --------------------------------------------------------------------------------------
	 * Entr�e : CArcGORNewArc, le nouvel arc que l'on veut ajouter au graphe
	 * N�cessite : Qu'il n'existe pas d�j� un arc ayant le m�me sommet de d�part et d'arriv�e
	 * Que le sommet de d�part et le sommet d'arriv�e existent d�j� dans le graphe
	 * Sortie : Rien
	 * Entra�ne : L'arc sp�cifi� est ajout� dans le graphe OU
	 * (EXCEPTION): arc d�j� existant OU
	 * (EXCEPTION): le sommet de d�part n'existe pas OU 
	 * (EXCEPTION): le sommet d'arriv�e n'existe pas
 ******************************************************************************************/

	void GORAjouterArc(TArc* CArcGORNewArc)
	{
		if (find(vGORCArc.begin(), vGORCArc.end(), CArcGORNewArc) != vGORCArc.end()) {
			throw invalid_argument("Arc deja existant !");
		}
		if (GORFindSommet(CArcGORNewArc->ARCGetNumeroD()) == nullptr) {
			throw invalid_argument("Sommet de depart non existant");
		}
		if (GORFindSommet(CArcGORNewArc->ARCGetNumeroA()) == nullptr) {
			throw invalid_argument("Sommet d'arrivee non existant");
		}

		GORFindSommet(CArcGORNewArc->ARCGetNumeroD())->SOMAjoutArcD(CArcGORNewArc);
		GORFindSommet(CArcGORNewArc->ARCGetNumeroA())->SOMAjoutArcA(CArcGORNewArc);

		vGORCArc.push_back(CArcGORNewArc);
	}

/******************************************************************************************
	* GORModifierArc
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

	void GORModifierArc(TArc* CArcGORArc, unsigned int uiGORSommetD, unsigned int uiGORSommetA)
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
		if (find(vGORCSommet.begin(), vGORCSommet.end(), uiGORSommetD) == vGORCSommet.end()) {
			throw invalid_argument("Sommet de depart non existant");
		}
		if (find(vGORCSommet.begin(), vGORCSommet.end(), uiGORSommetA) == vGORCSommet.end()) {
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
	* Entr�e : CArcGORArc, l'arc que l'on souhaite supprimer,
	* N�cessite : Que l'arc sp�cifi� existe
	* Sortie : Rien
	* Entra�ne : L'arc sp�cifi� est supprim� dans le graphe OU
	* (EXCEPTION): arc non existant
******************************************************************************************/

	void GORSupprimerArc(TArc* CArcGORArc)
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
	 * Entr�e : CSommetGORNewSommet, le nouveau sommet que l'on veut ajouter au graphe
	 * N�cessite : Rien
	 * Sortie : Rien
	 * Entra�ne : Le sommet sp�cifi� est ajout� dans le graphe ou
	 * (EXCEPTION): Le num�ro de sommet a d�j� �t� attribu�
 ******************************************************************************************/

	void GORAjouterSommet(PSommet<TArc>* CSommetGORNewSommet)
	{
		unsigned int uiNumSommet = CSommetGORNewSommet->SOMGetNumero();
		if (GORFindSommet(uiNumSommet) != nullptr) {
			throw invalid_argument("Sommet deja existant");
		}
		vGORCSommet.push_back(CSommetGORNewSommet);
	}

/******************************************************************************************
	* GORModifierSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : CSommetGORSommet, le sommet que l'on souhaite modifier, 
			   uiGORNumSommet, le nouveau num�ro du sommet
	* N�cessite : Que le nouveau num�ro de sommet ne soit pas d�j� attribu�
	* Sortie : Rien
	* Entra�ne : Le num�ro du sommet est modifi� OU
	  (EXCEPTION): Le num�ro de sommet a d�j� �t� attribu�
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
	* Entr�e : CSommetGORSommet, le sommet que l'on souhaite supprimer,
	* N�cessite : Que le sommet sp�cifi� existe
	* Que les arcs reli�s � ce sommet soient aussi supprim�s
	* Sortie : Rien
	* Entra�ne : Le sommet sp�cifi� est supprim� dans le graphe OU
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
	* Entr�e : uiGORNumSommetD, le sommet de d�part de l'arc recherch�,
	* uiGORNumSommetA, le sommet d'arriv�e de l'arc recherch�
	* N�cessite : Rien
	* Entra�ne : L'affichage de l'arc recherch� s'il existe, NULL sinon
******************************************************************************************/

	TArc* GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA)
	{
		TArc* ptrTArcArcTrouve = nullptr;
		size_t iIterator = 0;
		do
		{
			if (vGORCArc[iIterator]->ARCGetNumeroD() == uiGORNumSommetD && vGORCArc[iIterator]->ARCGetNumeroA() == uiGORNumSommetA)
			{
				ptrTArcArcTrouve = vGORCArc[iIterator];
			}
			iIterator++;
		} while (iIterator < vGORCArc.size() && ptrTArcArcTrouve == nullptr);
		return ptrTArcArcTrouve;
	}

/******************************************************************************************
	* GORFindSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : uiGORNumSommet, le sommet recherch�,
	* uiGORNumSommet, le num�ro de sommet recherch�
	* N�cessite : Rien
	* Entra�ne : L'affichage du sommet recherch� s'il existe, NULL sinon
******************************************************************************************/

	PSommet<TArc>* GORFindSommet(unsigned int uiGORNumSommet)
	{
		PSommet<TArc>* ptrPSommetSommetTrouve = nullptr;
		size_t iIterator = 0;

		do
		{
			if (vGORCSommet[iIterator]->SOMGetNumero() == uiGORNumSommet)
			{
				ptrPSommetSommetTrouve = vGORCSommet[iIterator];
			}
			iIterator++;
		} while (iIterator < vGORCSommet.size() && ptrPSommetSommetTrouve == nullptr);
		return ptrPSommetSommetTrouve;
	}

/******************************************************************************************
	* GORGetArc
	* --------------------------------------------------------------------------------------
	* Entr�e : Rien
	* Sortie : Le vector vGORCArc
	* Entra�ne : Retourne vGORCArc OU
	* (EXCEPTION): vGORCArc est nulle
******************************************************************************************/

	vector<TArc*> GORGetArc()
	{
		if (vGORCArc.empty())
		{
			throw invalid_argument("Vector vide");
		}
		else
		{
			return vGORCArc;
		}
	}

/******************************************************************************************
	* GORGetSommet
	* --------------------------------------------------------------------------------------
	* Entr�e : Rien
	* Sortie : Le vector vGORCSommet
	* Entra�ne : Retourne vGORCSommet OU
	* (EXCEPTION): vGORCSommet est nulle
******************************************************************************************/

	vector<PSommet<TArc>*> GORGetSommet()
	{
		if (vGORCSommet.empty())
		{
			throw invalid_argument("Vector vide");
		}
		else
		{
			return vGORCSommet;
		}
	}


};

#endif