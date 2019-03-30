#include "zombie.h"
#include "graphe.h"

void lireGraphe(Graphe* graphe, const char* grapheFileName){ // rentrer juste le nombre de sommets
    FILE *fp;
    fp = fopen(grapheFileName, "r");

    if (fp != NULL){ // le fichier est trouve
        int nb_sommets, u, v;
        fscanf(fp, "%d", &nb_sommets);
        graphe->nb_sommets 	= nb_sommets;
        graphe->successeurs	= (personne**)malloc(nb_sommets * sizeof(personne*));

        int i;
        for (i = 0; i < nb_sommets; i++)
            graphe->successeurs[i]	= NULL;

        for (i = 0; i < nb_sommets; i++){
            fscanf(fp, "%d %d", &u, &v);
            //u--; // decrement pour gerer le decalage entre le numeros des sommets dans le fichiers et les index dans les tableaux
            //v--;
            //ajout d'un arc (u,v) : un maillon est ajoute en debut de la liste de successeurs de u
            personne* s		= (personne*) malloc(sizeof(personne));
            s->numero = v;
            s->suivant = graphe->successeurs[u];
            graphe->successeurs[u]	= s;
        }
    }
    else printf("Le fichier n'a pas été trouvé.");
    fclose(fp);
}

void affichage_graphe(Graphe* graphe){

}