#include <stdio.h>
#include <stdlib.h>
#include "zombie.h"
#include "CreerGraph.h"
#include "graphe.h"

int main()
{
    printf("Hello world123!\n");
//cvbknfcb
    int taille; taille = 10;
    creerGraph(taille);

    Graphe populationMatrice;
    creerGraph(taille);
    lireGraphe(&populationMatrice, "graphe.txt");

    // Toute la population est initialemnt saine
    // On infecte une personne au hasard
    printf("//******** INFECTIONATOR V2.0 ********\\\\\n\n");
    printf("parametres d'infection:\nchances d'infection: ");
    float plambda; float pbeta; float pgamma;
    scanf("%d",&plambda);
    printf("\ndangerosite de l'infection: ");
    scanf("%d",&pbeta);
    printf("\nprobabilite d'immunisation: ");
    scanf("%d",&pgamma);
    //void infection(plambda, pbeta, pgamma);



    return 0;
}