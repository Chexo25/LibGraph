#include "PGraphOrient.h"


template<class TArc, class TSommet>
PGraphOrient<TArc, TSommet>::PGraphOrient(vector<TArc*> vGORCArc, vector<TSommet*> vGORCSommet)
{
	this->vGORCArc = vGORCArc;
	this->vGORCSommet = vGORCSommet;
}

template<class TArc, class TSommet>
PGraphOrient<TArc, TSommet>::~PGraphOrient()
{
	vGORCArc.clear(); 
	vGORCSommet.clear();
}

//Gestion de la liste d'arcs
template<class TArc, class TSommet>
void PGraphOrient<TArc, TSommet>::GORAjouterArc(TArc* CArcGORNewArc)
{
	if (find(vGORCArc.begin(), vGORCArc.end(), CArcGORNewArc) != vGORCArc.end()) {
		throw invalid_argument("Arc deja existant !");
	}
	if (GORFindSommet(CArcGORNewArc.ARCGetNumeroD()) == nullptr) {
		throw invalid_argument("Sommet de depart non existant");
	}
	if (GORFindSommet(CArcGORNewArc.ARCGetNumeroA()) == nullptr) {
		throw invalid_argument("Sommet d'arrivee non existant");
	}

	GORFindSommet(CArcGORNewArc.ARCGetNumeroD()).SOMAjoutArcD(CArcGORNewArc);
	GORFindSommet(CArcGORNewArc.ARCGetNumeroA()).SOMAjoutArcA(CArcGORNewArc);

	vGORCArc.push_back(CArcGORNewArc);
}

