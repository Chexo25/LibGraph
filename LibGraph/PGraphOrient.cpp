#include "PGraphOrient.h"

template<class TArc, class TSommet>
void PGraphOrient<TArc, TSommet>::GORAjouterArc(TArc* CArcGORNewArc)
{
	if (find(vGORCArc.begin(), vGORCArc.end(), CArcGORNewArc) != vGORCArc.end()) {
		throw invalid_argument("Arc non existant !");
	}
	if (find(vGORCSommet.begin(), vGORCSommet.end(), CArgGORNewArc.ARCGetNumeroD()) != vGORCSommet.end()) {
		throw invalid_argument("Sommet de départ non existant");
	}
	if (find(vGORCSommet.begin(), vGORCSommet.end(), CArgGORNewArc.ARCGetNumeroA()) != vGORCSommet.end()) {
		throw invalid_argument("Sommet d'arrivée non existant");
	}
	vGORCArc.push_back(*CArcGORNewArc);
}

template<class TArc, class TSommet>
void PGraphOrient<TArc, TSommet>::GORModifierArc(TArc* CArcGORArc, unsigned int uiGORSommetD, unsigned int uiGORSommetA) 
{

}

template<class TArc, class TSommet>
void PGraphOrient<TArc, TSommet>::GORSupprimerArc(TArc* CArcGORArc)
{

}

template<class TArc, class TSommet>
void PGraphOrient<TArc, TSommet>::GORAjouterSommet(TSommet* CSommetGORNewSommet)
{

}

template<class TArc, class TSommet>
void PGraphOrient<TArc, TSommet>::GORModifierSommet(TSommet* CSommetGORSommet, unsigned int uiGORNumSommet)
{

}

template<class TArc, class TSommet>
void PGraphOrient<TArc, TSommet>::GORSupprimerSommet(TSommet* CSommetGORSommet)
{

}

template<class TArc, class TSommet>
TArc* PGraphOrient<TArc, TSommet>::GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA)
{
	TArc* ptrTArcArcTrouve = nullptr
	for (int iIterator = 0; iIterator < vGORCArc.size; iIterator++)
	{
		if (vGORCArc[iIterator].ARCGetNumeroD() == uiGORNumSommetD && vGORCArc[iIterator].ARCGetNumeroA() == uiGORNumSommetA)
		{
			ptrTArcArcTrouve = vGORCArc[iIterator];
		}
	}
	return ptrTArcArcTrouve;
}

template<class TArc, class TSommet>
TSommet* PGraphOrient<TArc, TSommet>::GORFindSommet(unsigned int uiGORNumSommet)
{
	return nullptr;
}

//To do, la fonction juste au dessus, findsommet
/// TO DO ajouter des getter sur les listes (vector) d'arc et de sommet





