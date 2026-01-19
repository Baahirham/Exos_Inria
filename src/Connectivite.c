#include "Connectivite.h"

void ConnectivitePoint1(int nP, int nT, int** trias, int*** voisins) {
    
    *voisins = (int**)malloc(nP * sizeof(int*));

    for (int p = 0; p < nP; ++p) {
        int VoisinsTrouves = 0;
        int Capacite = 6; 
        
        (*voisins)[p] = (int*)malloc(Capacite * sizeof(int));

        for (int t = 0; t < nT; ++t) {
            int p1 = -1, p2 = -1;
            
            for (int i = 0; i < 3; i++) {
                if (p == trias[t][i]) {
                    p1 = trias[t][(i + 1) % 3];
                    p2 = trias[t][(i + 2) % 3];
                    break; 
                }
            }

            if (p1 != -1) {
                
                if (VoisinsTrouves + 2 >= Capacite) {
                    Capacite *= 6;
                    (*voisins)[p] = (int*)realloc((*voisins)[p], Capacite * sizeof(int));
                }
    
                int f1 = 0, f2 = 0;
                for (int k = 0; k < VoisinsTrouves; ++k) {
                    if ((*voisins)[p][k] == p1) f1 = 1;
                    if ((*voisins)[p][k] == p2) f2 = 1;
                }
                
                if (f1 == 0) {
                    (*voisins)[p][VoisinsTrouves] = p1;
                    VoisinsTrouves++;
                }
                if (f2 == 0 && p1 != p2) {
                    (*voisins)[p][VoisinsTrouves] = p2;
                    VoisinsTrouves++;
                }
            }
        }

        (*voisins)[p] = (int*)realloc((*voisins)[p], (VoisinsTrouves + 1) * sizeof(int));
        (*voisins)[p][VoisinsTrouves] = -1;
    }
}

void ConnectiviteTriangle1(int nT, int** trias, int*** voisins) {
    *voisins = (int**)malloc(nT * sizeof(int*));

    for (int t1 = 0; t1 < nT; ++t1) {
        int VoisinsTrouves = 0;
        int Capacite = 3; 
        (*voisins)[t1] = (int*)malloc((Capacite + 1) * sizeof(int));

        for (int t2 = 0; t2 < nT; ++t2) {
            if (t1 == t2) continue;

            int PointsCommuns = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (trias[t1][i] == trias[t2][j]) PointsCommuns++;
                }
            }

            if (PointsCommuns >= 2) {
                (*voisins)[t1][VoisinsTrouves] = t2;
                VoisinsTrouves++;
            }
        }

        (*voisins)[t1] = (int*)realloc((*voisins)[t1], (VoisinsTrouves + 1) * sizeof(int));
        (*voisins)[t1][VoisinsTrouves] = -1;
    }
}

void ConnectivitePoint2(int nP, int nT, int** trias, int*** voisins) {
    *voisins = (int**)malloc(nP * sizeof(int*));
    int* tailles = (int*)calloc(nP, sizeof(int));
    int* capacites = (int*)malloc(nP * sizeof(int));
    
    for (int p = 0; p < nP; p++) {
        capacites[p] = 6;
        (*voisins)[p] = (int*)malloc(capacites[p] * sizeof(int));
    }
    
    for (int t = 0; t < nT; t++) {
        int p0 = trias[t][0];
        int p1 = trias[t][1];
        int p2 = trias[t][2];
        
        int aretes[3][2] = {{p0, p1}, {p0, p2}, {p1, p2}};
        
        for (int a = 0; a < 3; a++) {
            int pt1 = aretes[a][0];
            int pt2 = aretes[a][1];
            
            int trouve = 0;
            for (int i = 0; i < tailles[pt1]; i++) {
                if ((*voisins)[pt1][i] == pt2) {
                    trouve = 1;
                    break;
                }
            }
            if (trouve == 0) {
                if (tailles[pt1] >= capacites[pt1]) {
                    capacites[pt1] *= 2;
                    (*voisins)[pt1] = (int*)realloc((*voisins)[pt1], capacites[pt1] * sizeof(int));
                }
                (*voisins)[pt1][tailles[pt1]] = pt2;
                tailles[pt1]++;
            }
            
            trouve = 0;
            for (int i = 0; i < tailles[pt2]; i++) {
                if ((*voisins)[pt2][i] == pt1) {
                    trouve = 1;
                    break;
                }
            }
            if (trouve == 0) {
                if (tailles[pt2] >= capacites[pt2]) {
                    capacites[pt2] *= 2;
                    (*voisins)[pt2] = (int*)realloc((*voisins)[pt2], capacites[pt2] * sizeof(int));
                }
                (*voisins)[pt2][tailles[pt2]] = pt1;
                tailles[pt2]++;
            }
        }
    }
    
    for (int p = 0; p < nP; p++) {
        (*voisins)[p] = (int*)realloc((*voisins)[p], (tailles[p] + 1) * sizeof(int));
        (*voisins)[p][tailles[p]] = -1;
    }
    
    free(tailles);
    free(capacites);
}