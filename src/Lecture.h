#ifndef LECTURE_H
#define LECTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LectureCoordonnees(FILE* Fichier, int* NbPoints, double*** Coordonnees);
void LectureTriangles(FILE* Fichier, int* NbTriangles, int*** Triangles);
void LectureMaillage(FILE* Fichier, int* NbPoints, int* NbTriangles, double*** Coordonnees, int*** Triangles);

#endif