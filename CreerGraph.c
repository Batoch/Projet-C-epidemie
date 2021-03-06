//
// Created by Baptiste on 25/03/2019.
//

#include "CreerGraph.h"


void creerGraph(int taille){
    int poids = 0;
    FILE *fp;
    fp = fopen("graph.txt", "w");
    fprintf(fp, "%d\n", taille*taille);                                 //nombre de sommets
    fprintf(fp, "%d\n", 4*2 + 3*(taille-2)*4 + (taille-2)*(taille-2)*4);        //nombre d'arcs
    for (int i = 1; i <= taille*taille; ++i) {                                 //i represente la i eme cell du graph
        int voisin[4] = {i-taille, i+1, i+taille, i-1};                 //indice du voisin: haut, droite, bas, gauche

        if(i<=taille){                                                  //Si la ieme cell fait parti de la premiere ligne, alors elle n'a pas de voisin en haut
            voisin[0]=0;
        }
        if(i>=taille*taille-taille){                                    //Si la ieme cell est sur la derniere ligne
            voisin[2]=0;
        }
        if(i%(taille)==0){                                              //Si sur la colonne de droite
            voisin[1]=0;
        }
        if(i%(taille)==1){                                              //Si sur la colonne de gauche
            voisin[3]=0;
        }



        if(voisin[0]!=0){
            fprintf(fp, "%d %d %d\n", i, voisin[0], poids);
        }
        if(voisin[1]!=0){
            fprintf(fp, "%d %d %d\n", i, voisin[1], poids);
        }
        if(voisin[2]!=0){
            fprintf(fp, "%d %d %d\n", i, voisin[2], poids);
        }
        if(voisin[3]!=0){
            fprintf(fp, "%d %d %d\n", i, voisin[3], poids);
        }
    }
    fclose(fp);
}