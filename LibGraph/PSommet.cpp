#include "PSommet.h"

template<class TArc>
PSommet<TArc>::PSommet(unsigned int uiSOMNewNumero)
{
	uiSOMNumero = uiSOMNewNumero;
}

template<class TArc>
PSommet<TArc>::~PSommet()
{
	for (TArc* arc : vSOMArcD) {
		delete arc;  //Supprime chaque arc de départ
	}
	vSOMArcD.clear();
	for (TArc* arc : vSOMArcA) {
		delete arc;  //Supprime chaque arc d'arrivée
	}
	vSOMArcA.clear();
}

//Accesseur de uiSOMNumero
template<class TArc>
unsigned int PSommet<TArc>::SOMGetNumero()
{
	return uiSOMNumero;
}

template<class TArc>
void PSommet<TArc>::SOMSetNumero(unsigned int uiSOMNewNumero)
{
	uiSOMNumero = uiSOMNewNumero;
}

//Accesseur de vSOMArcD

template<class TArc>
void PSommet<TArc>::SOMAjoutArcD(TArc* ptrTArcSOMNouveauArc)
{
	if (ptrTArcSOMNouveauArc != nullptr)
	{
		vSOMArcD.push_back(ptrTArcSOMNouveauArc);
	}
	else
	{
		throw invalid_argument("Pointeur d'Arc non valide");
	}
}

template<class TArc>
vector<TArc*> PSommet<TArc>::SOMGetArcD()
{
	if (vSOMArcD.empty())
	{
		throw invalid_argument("Vector vide");
	}
	else
	{
		return vSOMArcD;
	}
}

template<class TArc>
void PSommet<TArc>::SOMSupprArcD(TArc* ptrTArcSOMArc)
{
	auto iIterator = find(vSOMArcD.begin(), vSOMArcD.end(), ptrTArcSOMArc);
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
template<class TArc>
void PSommet<TArc>::SOMAjoutArcA(TArc* ptrTArcSOMNouveauArc)
{
	if (ptrTArcSOMNouveauArc != nullptr)
	{
		vSOMArcA.push_back(ptrTArcSOMNouveauArc);
	}
	else
	{
		throw invalid_argument("Pointeur d'Arc non valide");
	}
}

template<class TArc>
vector<TArc*> PSommet<TArc>::SOMGetArcA()
{
	if (vSOMArcA.empty())
	{
		throw invalid_argument("Vector vide");
	}
	else
	{
		return vSOMArcA;
	}
}

template<class TArc>
void PSommet<TArc>::SOMSupprArcA(TArc* ptrTArcSOMArc)
{
	auto iIterator = find(vSOMArcA.begin(), vSOMArcA.end(), ptrTArcSOMArc);
		if (iIterator != vSOMArcA.end())
		{
			vSOMArcA.erase(iIterator);
		}
		else
		{
			throw invalid_argument("Arc non existant dans la liste d'arrivee !");
		}
}