#ifndef LECTUREFICHIER_H
#define LECTUREFICHIER_H
/************************************************************************************************
 * FICHIER : Fichier contenant la fonction permettant la lecture d'un fichier
 ************************************************************************************************
 *
 * ROLE : Contenir la fonction permettant de parser un fichier pour retourner un graphe
 *
 ************************************************************************************************
 * VERSION : 1.0.0
 * AUTEURS : Corentin BAILLE, Cl�ment BOURDIER
 * DATE : 20/05/2025
 ************************************************************************************************
 * INCLUSIONS EXTERNES :
************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/******************************************************************************************
     * Lecturefichier
     * --------------------------------------------------------------------------------------
     * Entr�e : sNomFichier, un fichier
     * N�cessite : que le fichier sp�cifi� existe
     * Sortie : Rien
     * Entra�ne : L'ouverture du fichier et la lecture des lignes permettant l'affichge du graphe OU
     * (EXCEPTION): le fichier ne s'est pas ouvert correctement
******************************************************************************************/

template <template <class> class TGraph, class TArc>
TGraph<TArc>* Lecturefichier(const string sNomFichier);

#include "LectureFichier.th"

#endif