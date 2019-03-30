#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED
#define lambda 20 // en pourcentage

#include <stdio.h>
#include <stdlib.h>

enum type {sain = 0, immunise = 0, malade = 1, mort = 1}; // les morts infectent aussi

typedef struct _personne{
    int numero;
    enum type etat;

    struct _personne* suivant;
} personne;

#endif // ZOMBIE_H_INCLUDED