#define MAX_ETATS 1000

#include "graphe.h"


void lireGraphe(Graphe* G, const char* grapheFileName)
{
	FILE *fp;
	fp = fopen(grapheFileName, "r");
	
	if (fp != NULL) // le fichier est trouve
	{
		int nb_sommets, nb_arcs, u, v, w; // dans l'ordre: nombre de sommets; nombre d'arcs; premier noeud de l'arc; deuxieme; poids de l'arc;
		fscanf(fp, "%d %d", &nb_sommets, &nb_arcs);
		G->nb_sommets 	= nb_sommets;
		G->successeurs	= (cell**)malloc(nb_sommets * sizeof(cell*));

		for (int i = 1; i < nb_sommets +1; i++)
			G->successeurs[i]	= NULL;

		for (int i = 1; i < nb_arcs +1; i++)
		{
			fscanf(fp, "%d %d %d", &u, &v, &w);
			//u--; // decrement pour gerer le decalage entre le numeros des sommets dans le fichiers et les index dans les tableaux
			//v--;
			//ajout d'un arc (u,v) : un maillon est ajoute en debut de la liste de successeurs de u
			cell* s	= (cell*) malloc(sizeof(cell));
			s->etat = sain;
			s->val = v;
			s->poids = w;
			s->suivant = G->successeurs[u];
			G->successeurs[u] = s;
		}
	}
	else printf("Le fichier n'a pas ete trouve.");
	fclose(fp);
}

void affichage_graphe(Graphe* G) 
{
	cell* courant;

	for(int i = 0; i < G->nb_sommets; i++) 
	{
		printf("Sommet %d : ", i+1);
		courant = G->successeurs[i];
		while(courant != NULL)
		{
			printf("%d, ", courant->val +1);
			courant = courant->suivant;
		} 
		printf("\n");
	}
}


void infection(int taille, enum eType* listeEtats){
	srand(time(NULL)); // initialisation de rand
	int index = rand()%(taille*taille); // choisir un malade au hasard
    //int index = rand()%(10000);
	listeEtats[index] = malade;
}


void forward(Graphe* populationMatrice, enum eType* listeEtats, int taille, float plambda, float pbeta, float pgamma){
    enum eType listeTemp[MAX_ETATS]; // on fait une copie pour ne pas utiliser le graphe que l'on construit dans nos tests
    for(int i = 1; i< taille*taille + 1;i++){
        listeTemp[i] = listeEtats[i];
    }
    cell* nouveau = malloc(sizeof(cell*));
    for(int i = 1; i< taille*taille + 1; i++){
        if (listeTemp[i] == sain) {
            float pmalade = 0;
            nouveau = populationMatrice->successeurs[i];
            while (nouveau != NULL) {
                pmalade += plambda*(listeTemp[nouveau->val] == malade);
                nouveau = nouveau->suivant;
            }
            if (pmalade> 1.0*rand()/RAND_MAX)
                {listeEtats[i] = malade;}
        }
        else if (listeTemp[i] == malade){
            if (pbeta > 1.0*rand()/RAND_MAX)
                {listeEtats[i] = mort;}
            else if (pgamma > 1.0*rand()/RAND_MAX)
                {listeEtats[i] = immunise;}
        }
    }
    free(nouveau);
}