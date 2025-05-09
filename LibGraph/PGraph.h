#ifndef PGRAPH_H
#define PGRAPH_H

/************************************************************************************************
 * CLASSE : Classe pour manipulations de base d'un graphe non orient�
 ************************************************************************************************
 *
 * ROLE : Interface de la classe PGraph
 *		  Elle permet d'effectuer des op�rations de base sur un graphe non orient� ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 09/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 ************************************************************************************************/

#include "PGraphOrient.h"

template <class TArc>
class PGraph : public PGraphOrient<TArc>
{
private:
	/*vector<TArc*> vGRACArc;
	vector<PSommet<TArc>*> vGRACSommet;*/

public:
	/*~PGraph()
	{
		vGRACArc.clear();
		vGRACSommet.clear();
	}*/

	//METHODES

	/******************************************************************************************
		 * GORAjouterArc red�finie
		 * --------------------------------------------------------------------------------------
		 * Entr�e : CArcGRANewArc, le nouvel arc que l'on veut ajouter au graphe
		 * N�cessite : Qu'il n'existe pas d�j� un arc ayant les m�mes sommets 1 et 2
		 * Que les sommets 1 et 2 existent d�j� dans le graphe
		 * Sortie : Rien
		 * Entra�ne : L'arc sp�cifi� est ajout� dans le graphe OU
		 * (EXCEPTION): arc d�j� existant OU
		 * (EXCEPTION): le sommet 1 n'existe pas OU
		 * (EXCEPTION): le sommet 2 n'existe pas
	 ******************************************************************************************/

	virtual void GORAjouterArc(TArc* CArcGRANewArc)
	{
		if (GORFindArc(CArcGRANewArc.ARCGetNumeroD(), CArcGRANewArc->ARCGetNumeroA()) == nullptr &&
			(GORFindArc(CArcGRANewArc.ARCGetNumeroA(), CArcGRANewArc->ARCGetNumeroD()) == nullptr))
		{
			throw invalid_argument("Arc deja existant !");
		}
		if (GORFindSommet(CArcGRANewArc->ARCGetNumeroD()) == nullptr)
		{
			throw invalid_argument("Sommet 1 non existant");
		}
		if (GORFindSommet(CArcGRANewArc->ARCGetNumeroA()) == nullptr)
		{
			throw invalid_argument("Sommet 2 non existant");
		}

		GORFindSommet(CArcGRANewArc->ARCGetNumeroD())->SOMAjoutArcD(CArcGRANewArc);
		GORFindSommet(CArcGRANewArc->ARCGetNumeroA())->SOMAjoutArcA(CArcGRANewArc);

		vGRACArc.push_back(CArcGRANewArc);

		TArc* CArcGRAArcInverse = CArcGRANewArc->ARCArcInverse();

		GORFindSommet(CArcGRAArcInverse->ARCGetNumeroD())->SOMAjoutArcD(CArcGRAArcInverse);
		GORFindSommet(CArcGRAArcInverse->ARCGetNumeroA())->SOMAjoutArcA(CArcGRAArcInverse);

		vGRACArc.push_back(CArcGRAArcInverse);
	}

	/******************************************************************************************
		* GORModifierArc red�finie
		* --------------------------------------------------------------------------------------
		* Entr�e : CArcGRAArc, l'arc que l'on souhaite modifier,
		* uiGRASommet1, le nouveau sommet 1 de l'arc,
		* uiGRASommet2, le nouveau sommet 2 de l'arc.
		* N�cessite : Qu'il n'existe pas d�j� un arc ayant les m�mes sommets 1 et 2
		* Que le premier nouveau sommet et le second nouveau existent d�j� dans le graphe
		* Que le sommet 1 et 2 restent diff�rents
		* Sortie : Rien
		* Entra�ne : L'arc sp�cifi� est modifi� dans le graphe OU
		* (EXCEPTION): ancien arc non present dans le graphe OU
		* (EXCEPTION): arc d�j� existant OU
		* (EXCEPTION): le sommet 1 ou 2 n'existe pas OU
		* (EXCEPTION): sommets 1 et 2 identiques
	******************************************************************************************/

