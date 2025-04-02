#include "CSommet.h"

//Constructeur et destructeur
CSommet::CSommet(unsigned int uiSOMNewNumero)
{
	uiSOMNumero = uiSOMNewNumero;
}
CSommet::~CSommet()
{
	vSOMArcD.clear();
	delete vSOMArcD;
	vSOMArcA.clear();
	delete vSOMArcA;
}

//Accesseur de uiSOMNumero
unsigned int CSommet::SOMGetNumero()
{
	return uiSOMNumero;
}
void CSommet::SOMSetNumero(unsigned int uiSOMNewNumero)
{
	uiSOMNumero = uiSOMNewNumero;
}

//Accesseur de vSOMArcD
void CSommet::SOMAjoutArcD(CArc* ptrCArcSOMNouveauArc)
{
	if (ptrCArcSOMNouveauArc != nullptr)
	{
		vSOMArcD.push_back(ptrCArcSOMNouveauArc);
	}
	else
	{
		throw invalid_argument("Pointeur d'Arc non valide");
	}
}
vector<CArc*> CSommet::SOMGetArcD()
{
	if (vSOMArcD.empty)
	{
		throw invalid_argument("Vector vide");
	}
	else
	{
		return vSOMArcD;
	}
}
void CSommet::SOMSupprArcD(CArc* ptrCArcSOMArc)
{
	int iIterator = find(vSOMArcD.begin(), vSOMArcD.end(), ptrCArcSOMArc)
	if(iIterator != vSOMArcD.end())
	{
		vSOMArcD.erase(iIterator);
	}
	else
	{
		throw invalid_argument("Arc non existant dans la liste de depart !");
	}
}

//Accesseur de vSOMArcA
void CSommet::SOMAjoutArcA(CArc* ptrCArcSOMNouveauArc)
{
	if (ptrCArcSOMNouveauArc != nullptr)
	{
		vSOMArcA.push_back(ptrCArcSOMNouveauArc);
	}
	else
	{
		throw invalid_argument("Pointeur d'Arc non valide");
	}
}
vector<CArc*> CSommet::SOMGetArcA()
{
	if (vSOMArcA.empty)
	{
		throw invalid_argument("Vector vide");
	}
	else
	{
		return vSOMArcA;
	}
}
void CSommet::SOMSupprArcA(CArc* ptrCArcSOMArc)
{
	int iIterator = find(vSOMArcA.begin(), vSOMArcA.end(), ptrCArcSOMArc)
		if (iIterator != vSOMArcA.end())
		{
			vSOMArcA.erase(iIterator);
		}
		else
		{
			throw invalid_argument("Arc non existant dans la liste d'arrivée !");
		}
}