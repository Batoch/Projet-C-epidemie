//
// Created by Baptiste on 25/03/2019.
//

#include "CreerGraph.h"


void creerGraph(int taille){
    FILE *fp;
    fp = fopen("graph.txt", "w");
    fputs("test",fp);
    fputs((const char *) (taille * taille), fp);                                          //nombre de sommets
    fputs((const char *) (2 * taille * taille - 2 * (taille - 1)), fp);                            //nombre d'arcs
    for (int i = 1; i <= taille; ++i) {                                //i represente la i eme personne du graph
        int voisin[4] = {i-taille, i+1, i+taille, i-1};                      //indice du voisin: haut, droite, bas, gauche

        if(i<taille){
            voisin[0]=0;                                                //Si la ieme personne fait parti de la premiere ligne, alors elle n'a pas de voisin en haut
        }
        if(i>taille*taille-taille){                                     //Si la ieme personne est sur la derniere ligne
            voisin[2]=0;
        }
        if(taille%i==0){                                                //Si sur la colonne de droite
            voisin[1]=0;
        }
        if(taille%(i+1)==0){                                            //Si sur la colonne de gauche
            voisin[3]=0;
        }
        fputs("\n", fp);
        fputs((const char *) voisin, fp);
    }
    fclose(fp);
    return 0;

}