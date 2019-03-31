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

void statisaiques(enum eType* listeEtats, int taille, float stats[]){
    int malades = 0, morts = 0, sains = 0, immunises = 0;
    int sujets = taille*taille;

    FILE *fp;
    fp = fopen("statistiques.txt", "w");

    for(int i=0; i< taille*taille; i++){
        switch(listeEtats[i]){
            case sain:
                sains++;
                break;
            case malade:
                malades++;
                break;
            case immunise:
                immunises++;
                break;
            case mort:
                morts++;
                break;
        }
    }

    fprintf(fp, "Statistiques de la simulation: \n\n");
    fprintf(fp, "Nombre de sujets: %d\n", sujets);
    fprintf(fp, "Nombre de morts: %d (%d%)\n", morts, morts*100/sujets);
    fprintf(fp, "Nombre de malades: %d (%d%)\n", malades, malades*100/sujets);
    fprintf(fp, "Nombre d immunises: %d (%d%)\n", immunises, immunises*100/sujets);
    fprintf(fp, "Nombre de sains: %d (%d%)\n", sains, sains*100/sujets);



    fclose(fp);
}