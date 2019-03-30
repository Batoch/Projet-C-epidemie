#include <stdio.h>
#include <stdlib.h>
#include "zombie.h"
#include "CreerGraph.h"
#include "graphe.h"

int main()
{
    printf("Hello world123!\n");

    int taille; taille = 10;

    Graphe populationMatrice;
    creerGraph(taille);
    // lireGraphe(&populationMatrice, "C:\\Users\\makhl\\Desktop\\testClion\\cmake-build-debug\\graph.txt");
    lireGraphe(&populationMatrice, "C:\\Users\\makhl\\Desktop\\testClion\\cmake-build-debug\\graph.txt");

    // Toute la population est initialemnt saine
    // On infecte une personne au hasard
    printf("//******** INFECTIONATOR V2.0 ********\\\\\n\n");
    printf("parametres d'infection:\nchances d'infection: ");
    float plambda; float pbeta; float pgamma;
    scanf("%d",&plambda);
    printf("dangerosite de l'infection: ");
    scanf("%d",&pbeta);
    printf("probabilite d'immunisation: ");
    scanf("%d",&pgamma);
    //void infection(plambda, pbeta, pgamma);



    return 0;
}