#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenarMatriz(int **matriz, int filas, int columnas) {
    srand(time(NULL));
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 100 + 1;  
        }
    }
}
