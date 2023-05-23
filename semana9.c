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

void imprimirMatriz(int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void calcularTranspuesta(int **matriz, int **transpuesta, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
}

int main() {
    int filas, columnas;
    
    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);
    
    int **matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }
    
   
    llenarMatriz(matriz, filas, columnas);
    
    printf("Matriz original:\n");
    imprimirMatriz(matriz, filas, columnas);
    
   
    int **transpuesta = (int **)malloc(columnas * sizeof(int *));
    for (int i = 0; i < columnas; i++) {
        transpuesta[i] = (int *)malloc(filas * sizeof(int));
    }
    
    
    calcularTranspuesta(matriz, transpuesta, filas, columnas);
    
    printf("\nMatriz transpuesta:\n");
    imprimirMatriz(transpuesta, columnas, filas);
    
    
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
    for (int i = 0; i < columnas; i++) {
        free(transpuesta[i]);
    }
    free(transpuesta);
    
    return 0;
}

