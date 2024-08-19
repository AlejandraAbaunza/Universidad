/****************************************
* Autor: Alejandra Abaunza Súarez
* Fecha: 15 de Agosto de 2024
* Materia: Sistemas Operativos
* Tema: Gestión de memoria
* Topico: Diferencia entre usar o no punteros
*********************************************/

#include <stdlib.h>
#include <stdio.h>

void imprimirMatriz(int *matriz, int n){
    for (int i = 0; i < n * n; i++) {
        if (i % n == 0) {
            printf("\n");
        }
        printf(" %d ", *(matriz + i));
    }
    printf("\n________________________\n");
}

int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("\nArgumentos validos: $ejecutable sizeOfMatriz\n");
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    int size = n * n;

    // Declaración de matrices
    int mA[size];
    int mB[size];
    int mC[size]; 

    // Inicialización de matrices
    for (int i = 0; i < size; i++) {
        mA[i] = 1; // Inicializa mA con 1
        mB[i] = 2; // Inicializa mB con 2
        mC[i] = 0; // Inicializa mC con 0
    }

    // Versión Clásica de Multiplicación de matrices: mA * mB = mC
    for (int i = 0; i < n; i++) { // Filas de mA
        for (int j = 0; j < n; j++) { // Columnas de mB
            int suma = 0;
            for (int k = 0; k < n; k++) { // Elementos de la fila de mA y columna de mB
                suma += mA[i * n + k] * mB[k * n + j];
            }
            mC[i * n + j] = suma;
        }
    }

    imprimirMatriz(mA, n);
    imprimirMatriz(mB, n);
    imprimirMatriz(mC, n);
    printf("\n\n\n......... fin del programa \n\n");

    return 0;
}
