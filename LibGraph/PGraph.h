#ifndef PGRAPH_H
#define PGRAPH_H

/************************************************************************************************
 * CLASSE : Classe pour manipulations de base d'un graphe non orienté
 ************************************************************************************************
 *
 * ROLE : Interface de la classe PGraph
 *		  Elle permet d'effectuer des opérations de base sur un graphe non orienté ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
 * DATE : 09/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 ************************************************************************************************/

#include "PGraphOrient.h"

template <class TArc>
class PGraph : public PGraphOrient<TArc>	
{
private:
	vector<TArc*> vGRACArc;
	vector<PSommet<TArc>*> vGRACSommet;

public: 
	~PGraph() 
	{
		vGRACArc.clear();
		vGRACSommet.clear();
	}

//METHODES

/******************************************************************************************
	 * GORAjouterArc redéfinie
	 * --------------------------------------------------------------------------------------
	 * Entrée : CArcGRANewArc, le nouvel arc que l'on veut ajouter au graphe
	 * Nécessite : Qu'il n'existe pas déjà un arc ayant les mêmes sommets 1 et 2
	 * Que les sommets 1 et 2 existent déjà dans le graphe
	 * Sortie : Rien
	 * Entraîne : L'arc spécifié est ajouté dans le graphe OU
	 * (EXCEPTION): arc déjà existant OU
	 * (EXCEPTION): le sommet 1 n'existe pas OU
	 * (EXCEPTION): le sommet 2 n'existe pas
 ******************************************************************************************/

	virtual void GORAjouterArc(TArc* CArcGRANewArc)
	{
		if ((find(vGRACArc.begin(), vGRACArc.end(), CArcGRANewArc) != vGRACArc.end()) ||
			(find(vGRACArc.begin(), vGRACArc.end(), CArcGRANewArc->ARCArcInverse()) != vGRACArc.end()))
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
	}

/******************************************************************************************
	* GORModifierArc redéfinie
	* --------------------------------------------------------------------------------------
	* Entrée : CArcGRAArc, l'arc que l'on souhaite modifier,
	* uiGRASommet1, le nouveau sommet 1 de l'arc,
	* uiGRASommet2, le nouveau sommet 2 de l'arc.
	* Nécessite : Qu'il n'existe pas déjà un arc ayant les mêmes sommets 1 et 2
	* Que le premier nouveau sommet et le second nouveau existent déjà dans le graphe
	* Que le sommet 1 et 2 restent différents
	* Sortie : Rien
	* Entraîne : L'arc spécifié est modifié dans le graphe OU
	* (EXCEPTION): ancien arc non present dans le graphe OU
	* (EXCEPTION): arc déjà existant OU
	* (EXCEPTION): le sommet 1 ou 2 n'existe pas OU
	* (EXCEPTION): sommets 1 et 2 identiques
******************************************************************************************/

	virtual void GORModifierArc(TArc* CArcGRAArc, unsigned int uiGRASommet1, unsigned int uiGRASommet2)
	{
		if ((find(vGRACArc.begin(), vGRACArc.end(), CArcGRAArc) == vGRACArc.end()) &&
			(find(vGRACArc.begin(), vGRACArc.end(), CArcGRAArc.ARCArcInverse()) == vGRACArc.end()))
		{
			throw invalid_argument("Ancien arc non present dans le graphe");
		}
		if (uiGRASommet1 == uiGRASommet2)
		{
			throw invalid_argument("Sommet 1 et 2 identiques");
		}
		if (GRAFindArc(uiGRASommet2, uiGRASommet1) != nullptr)
		{
			throw invalid_argument("Arc deja existant");
		}
		if (find(vGRACSommet.begin(), vGRACSommet.end(), uiGRASommet2) == vGRACSommet.end()) 
		{
			throw invalid_argument("Sommet 2 non existant");
		}
		if (find(vGRACSommet.begin(), vGRACSommet.end(), uiGRASommet1) == vGRACSommet.end()) 
		{
			throw invalid_argument("Sommet 1 non existant");
		}

		unsigned int iNumSommet2 = CArcGRAArc->ARCGetNumeroD();
		unsigned int iNumSommet1 = CArcGRAArc->ARCGetNumeroA();

		PSommet<TArc>* ptrPSommet2 = GORFindSommet(iNumSommet2);
		PSommet<TArc>* ptrPSommet1 = GORFindSommet(iNumSommet1);

		ptrPSommet2->SOMSupprArcD(CArcGRAArc);
		ptrPSommet1->SOMSupprArcA(CArcGRAArc);

		CArcGRAArc->ARCSetNumeroD(uiGRASommet2);
		CArcGRAArc->ARCSetNumeroA(uiGRASommet1);

		PSommet<TArc>* ptrPSommetnewD = GORFindSommet(uiGRASommet2);
		PSommet<TArc>* ptrPSommetnewA = GORFindSommet(uiGRASommet1);

		ptrPSommetnewD->SOMAjoutArcD(CArcGRAArc);
		ptrPSommetnewA->SOMAjoutArcA(CArcGRAArc);
	}

/******************************************************************************************
	* GORFindArc redéfinie
	* --------------------------------------------------------------------------------------
	* Entrée : uiGRANumSommet1, le premier sommet de l'arc recherché,
	* uiGORNumSommet2, le second sommet de l'arc recherché
	* Nécessite : Rien
	* Entraîne : L'affichage de l'arc recherché s'il existe, NULL sinon OU
	* (EXCEPTION): Liste vide, ce qui renvoie NULL OU
	* (EXCEPTION): Les deux sommets spécifiés sont les mêmes, l'arc ne peut pas exister
******************************************************************************************/

	virtual TArc* GORFindArc(unsigned int uiGRANumSommet1, unsigned int uiGRANumSommet2)
	{
		TArc* ptrTArcArcTrouve = nullptr;
		size_t iIterator = 0;
		if (uiGRANumSommet1 == uiGRANumSommet2)
		{
			throw invalid_argument("Les deux sommets spécifiés sont les mêmes, l'arc ne peut pas exister");
		}
		if (vGRACArc.empty() == false)
		{
			do
			{
				if (((vGRACArc[iIterator]->ARCGetNumeroD() == uiGRANumSommet1) && 
					(vGRACArc[iIterator]->ARCGetNumeroA() == uiGRANumSommet2)) ||
					((vGRACArc[iIterator]->ARCGetNumeroA() == uiGRANumSommet1) &&
					(vGRACArc[iIterator]->ARCGetNumeroD() == uiGRANumSommet2)))
				{
					ptrTArcArcTrouve = vGRACArc[iIterator];
				}
				iIterator++;
			} while (iIterator < vGRACArc.size() && ptrTArcArcTrouve == nullptr);
		}
		return ptrTArcArcTrouve;
	}

};

#endif