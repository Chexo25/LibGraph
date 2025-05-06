#include "PGraphOrient.h"

template class PGraphOrient<CArc, PSommet>;

template<class TArc, template <class> class TSommet>
PGraphOrient<TArc, TSommet<TArc>>::PGraphOrient() {

}

template<class TArc, template <class> class TSommet>
PGraphOrient<TArc, TSommet<TArc>>::PGraphOrient(vector<TArc*> vGORCArc, vector<TSommet<TArc>*> vGORCSommet)
{
	this->vGORCArc = vGORCArc;
	this->vGORCSommet = vGORCSommet;
}

template<class TArc, template <class> class TSommet>
PGraphOrient<TArc, TSommet<TArc>>::~PGraphOrient()
{
	vGORCArc.clear();
	vGORCSommet.clear();
}

//Gestion de la liste d'arcs
template<class TArc, template <class> class TSommet>
void PGraphOrient<TArc, TSommet<TArc>>::GORAjouterArc(TArc* CArcGORNewArc)
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

template<class TArc, template <class> class TSommet>
void PGraphOrient<TArc, TSommet<TArc>>::GORModifierArc(TArc* CArcGORArc, unsigned int uiGORSommetD, unsigned int uiGORSommetA)
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

	TSommet<TArc>* ptrTSommetD = GORFindSommet(iNumSommetD);
	TSommet<TArc>* ptrTSommetA = GORFindSommet(iNumSommetA);

	ptrTSommetD->SOMSupprArcD(CArcGORArc);
	ptrTSommetA->SOMSupprArcA(CArcGORArc);

	CArcGORArc->ARCSetNumeroD(uiGORSommetD);
	CArcGORArc->ARCSetNumeroA(uiGORSommetA);

	TSommet<TArc>* ptrTSommetnewD = GORFindSommet(uiGORSommetD);
	TSommet<TArc>* ptrTSommetnewA = GORFindSommet(uiGORSommetA);

	ptrTSommetnewD->SOMAjoutArcD(CArcGORArc);
	ptrTSommetnewA->SOMAjoutArcA(CArcGORArc);

}

template<class TArc, template <class> class TSommet>
void PGraphOrient<TArc, TSommet<TArc>>::GORSupprimerArc(TArc* CArcGORArc)
{
	if (find(vGORCArc.begin(), vGORCArc.end(), CArcGORArc) == vGORCArc.end())
	{
		throw invalid_argument("Arc non present dans le graphe");
	}

	unsigned int iNumSommetD = CArcGORArc->ARCGetNumeroD();
	unsigned int iNumSommetA = CArcGORArc->ARCGetNumeroA();

	TSommet<TArc>* ptrTSommetD = GORFindSommet(iNumSommetD);
	TSommet<TArc>* ptrTSommetA = GORFindSommet(iNumSommetA);

	ptrTSommetD->SOMSupprArcD(CArcGORArc);
	ptrTSommetA->SOMSupprArcA(CArcGORArc);

	auto aIterator = find(vGORCArc.begin(), vGORCArc.end(), CArcGORArc);
	vGORCArc.erase(aIterator);

}


//Gestion de la liste de sommets
template<class TArc, template <class> class TSommet>
void PGraphOrient<TArc, TSommet<TArc>>::GORAjouterSommet(TSommet<TArc>* CSommetGORNewSommet)
{
	unsigned int uiNumSommet = CSommetGORNewSommet->SOMGetNumero();
	if (GORFindSommet(uiNumSommet) != nullptr) {
		throw invalid_argument("Sommet deja existant");
	}
	vGORCSommet.push_back(CSommetGORNewSommet);
}

template<class TArc, template <class> class TSommet>
void PGraphOrient<TArc, TSommet<TArc>>::GORModifierSommet(TSommet<TArc>* CSommetGORSommet, unsigned int uiGORNumSommet)
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

template<class TArc, template <class> class TSommet>
void PGraphOrient<TArc, TSommet<TArc>>::GORSupprimerSommet(TSommet<TArc>* CSommetGORSommet)
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


//Recherche dans les vectors
template<class TArc, template <class> class TSommet>
TArc* PGraphOrient<TArc, TSommet<TArc>>::GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA)
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

template<class TArc, template <class> class TSommet>
TSommet<TArc>* PGraphOrient<TArc, TSommet<TArc>>::GORFindSommet(unsigned int uiGORNumSommet)
{
	TSommet<TArc>* ptrTSommetSommetTrouve = nullptr;
	size_t iIterator = 0;

	do
	{
		if (vGORCSommet[iIterator]->SOMGetNumero() == uiGORNumSommet)
		{
			ptrTSommetSommetTrouve = vGORCSommet[iIterator];
		}
		iIterator++;
	} while (iIterator < vGORCSommet.size() && ptrTSommetSommetTrouve == nullptr);
	return ptrTSommetSommetTrouve;
}


//Accesseurs vector
template<class TArc, template <class> class TSommet>
vector<TArc*> PGraphOrient<TArc, TSommet<TArc>>::GORGetArc()
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

template<class TArc, template <class> class TSommet>
vector<TSommet<TArc>*> PGraphOrient<TArc, TSommet<TArc>>::GORGetSommet()
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




