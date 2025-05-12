#ifndef CLIQUE_H
#define CLIQUE_H

/************************************************************************************************
 * FICHIER : Permet la vérification des cliques dans un graphe
 ************************************************************************************************
 *
 * ROLE : Retrouver une clique et une clique maximale au sein d'un graphe
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Clément BOURDIER
 * DATE : 12/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
 ************************************************************************************************/
#include "PSommet.h"

#include <vector>

template <typename TArc>
bool isClique(const vector<PSommet<TArc>*>& vSommet);

#include "Clique.th"

#endif