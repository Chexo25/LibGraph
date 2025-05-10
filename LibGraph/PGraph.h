#ifndef PGRAPH_H
#define PGRAPH_H

/************************************************************************************************
 * PATRON DE CLASSE : Patron de classe pour manipulations de base d'un graphe non orienté
 ************************************************************************************************
 *
 * ROLE : Interface du patron de classe PGraph
 *		  Il permet d'effectuer des opérations de base sur un graphe non orienté ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
 * DATE : 10/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 ************************************************************************************************/

#include "PGraphOrient.h"

template <class TArc>
class PGraph : public PGraphOrient<TArc>
{

public:

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
		vector<TArc*>& vTArc = this->GORGetvGORCArc();
		if (CArcGRANewArc->ARCGetNumeroD() == CArcGRANewArc->ARCGetNumeroA())
		{
			throw invalid_argument("Sommets identiques");
		}
		if (GORFindArc(CArcGRANewArc->ARCGetNumeroD(), CArcGRANewArc->ARCGetNumeroA()) != nullptr)
		{
			throw invalid_argument("Arc deja existant !");
		}
		if (this->GORFindSommet(CArcGRANewArc->ARCGetNumeroD()) == nullptr)
		{
			throw invalid_argument("Sommet 1 non existant");
		}
		if (this->GORFindSommet(CArcGRANewArc->ARCGetNumeroA()) == nullptr)
		{
			throw invalid_argument("Sommet 2 non existant");
		}

		this->GORFindSommet(CArcGRANewArc->ARCGetNumeroD())->SOMAjoutArcD(CArcGRANewArc);
		this->GORFindSommet(CArcGRANewArc->ARCGetNumeroA())->SOMAjoutArcA(CArcGRANewArc);

		vTArc.push_back(CArcGRANewArc);

		TArc* TArcGRAArcInverse = CArcGRANewArc->ARCArcInverse();

		this->GORFindSommet(TArcGRAArcInverse->ARCGetNumeroD())->SOMAjoutArcD(TArcGRAArcInverse);
		this->GORFindSommet(TArcGRAArcInverse->ARCGetNumeroA())->SOMAjoutArcA(TArcGRAArcInverse);

		vTArc.push_back(TArcGRAArcInverse);
	}

/******************************************************************************************
	* GORModifierArc redéfinie
	* --------------------------------------------------------------------------------------
	* Entrée : TArcGRAArc, l'arc que l'on souhaite modifier,
	* uiGRASommetD, le nouveau sommet 1 de l'arc,
	* uiGRASommetA, le nouveau sommet 2 de l'arc.
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

	virtual void GORModifierArc(TArc* TArcGRAArc, unsigned int uiGRASommetD, unsigned int uiGRASommetA)
	{
		if (GORFindArc(TArcGRAArc->ARCGetNumeroD(), TArcGRAArc->ARCGetNumeroA()) != nullptr)
		{
			throw invalid_argument("Ancien arc non present dans le graphe");
		}
		if (uiGRASommetD == uiGRASommetA)
		{
			throw invalid_argument("Sommets identiques");
		}
		if (GORFindArc(uiGRASommetA, uiGRASommetD) != nullptr)
		{
			throw invalid_argument("Arc deja existant");
		}
		if (this->GORFindSommet(uiGRASommetA) == nullptr)
		{
			throw invalid_argument("Sommet d'arrive non existant");
		}
		if (this->GORFindSommet(uiGRASommetD) == nullptr)
		{
			throw invalid_argument("Sommet de depart non existant");
		}

		unsigned int uiNumSommetD = TArcGRAArc->ARCGetNumeroD();
		unsigned int uiNumSommetA = TArcGRAArc->ARCGetNumeroA();

		PSommet<TArc>* ptrPSommetD = this->GORFindSommet(uiNumSommetD);
		PSommet<TArc>* ptrPSommetA = this->GORFindSommet(uiNumSommetA);

		ptrPSommetD->SOMSupprArcD(TArcGRAArc);
		ptrPSommetA->SOMSupprArcA(TArcGRAArc);

		TArcGRAArc->ARCSetNumeroD(uiGRASommetA);
		TArcGRAArc->ARCSetNumeroA(uiGRASommetD);

		PSommet<TArc>* ptrPSommetnewD = this->GORFindSommet(uiGRASommetA);
		PSommet<TArc>* ptrPSommetnewA = this->GORFindSommet(uiGRASommetD);

		ptrPSommetnewD->SOMAjoutArcD(TArcGRAArc);
		ptrPSommetnewA->SOMAjoutArcA(TArcGRAArc);

		TArc* TArcGRAArcInverse = GORFindArc(uiNumSommetA, uiNumSommetD);

		uiNumSommetD = TArcGRAArcInverse->ARCGetNumeroD();
		uiNumSommetA = TArcGRAArcInverse->ARCGetNumeroA();

		ptrPSommetD = this->GORFindSommet(uiNumSommetD);
		ptrPSommetA = this->GORFindSommet(uiNumSommetA);

		ptrPSommetD->SOMSupprArcD(TArcGRAArcInverse);
		ptrPSommetA->SOMSupprArcA(TArcGRAArcInverse);

		TArcGRAArcInverse->ARCSetNumeroD(ptrPSommetD->SOMGetNumero());
		TArcGRAArcInverse->ARCSetNumeroA(ptrPSommetA->SOMGetNumero());

		ptrPSommetnewD = this->GORFindSommet(ptrPSommetD->SOMGetNumero());
		ptrPSommetnewA = this->GORFindSommet(ptrPSommetA->SOMGetNumero());

		ptrPSommetnewD->SOMAjoutArcD(TArcGRAArcInverse);
		ptrPSommetnewA->SOMAjoutArcA(TArcGRAArcInverse);
	}


/******************************************************************************************
	* GORSupprimerArc redéfinie
	* --------------------------------------------------------------------------------------
	* Entrée : TArcGRAArc, l'arc que l'on souhaite supprimer,
	* Nécessite : Que l'arc spécifié existe
	* Sortie : Rien
	* Entraîne : L'arc spécifié est supprimé dans le graphe OU
	* (EXCEPTION): arc non existant
******************************************************************************************/

	virtual void GORSupprimerArc(TArc* TArcGRAArc)
	{
		vector<TArc*>& vTArc = this->GORGetvGORCArc();
		if (GORFindArc(TArcGRAArc->ARCGetNumeroD(), TArcGRAArc->ARCGetNumeroA()) == nullptr)
		{
			throw invalid_argument("Arc non present dans le graphe");
		}

		unsigned int uiNumSommetD = TArcGRAArc->ARCGetNumeroD();
		unsigned int uiNumSommetA = TArcGRAArc->ARCGetNumeroA();

		TArc* TArcGRAArcInverse = GORFindArc(uiNumSommetA, uiNumSommetD);

		PSommet<TArc>* ptrPSommetD = this->GORFindSommet(uiNumSommetD);
		PSommet<TArc>* ptrPSommetA = this->GORFindSommet(uiNumSommetA);

		ptrPSommetD->SOMSupprArcD(TArcGRAArc);
		ptrPSommetA->SOMSupprArcA(TArcGRAArc);

		auto aIterator = find(vTArc.begin(), vTArc.end(), TArcGRAArc);
		vTArc.erase(aIterator);

		uiNumSommetD = TArcGRAArcInverse->ARCGetNumeroD();
		uiNumSommetA = TArcGRAArcInverse->ARCGetNumeroA();

		ptrPSommetD = this->GORFindSommet(uiNumSommetD);
		ptrPSommetA = this->GORFindSommet(uiNumSommetA);

		ptrPSommetD->SOMSupprArcD(TArcGRAArcInverse);
		ptrPSommetA->SOMSupprArcA(TArcGRAArcInverse);

		aIterator = find(vTArc.begin(), vTArc.end(), TArcGRAArcInverse);
		vTArc.erase(aIterator);

	}

