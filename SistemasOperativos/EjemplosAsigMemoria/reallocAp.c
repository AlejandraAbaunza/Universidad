/*******************************************************
* Autor: Alejandra Abaunza Suárez
* Fecha: 8-8-2024
* Materia: Sistemas Operativos
* Tema: Asignación de Memoria Dinámica
        Asignación del tamaño en Bytes de almacenamiento
********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h> // Para memcpy
#include <assert.h> // Para assert

/* Función para imprimir el tamaño reasignado */
void info_Almacenamiento(const int *siguiente, const int *anterior, int valores) {
    if (siguiente) {
        printf("Ubicación = %p. Tamaño Reservado: %d valores (%ld bytes)\n",
               (void*)siguiente, valores, valores * sizeof(int));
    }
}

int main() {
    const int patron[] = {1, 2, 3, 4, 5, 6, 7, 8};
    const int patron_size = sizeof(patron) / sizeof(int);
    int *siguiente = NULL, *anterior = NULL;

    // Asigna el vector
    siguiente = (int *)malloc(patron_size * sizeof(int));
    if (siguiente) {
        // Llena el vector
        memcpy(siguiente, patron, patron_size * sizeof(int));
        info_Almacenamiento(siguiente, anterior, patron_size);
    } else {
        return EXIT_FAILURE;
    }

    // Reasigna los valores del vector en el siguiente ciclo
    const int realloc_size[] = {10, 20, 30, 40, 50, 60, 70, 80};
    for (int i = 0; i < sizeof(realloc_size) / sizeof(int); i++) {
        // Reasigna memoria
        anterior = siguiente;
        siguiente = (int *)realloc(siguiente, realloc_size[i] * sizeof(int));
        
        if (siguiente) {
            // Copia datos del antiguo bloque de memoria al nuevo, si es necesario
            if (anterior) {
                info_Almacenamiento(siguiente, anterior, realloc_size[i]);
            }
        } else {
            printf("Error al reasignar memoria\n");
            free(anterior);
            return EXIT_FAILURE;
        }
    }

    printf("Se libera memoria reservada\n");
    free(siguiente); // Finalmente se libera el almacenamiento

    return 0;
}
