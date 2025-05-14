#ifndef PCLIQUE_MAXIMA_H
#define PCLIQUE_MAXIMA_H

#include "PSommet.h"
#include "PGraph.h"
#include "Clique.h"
#include <vector>

template <class TArc>
class PClique_max
{

private:
	vector<vector<PSommet<TArc>*>> vvCliques_Max;
	size_t stTailleMaxClique;

public:
	PClique_max();
	~PClique_max();
	void CLIEnuCliqueMax(PGraph<TArc> Graph, vector<PSommet<TArc>*> ListeSommet);
	void CLIResetCliqueMax();

};
#endif

#include "PCliqueMaxima.th"