//
// Created by makhl on 25/03/2019.
//

#ifndef PROJET_C_EPIDEMIE_GRAPHE_H
#define PROJET_C_EPIDEMIE_GRAPHE_H

#include <time.h>
#include "pFile.h"

// graphe : defini par son nombre de sommets et un tableau contenant une liste de successeurs pour chaque sommet
// chaque case du tableau contient un pointeur vers un maillon de liste (le premier de la liste, ou NULL si la liste est vide)
typedef struct
{
    int	nb_sommets;
    cell** successeurs;
} Graphe;

void lireGraphe(Graphe* graphe, const char* grapheFileName); // creation du graphe a partir du fichier
void affichage_graphe(Graphe* graphe);  // affichage du graphe pour la matrice caree
void infection(int taille, enum eType* listeEtats);
void forward(Graphe* populationMatrice, enum eType* listeEtats, int taille, float plambda, float pbeta, float pgamma);
void pause(int i);

#endif //PROJET_C_EPIDEMIE_GRAPHE_H