template<class TArc, class TSommet>
void PGraphOrient<TArc, TSommet>::GORModifierArc(TArc* CArcGORArc, unsigned int uiGORSommetD, unsigned int uiGORSommetA) 
{
	if (find(vGORCArc.begin(), vGORCArc.end(), CArcGORArc) == vGORCArc.end())
	{
		throw invalid_argument("Arc non present dans le graphe");
	}
	if (uiGORSommetA == uiGORSommetA)
	{
		throw invalid_argument("Sommet d arrivee identique a celui de depart");
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

	unsigned int iNumSommetD = CArcGORArc.ARCGetNumeroD();
	unsigned int iNumSommetA = CArcGORArc.ARCGetNumeroA();

	TSommet* ptrTSommetD = GORFindSommet(iNumSommetD);
	TSommet* ptrTSommetA = GORFindSommet(iNumSommetA);

	ptrTSommetD.SOMSupprArcD(CArcGORArc);
	ptrTSommetA.SOMSupprArcA(CArcGORArc);

	CArcGORArc.ARCSetNumeroD(uiGORSommetD);
	CArcGORArc.ARCSetNumeroA(uiGORSommetA);

	TSommet* ptrTSommetnewD = GORFindSommet(uiGORSommetD);
	TSommet* ptrTSommetnewA = GORFindSommet(uiGORSommetA);

	ptrTSommetnewD.SOMAjoutArcD(CArcGORArc);
	ptrTSommetnewA.SOMAjoutArcA(CArcGORArc);

}

template<class TArc, class TSommet>
void PGraphOrient<TArc, TSommet>::GORSupprimerArc(TArc* CArcGORArc)
{
	if (find(vGORCArc.begin(), vGORCArc.end(), CArcGORArc) == vGORCArc.end())
	{
		throw invalid_argument("Arc non present dans le graphe");
	}

	unsigned int iNumSommetD = CArcGORArc.ARCGetNumeroD();
	unsigned int iNumSommetA = CArcGORArc.ARCGetNumeroA();

	TSommet* ptrTSommetD = GORFindSommet(iNumSommetD);
	TSommet* ptrTSommetA = GORFindSommet(iNumSommetA);

	ptrTSommetD.SOMSupprArcD(CArcGORArc);
	ptrTSommetA.SOMSupprArcA(CArcGORArc);

	auto aIterator = find(vGORCArc.begin(), vGORCArc.end(), CArcGORArc);
	vGORCArc.erase(aIterator);

}


//Gestion de la liste de sommets
template<class TArc, class TSommet>
void PGraphOrient<TArc, TSommet>::GORAjouterSommet(TSommet* CSommetGORNewSommet)
{
	unsigned int uiNumSommet = CSommetGORNewSommet.SOMGetNumero();
	if (GORFindSommet(uiNumSommet) != nullptr) {
		throw invalid_argument("Sommet deja existant");
	}
	vGORCSommet.push_back(CSommetGORNewSommet);
}

template<class TArc, class TSommet>
void PGraphOrient<TArc, TSommet>::GORModifierSommet(TSommet* CSommetGORSommet, unsigned int uiGORNumSommet)
{
	if (GORFindSommet(uiGORNumSommet) != nullptr) {
		throw invalid_argument("Sommet deja existant");
	}

	CSommetGORSommet.SOMSetNumero(uiGORNumSommet);

	int iIterator;

	vector<TArc*> vArcD = CSommetGORSommet.SOMGetArcD();
	for (iIterator = 0; iIterator < vArcD.size(); iIterator++)
	{
		vArcD[iIterator].ARCSetNumeroD(uiGORNumSommet);
	}

	vector<TArc*> vArcA = CSommetGORSommet.SOMGetArcA();
	for (iIterator = 0; iIterator < vArcA.size(); iIterator++)
	{
		vArcA[iIterator].ARCSetNumeroA(uiGORNumSommet);
	}
}

template<class TArc, class TSommet>
void PGraphOrient<TArc, TSommet>::GORSupprimerSommet(TSommet* CSommetGORSommet)
{
	if (find(vGORCSommet.begin(), vGORCSommet.end(), CSommetGORSommet) == vGORCSommet.end()) {
		throw invalid_argument("Sommet d'arrivee non existant");
	}

	int iIterator;
	vector<TArc*> vArcD = CSommetGORSommet.SOMGetArcD();
	vector<TArc*> vArcA = CSommetGORSommet.SOMGetArcA();

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
template<class TArc, class TSommet>
TArc* PGraphOrient<TArc, TSommet>::GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA)
{
	TArc* ptrTArcArcTrouve = nullptr;
	int iIterator = 0;
	do
	{
		if (vGORCArc[iIterator].ARCGetNumeroD() == uiGORNumSommetD && vGORCArc[iIterator].ARCGetNumeroA() == uiGORNumSommetA)
		{
			ptrTArcArcTrouve = vGORCArc[iIterator];
		}
		iIterator++;
	} while (iIterator < vGORCArc.size && ptrTArcArcTrouve == nullptr);
	return ptrTArcArcTrouve;
}

template<class TArc, class TSommet>
TSommet* PGraphOrient<TArc, TSommet>::GORFindSommet(unsigned int uiGORNumSommet)
{
	TSommet* ptrTSommetSommetTrouve = nullptr;
	int iIterator = 0;

	do 
	{
		if (vGORCSommet[iIterator].SOMGetNumero() == uiGORNumSommet)
		{
			ptrTSommetSommetTrouve = vGORCSommet[iIterator];
		}
		iIterator++;
	} while (iIterator < vGORCSommet.size && ptrTSommetSommetTrouve == nullptr);
	return nullptr;
}


//Accesseurs vector
template<class TArc, class TSommet>
vector<TArc*> PGraphOrient<TArc, TSommet>::GORGetArc()
{
	if (vGORCArc.empty)
	{
		throw invalid_argument("Vector vide");
	}
	else
	{
		return vGORCArc;
	}
}

template<class TArc, class TSommet>
vector<TSommet*> PGraphOrient<TArc, TSommet>::GORGetSommet()
{
	if (vGORCSommet.empty)
	{
		throw invalid_argument("Vector vide");
	}
	else
	{
		return vGORCSommet;
	}
}





//To do constructeur destructeur




