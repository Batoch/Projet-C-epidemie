//
// Created by Baptiste on 25/03/2019.
//

#include "CreerGraph.h"


void creerGraph(int taille){
    FILE *fp;
    fp = fopen("graph.txt", "w");
    fputs(taille*taille, fp);


}