//
// Created by Baptiste on 31/03/2019.
//

#include "affichage.h"


void afficherMatrice(enum eType* listeEtats, int taille){
    for (int i=0; i< taille; i++){
        for (int j=0; j<taille; j++){
            switch(listeEtats[taille*i+j]) {
                case sain:
                    printf(".");
                    break;
                case malade:
                    printf("*");
                    break;
                case immunise:
                    printf("o");
                    break;
                case mort:
                    printf("x");
                    break;
                default:
                    printf("?");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