/******************************************************************************************
	* GORFindArc redéfinie
	* --------------------------------------------------------------------------------------
	* Entrée : uiGRANumSommetD, le premier sommet de l'arc recherché,
	* uiGORNumSommetA, le second sommet de l'arc recherché
	* Nécessite : Rien
	* Entraîne : L'affichage de l'arc recherché s'il existe, NULL sinon OU
	* (EXCEPTION): Liste vide, ce qui renvoie NULL OU
	* (EXCEPTION): Les deux sommets spécifiés sont les mêmes, l'arc ne peut pas exister
******************************************************************************************/

	virtual TArc* GORFindArc(unsigned int uiGRANumSommetD, unsigned int uiGRANumSommetA)
	{
		vector<TArc*>& vTArc = this->GORGetvGORCArc();
		TArc* ptrTArcArcTrouve = nullptr;
		size_t stIterator = 0;
		if (uiGRANumSommetD == uiGRANumSommetA)
		{
			throw invalid_argument("Les deux sommets specifies sont les mêmes, l'arc ne peut pas exister");
		}
		if (vTArc.empty() == false)
		{
			do
			{
				if (((vTArc[stIterator]->ARCGetNumeroD() == uiGRANumSommetD) &&
					(vTArc[stIterator]->ARCGetNumeroA() == uiGRANumSommetA)) ||
					((vTArc[stIterator]->ARCGetNumeroA() == uiGRANumSommetD) &&
						(vTArc[stIterator]->ARCGetNumeroD() == uiGRANumSommetA)))
				{
					ptrTArcArcTrouve = vTArc[stIterator];
				}
				stIterator++;
			} while (stIterator < vTArc.size() && ptrTArcArcTrouve == nullptr);
		}
		return ptrTArcArcTrouve;
	}

/******************************************************************************************
* GORInverseAllArc redéfinie
* --------------------------------------------------------------------------------------
* Entrée : Rien
* Nécessite : D'être appelée sur un graphe orienté
* Entraîne : Un message d'erreur expliquant que cette méthode ne peut être appelée que sur un graphe orienté
******************************************************************************************/

	virtual void GORInverseAllArc()
	{
		throw logic_error("Cette methode ne peut etre appelee que sur un graphe oriente !");
	}

};

#endif