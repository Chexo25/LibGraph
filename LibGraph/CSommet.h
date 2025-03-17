#include <vector>

#include "CArc.h"

using namespace std;

#ifndef CSOMMET_H
#define CSOMMET_H

class CSommet
{
private:
	unsigned int uiSOMNumero;
	vector<CArc> vSOMArcD;
	vector<CArc> vSOMArcA;

public:
	//Constructeur et destructeur
	CSommet(unsigned int uiNumero);
	~CSommet();

	//Accesseur de uiSOMNumero
	unsigned int SOMGetNumero();

	//Accesseur de vSOMArcD

	//Accesseur de vSOMArcA



};


#endif