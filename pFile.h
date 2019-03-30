#ifndef PFILE_H
#define PFILE_H

#include <stdio.h>
#include <stdlib.h>

enum eType {sain, immunise, malade, mort};

typedef struct _cell 
{
	int	val;
	int poids;
	enum eType etat;
	struct	_cell* suivant;
} cell;

typedef struct 
{
	cell* tete;
	cell* queue; 
} File;

File Initialiser();
int est_vide(File* pF);
void enfiler(File *pF, int val);
int defiler(File *pF);
void detruire (File *pF);

#endif
