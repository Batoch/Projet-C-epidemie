#include <stdio.h>
#include <stdlib.h>
#include "CreerGraph.h"
#include "graphe.h"
#include "pFile.h"
#include "affichage.h"

#define MAX_ETATS 1000

int main()
{
    int taille = 10;
    printf("largeur de la matrice a simuler?: ");
    scanf("%d",&taille);


    Graphe populationMatrice;
    creerGraph(taille);
    lireGraphe(&populationMatrice, "C:\\Users\\Baptiste\\CLionProjects\\Projet-C-epidemie\\cmake-build-debug\\graph.txt");
    //lireGraphe(&populationMatrice, "C:\\Users\\makhl\\Desktop\\testClion\\cmake-build-debug\\graph.txt");

    // Toute la population est initialemnt saine
    enum eType listeEtats[taille*taille]; // // nous n'avons pas compris pourquoi mais on ne peut pas mettre de variable en paramètre de taille du tableau
    for (int i = 1; i<taille*taille + 1; i++){
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
    infection(taille, &listeEtats);
    afficherMatrice(listeEtats, taille);

    printf("appuyer sur entrer pour faire avancer la simulation");

    for (int i=0; i< 10; i++) {
        forward(&populationMatrice, &listeEtats, taille, plambda, pbeta, pgamma);
        afficherMatrice(listeEtats, taille);
        getchar();
    }



    return 0;
}