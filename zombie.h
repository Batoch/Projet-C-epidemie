#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct _zombie{
    struct _zombie* suivant;
} zombie;

#endif // ZOMBIE_H_INCLUDED