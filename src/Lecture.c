#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LectureCoordonnees(FILE* Fichier, int* NbPoints, double*** Coordonnees) {
    char Mot[50];

    while (fscanf(Fichier, "%s", Mot) != EOF) {
        if (strcmp(Mot, "Vertices") == 0) {

            fscanf(Fichier, "%d", NbPoints);

            *Coordonnees = (double** )malloc((*NbPoints) * sizeof(double*));

            for (int i = 0; i < *NbPoints; i++) {
                (*Coordonnees)[i] = (double *)malloc(2 * sizeof(double));
                
                double z_temp; 
                int tag_temp;
                
                fscanf(Fichier, "%lf %lf %lf %d", &(*Coordonnees)[i][0], &(*Coordonnees)[i][1], &z_temp, &tag_temp);
            }
            return;
        }
    }
}

void LectureTriangles(FILE* Fichier, int* NbTriangles, int*** Triangles) {
    char Mot[50];

    while (fscanf(Fichier, "%s", Mot) != EOF) {
        if (strcmp(Mot, "Triangles") == 0) {

            fscanf(Fichier, "%d", NbTriangles);

            *Triangles = (int** )malloc((*NbTriangles) * sizeof(int*));

            for (int i = 0; i < *NbTriangles; i++) {
                (*Triangles)[i] = (int *)malloc(3 * sizeof(int));
                 
                int tag_temp;
                
                fscanf(Fichier, "%d %d %d %d", &(*Triangles)[i][0], &(*Triangles)[i][1], &(*Triangles)[i][2], &tag_temp);
                (*Triangles)[i][0]--; 
                (*Triangles)[i][1]--;
                (*Triangles)[i][2]--;
            }
            return;
        }
    }
}

void LectureMaillage(FILE* Fichier, int* NbPoints, int* NbTriangles, double*** Coordonnees, int*** Triangles) {
    rewind(Fichier);
    LectureCoordonnees(Fichier, NbPoints, Coordonnees);
    rewind(Fichier);
    LectureTriangles(Fichier, NbTriangles, Triangles);

    printf("--- Maillage charge avec succes ---\n");
    printf("Points    : %d\n", *NbPoints);
    printf("Triangles : %d\n", *NbTriangles);
}

