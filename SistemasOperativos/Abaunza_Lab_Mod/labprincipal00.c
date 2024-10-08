/**********************************************************
* Autor: A. Abaunza
* Fecha: 29 -08 - 24
* Materia: Sistemas Operativos
* Laboratirio Compilación Modular
    -Funcionamiento del código
    -Modularización del código
    -Creación de fichero de automatización de compilación
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

#define CAPACIDAD_INICIAL 4

/*Creación Estructura de Datos para el Vector*/
typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;

/*Inicialización de los valores del Vector, casting y reserva de memoria*/
void vectorInicio(vectorDinamico *V){
        V->capacidad = CAPACIDAD_INICIAL;
        V->totalElementos = 0;
        V->elementos = malloc(sizeof(void *) * V->capacidad); 
}

/*Retorna el total de elementos*/
int totalVector(vectorDinamico *V){
        return V->totalElementos;
}

/*Redimensiona el vector*/
static void resizeVector(vectorDinamico *V, int capacidad){
        printf("Redimensión: %d a %d \n", V->capacidad, capacidad);

        void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);
        if(elementos){
                V->elementos = elementos;
                V->capacidad = capacidad;
        }
}

/*Agregar elementos al vector*/
void addVector(vectorDinamico *V, void *elemento){
        if(V->capacidad == V->totalElementos)
                resizeVector(V, V->capacidad*2);
        V->elementos[V->totalElementos++] = elemento;
}

/*Liberación de Memoria Dinámica*/
void freeVector(vectorDinamico *V){
        free(V->elementos);
}

/*Obtención de elemto según indice*/
void *getVector(vectorDinamico *V, int indice){
        if(indice >= 0 && indice < V->totalElementos)
                return V->elementos[indice];
        return NULL;
}

/*Ubicar un elemento en un indice i*/
void setVector(vectorDinamico *V, int indice, void *elemento){
        if(indice >= 0 && indice < V->totalElementos)
                V->elementos[indice]=elemento;
}

/*Borrar elemento según indice, redimensión*/
void borrarVector(vectorDinamico *V, int indice){
        if(indice < 0 || indice >= V->totalElementos)
                return; 

        V->elementos[indice] = NULL;

        for(int i=indice; i<V->totalElementos-1; i++){
                V->elementos[i] = V->elementos[i+1];
                V->elementos[i+1] = NULL; 
        }
        V->totalElementos--;
        if(V->totalElementos>0 && V->totalElementos == V->capacidad/4)
                resizeVector(V, V->capacidad/2);
}

/*Programa principal*/
int main(){
  
  int i;
  
  vectorDinamico editor;
  vectorInicio(&editor);

  addVector(&editor, "Hola");
  addVector(&editor, "Profesional");
  addVector(&editor, "en");
  addVector(&editor, "Formación");
  addVector(&editor, "de");
  addVector(&editor, "Ingeniería");

  printf("\n");

  for (i = 0; i < totalVector(&editor); i++)
  printf("%s ", (char *) getVector(&editor, i));

  printf("\n");
  /*Se borra los 5 elementos del 1 al 5*/
  
  int a=5;
  while(a>1){
    borrarVector(&editor, a);
    a--;
  }
  printf("\n");
  printf("-------");
  printf("\n");
  
  setVector(&editor, 1, "Buenos");
  addVector(&editor, "Dias");

  printf("\n");
  for (i = 0; i < totalVector(&editor); i++)
  printf("%s ", (char *) getVector(&editor, i));
  
  printf("\n");
  freeVector(&editor);
  return 0;
}