	virtual void GORModifierArc(TArc* CArcGRAArc, unsigned int uiGRASommetD, unsigned int uiGRASommetA)
	{
		if (GORFindArc(CArcGRAArc.ARCGetNumeroD(), CArcGRAArc->ARCGetNumeroA()) == nullptr &&
			(GORFindArc(CArcGRAArc.ARCGetNumeroA(), CArcGRAArc->ARCGetNumeroD()) == nullptr))
		{
			throw invalid_argument("Ancien arc non present dans le graphe");
		}
		if (uiGRASommetD == uiGRASommetA)
		{
			throw invalid_argument("Sommet d arrive et de depart identiques");
		}
		if (GRAFindArc(uiGRASommetA, uiGRASommetD) != nullptr)
		{
			throw invalid_argument("Arc deja existant");
		}
		if (GORFindSommet(uiGRASommetA) == nullptr)
		{
			throw invalid_argument("Sommet d arrive non existant");
		}
		if (GORFindSommet(uiGRASommetD) == nullptr)
		{
			throw invalid_argument("Sommet de depart non existant");
		}

		unsigned int uiNumSommetD = CArcGRAArc->ARCGetNumeroD();
		unsigned int uiNumSommetA = CArcGRAArc->ARCGetNumeroA();

		PSommet<TArc>* ptrPSommetD = GORFindSommet(uiNumSommetD);
		PSommet<TArc>* ptrPSommetA = GORFindSommet(uiNumSommetA);

		uiNumSommetD->SOMSupprArcD(CArcGRAArc);
		uiNumSommetA->SOMSupprArcA(CArcGRAArc);

		CArcGRAArc->ARCSetNumeroD(uiGRASommetA);
		CArcGRAArc->ARCSetNumeroA(uiGRASommetD);

		PSommet<TArc>* ptrPSommetnewD = GORFindSommet(uiGRASommetA);
		PSommet<TArc>* ptrPSommetnewA = GORFindSommet(uiGRASommetD);

		ptrPSommetnewD->SOMAjoutArcD(CArcGRAArc);
		ptrPSommetnewA->SOMAjoutArcA(CArcGRAArc);

		TArc* CArcGRAArcInverse = GORFindArc(uiNumSommetA, uiNumSommetD);

		uiNumSommetD = CArcGRAArcInverse->ARCGetNumeroD();
		uiNumSommetA = CArcGRAArcInverse->ARCGetNumeroA();

		PSommet<TArc>* ptrPSommetD = GORFindSommet(uiNumSommetD);
		PSommet<TArc>* ptrPSommetA = GORFindSommet(uiNumSommetA);

		ptrPSommetD->SOMSupprArcD(CArcGRAArcInverse);
		ptrPSommetA->SOMSupprArcA(CArcGRAArcInverse);

		CArcGRAArcInverse->ARCSetNumeroD(ptrPSommetD);
		CArcGRAArcInverse->ARCSetNumeroA(ptrPSommetA);

		PSommet<TArc>* ptrPSommetnewD = GORFindSommet(ptrPSommetD);
		PSommet<TArc>* ptrPSommetnewA = GORFindSommet(ptrPSommetA);

		ptrPSommetnewD->SOMAjoutArcD(CArcGRAArcInverse); 
		ptrPSommetnewA->SOMAjoutArcA(CArcGRAArcInverse);
	}


	/******************************************************************************************
		* GORSupprimerArc red�finie
		* --------------------------------------------------------------------------------------
		* Entr�e : CArcGORArc, l'arc que l'on souhaite supprimer,
		* N�cessite : Que l'arc sp�cifi� existe
		* Sortie : Rien
		* Entra�ne : L'arc sp�cifi� est supprim� dans le graphe OU
		* (EXCEPTION): arc non existant
	******************************************************************************************/

	virtual void GORSupprimerArc(TArc* CArcGORArc)
	{
		if (GORFindArc(CArcGORArc.ARCGetNumeroD(), CArcGORArc->ARCGetNumeroA()) == nullptr)
		{
			throw invalid_argument("Arc non present dans le graphe");
		}

		unsigned int uiNumSommetD = CArcGORArc->ARCGetNumeroD();
		unsigned int uiNumSommetA = CArcGORArc->ARCGetNumeroA();

		TArc* CArcGRAArcInverse = GORFindArc(uiNumSommetA, uiNumSommetD);

		PSommet<TArc>* ptrPSommetD = GORFindSommet(uiNumSommetD);
		PSommet<TArc>* ptrPSommetA = GORFindSommet(uiNumSommetA);

		ptrPSommetD->SOMSupprArcD(CArcGORArc);
		ptrPSommetA->SOMSupprArcA(CArcGORArc);

		auto aIterator = find(vGORCArc.begin(), vGORCArc.end(), CArcGORArc);
		vGORCArc.erase(aIterator);

		uiNumSommetD = CArcGRAArcInverse->ARCGetNumeroD();
		uiNumSommetA = CArcGRAArcInverse->ARCGetNumeroA();

		ptrPSommetD = GORFindSommet(uiNumSommetD);
		ptrPSommetA = GORFindSommet(uiNumSommetA);

		ptrPSommetD->SOMSupprArcD(CArcGRAArcInverse);
		ptrPSommetA->SOMSupprArcA(CArcGRAArcInverse);

		aIterator = find(vGORCArc.begin(), vGORCArc.end(), CArcGRAArcInverse);
		vGORCArc.erase(aIterator);

	}

};

#endif