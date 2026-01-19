#include "Sortie.h"

void AfficheMaillage(const char* nomFichier, int nP, double** coords, int nT, int** trias) {
    FILE* f = fopen(nomFichier, "w");
    if (!f) return;

    fprintf(f, "# vtk DataFile Version 3.0\n");
    fprintf(f, "Maillage\n");
    fprintf(f, "ASCII\nDATASET UNSTRUCTURED_GRID\n\n");

    fprintf(f, "POINTS %d double\n", nP);
    for (int i = 0; i < nP; i++) {
        fprintf(f, "%f %f 0.0\n", coords[i][0], coords[i][1]);
    }

    fprintf(f, "\nCELLS %d %d\n", nT, nT * 4);
    for (int i = 0; i < nT; i++) {
        fprintf(f, "3 %d %d %d\n", trias[i][0], trias[i][1], trias[i][2]);
    }

    fprintf(f, "\nCELL_TYPES %d\n", nT);
    for (int i = 0; i < nT; i++) {
        fprintf(f, "5\n");
    }

    fclose(f);
    printf("Fichier VTK genere : %s\n", nomFichier);
}

void AfficheChampVoisinsPoints(const char* nomFichier, int nP, double** coords, int nT, int** trias, int** voisins) {
    FILE* f = fopen(nomFichier, "w");
    if (!f) return;

    fprintf(f, "# vtk DataFile Version 3.0\n");
    fprintf(f, "Champ Voisins\n");
    fprintf(f, "ASCII\nDATASET UNSTRUCTURED_GRID\n\n");

    fprintf(f, "POINTS %d double\n", nP);
    for (int i = 0; i < nP; i++) {
        fprintf(f, "%f %f 0.0\n", coords[i][0], coords[i][1]);
    }

    fprintf(f, "\nCELLS %d %d\n", nT, nT * 4);
    for (int i = 0; i < nT; i++) {
        fprintf(f, "3 %d %d %d\n", trias[i][0], trias[i][1], trias[i][2]);
    }

    fprintf(f, "\nCELL_TYPES %d\n", nT);
    for (int i = 0; i < nT; i++) {
        fprintf(f, "5\n");
    }

    fprintf(f, "\nPOINT_DATA %d\n", nP);
    fprintf(f, "SCALARS nb_voisins int 1\n");
    fprintf(f, "LOOKUP_TABLE default\n");

    for (int i = 0; i < nP; i++) {
        int count = 0;
        while (voisins[i][count] != -1) {
            count++;
        }
        fprintf(f, "%d\n", count);
    }

    fclose(f);
    printf("Fichier VTK avec champ genere : %s\n", nomFichier);
}

void AfficheChampVoisinsTriangles(const char* nomFichier, int nP, double** coords, int nT, int** trias, int** voisins) {
    FILE* f = fopen(nomFichier, "w");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", nomFichier);
        return;
    }

    fprintf(f, "# vtk DataFile Version 3.0\n");
    fprintf(f, "Champ de voisinage des triangles\n");
    fprintf(f, "ASCII\n");
    fprintf(f, "DATASET UNSTRUCTURED_GRID\n");

    fprintf(f, "POINTS %d double\n", nP);
    for (int i = 0; i < nP; i++) {
        fprintf(f, "%f %f 0.0\n", coords[i][0], coords[i][1]);
    }

    fprintf(f, "\nCELLS %d %d\n", nT, nT * 4);
    for (int i = 0; i < nT; i++) {
        fprintf(f, "3 %d %d %d\n", trias[i][0], trias[i][1], trias[i][2]);
    }

    fprintf(f, "\nCELL_TYPES %d\n", nT);
    for (int i = 0; i < nT; i++) {
        fprintf(f, "5\n"); 
    }

    fprintf(f, "\nCELL_DATA %d\n", nT);
    fprintf(f, "SCALARS nb_voisins int 1\n");
    fprintf(f, "LOOKUP_TABLE default\n");

    for (int t = 0; t < nT; t++) {
        int nb_trouves = 0;
        while (voisins[t][nb_trouves] != -1) {
            nb_trouves++;
        }
        fprintf(f, "%d\n", nb_trouves);
    }

    fclose(f);
    printf("Fichier VTK genere : %s\n", nomFichier);
}