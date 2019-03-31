#include <stdio.h>
#include <stdlib.h>
#include "CreerGraph.h"
#include "graphe.h"
#include "pFile.h"
#include "affichage.h"

#define MAX_ETATS 1000

int main()
{
    printf("Hello world123!\n");

    int taille; taille = 10;

    Graphe populationMatrice;
    creerGraph(taille);
    // lireGraphe(&populationMatrice, "C:\\Users\\makhl\\Desktop\\testClion\\cmake-build-debug\\graph.txt");
    lireGraphe(&populationMatrice, "C:\\Users\\makhl\\Desktop\\testClion\\cmake-build-debug\\graph.txt");

    // Toute la population est initialemnt saine
    enum eType listeEtats[MAX_ETATS]; // nous n'avons pas compris pourquoi mais on ne peut pas mettre de variable en paramètre de taille du tableau
    for (int i = 1; i<taille*taille + 1; i++){
        listeEtats[i] = sain;
    }

    // On infecte une cell au hasard
    printf("//******** INFECTIONATOR V2.0 ********\\\\\n\n");
    printf("-={parametres d'infection}=-\nchances d'infection: ");
    float plambda; float pbeta; float pgamma;
    scanf("%f",&plambda);
    printf("dangerosite de l'infection: ");
    scanf("%f",&pbeta);
    printf("probabilite d'immunisation: ");
    scanf("%f",&pgamma);

    afficherMatrice(listeEtats, taille);
    infection(taille, &listeEtats);
    afficherMatrice(listeEtats, taille);
    forward(&populationMatrice,&listeEtats,taille, plambda, pbeta, pgamma);
    afficherMatrice(listeEtats, taille);


    return 0;
}