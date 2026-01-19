#ifndef SORTIE_H
#define SORTIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AfficheMaillage(const char* nomFichier, int nP, double** coords, int nT, int** trias);
void AfficheChampVoisinsPoints(const char* nomFichier, int nP, double** coords, int nT, int** trias, int** voisins);
void AfficheChampVoisinsTriangles(const char* nomFichier, int nP, double** coords, int nT, int** trias, int** voisins);

#endif