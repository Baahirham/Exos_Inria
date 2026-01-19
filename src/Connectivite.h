#ifndef CONNECTIVITE_H
#define CONNECTIVITE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ConnectivitePoint1(int nP, int nT, int** trias, int*** voisins);
void ConnectiviteTriangle1(int nT, int** trias, int*** voisins);
void ConnectivitePoint2(int nP, int nT, int** trias, int*** voisins);
void ConnectiviteTriangle2(int nP, int nT, int** trias, int*** voisins);

#endif