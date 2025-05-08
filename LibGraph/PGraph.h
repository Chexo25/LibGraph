#ifndef PGRAPH_H
#define PGRAPH_H

/************************************************************************************************
 * CLASSE : Classe pour manipulations de base d'un graphe non orient�
 ************************************************************************************************
 *
 * ROLE : Interface de la classe PGraph
 *		  Elle permet d'effectuer des op�rations de base sur un graphe non orient� ainsi que sur ses arcs et sommets.
 *
 ************************************************************************************************
 * VERSION : 0.0.6
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 07/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 *
 ************************************************************************************************/

#include "PGraphOrient.h"

template <class TArc, template <class> class TSommet>
class PGraph : public PGraphOrient<TArc, TSommet<TArc>>
{
private:
	vector<TArc*> vGRACArc;
	vector<TSommet<TArc>*> vGRACSommet;
};
//TODO : FAIRE CE PATRON DE CLASSE
#endif