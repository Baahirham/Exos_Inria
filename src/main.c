#include "Lecture.h"
#include "Connectivite.h"
#include "Sortie.h"
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <nom_du_fichier.mesh>\n", argv[0]);
        return 1;
    }

    FILE* F = fopen(argv[1], "r");
    if (!F) {
        printf("Erreur : Impossible d'ouvrir le fichier %s\n", argv[1]);
        return 1;
    }

    int nP = 0, nT = 0;
    double** coords = NULL;
    int** trias = NULL;
    int** voisinsPoints1 = NULL;
    int** voisinsPoints2 = NULL;
    int** voisinsTriangles = NULL;

    printf("Debut de la lecture du fichier : %s\n", argv[1]);
    LectureMaillage(F, &nP, &nT, &coords, &trias);

    clock_t start, end;
    double cpu_time1, cpu_time2;

    printf("Calcul Naïf en cours...\n");
    start = clock();
    ConnectivitePoint1(nP, nT, trias, &voisinsPoints1);
    end = clock();
    cpu_time1 = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Calcul Optimisé en cours...\n");
    start = clock();
    ConnectivitePoint2(nP, nT, trias, &voisinsPoints2);
    end = clock();
    cpu_time2 = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n--- RÉSULTATS ---\n");
    printf("Temps Naïf    : %f secondes\n", cpu_time1);
    printf("Temps Optimisé : %f secondes\n", cpu_time2);
    printf("Facteur de gain : x%.1f\n", cpu_time1 / cpu_time2);
    
    ConnectiviteTriangle1(nT, trias, &voisinsTriangles);

    AfficheMaillage("res/Maillage.vtk", nP, coords, nT, trias);
    AfficheChampVoisinsPoints("res/VoisinsPoints.vtk", nP, coords, nT, trias, voisinsPoints1);
    AfficheChampVoisinsTriangles("res/VoisinsTriangles.vtk", nP, coords, nT, trias, voisinsTriangles);

    for(int i=0; i < nP; i++) free(coords[i]);
    free(coords);
    
    for(int i=0; i < nT; i++) free(trias[i]);
    free(trias);

    for(int i=0; i < nP; i++) free(voisinsPoints1[i]);
    free(voisinsPoints1);

    for(int i=0; i < nP; i++) free(voisinsPoints2[i]);
    free(voisinsPoints2);

    for(int i=0; i < nT; i++) free(voisinsTriangles[i]);
    free(voisinsTriangles);

    fclose(F);
    return 0;
}