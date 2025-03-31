#include "CGraphOrient.h"

void CGraphOrient::GORAjouterArc(CArc CArcGORNewArc) {
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

void CGraphOrient::GORModifierArc(CArc CArcGORArc, unsigned int uiGORSommetD, unsigned int uiGORSommetA) {
	CArcGORArc.ARCGetNumeroD = uiGORSommetD;
	CArcGORArc.ARCGetNumeroA = uiGORSommetA;
}

void CGraphOrient:: GORSupprimerArc(CArc CArcGORArc) {

}

void CGraphOrient::GORAjouterSommet(CSommet CSommetGORNewSommet) {

}

void CGraphOrient::GORModifierSommet(CSommet CSommetGORSommet, unsigned int uiGORNumSommet) {

}

void CGraphOrient::GORSupprimerSommet(CSommet CSommetGORSommet) {

}

CArc CGraphOrient::GORFindArc(unsigned int uiGORNumSommetD, unsigned int uiGORNumSommetA) {

}

CSommet CGraphOrient::GORFindSommet(unsigned int uiGORNumSommet) {

}






