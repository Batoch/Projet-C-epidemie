#include <stdio.h>
#include <stdlib.h>
#include "CreerGraph.h"
#include "graphe.h"
#include "pFile.h"
#include "affichage.h"


int main()
{
    int taille = 10;
    printf("largeur de la matrice a simuler?: ");
    scanf("%d",&taille);


    Graphe populationMatrice;
    creerGraph(taille);
    lireGraphe(&populationMatrice, "cmake-build-debug/graph.txt");
    //lireGraphe(&populationMatrice, "C:\\Users\\makhl\\Desktop\\testClion\\cmake-build-debug\\graph.txt");

    // Toute la population est initialemnt saine
    enum eType listeEtats[taille*taille];
    for (int i = 0; i<taille*taille; i++){
        listeEtats[i] = sain;
    }

    // On infecte une cell au hasard
    float plambda = 0.5; float pbeta = 0.5; float pgamma = 0.5;

    printf("//******** INFECTIONATOR V2.0 ********\\\\\n\n");
    printf("-={parametres d'infection}=-\nchances d'infection: ");
    scanf("%f",&plambda);
    printf("dangerosite de l'infection: ");
    scanf("%f",&pbeta);
    printf("probabilite d'immunisation: ");
    scanf("%f",&pgamma);

    afficherMatrice(listeEtats, taille);
    infection(taille, (enum eType *) &listeEtats);
    afficherMatrice(listeEtats, taille);


    for (int i=0; i< 20; i++) {
        printf("\e[1;1H\e[2J");     //clear console
        pause(1000);
        forward(&populationMatrice, &listeEtats, taille, plambda, pbeta, pgamma);
        afficherMatrice(listeEtats, taille);
    }



    return 0;
}