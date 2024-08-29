/******************************************************************
* Autor: A. Abaunza
* Fecha: 29 -08 - 24
* Materia: Sistemas Operativos
* Laboratirio Compilación Modular
    -Funcionamiento del código
    -Modularización del código
    -Creación de fichero de automatización de compilación
*******************************************************************
    INTERFAZ DE LIBRERIA DE FUNCIONES: MENU DE FUNCIONES
*******************************************************************/
#ifndef _LIBRERIALAB_H_
#define _LIBRERIALAB_H_

#define CAPACIDAD_INICIAL 4

/*Creación Estructura de Datos para el Vector*/
typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;

/*Inicialización de los valores del Vector, casting y reserva de memoria*/
void vectorInicio(vectorDinamico *V);}

/*Retorna el total de elementos*/
int totalVector(vectorDinamico *V);

/*Redimensiona el vector*/
static void resizeVector(vectorDinamico *V, int capacidad);

/*Agregar elementos al vector*/
void addVector(vectorDinamico *V, void *elemento);

/*Liberación de Memoria Dinámica*/
void freeVector(vectorDinamico *V);

/*Obtención de elemto según indice*/
void *getVector(vectorDinamico *V, int indice);

/*Ubicar un elemento en un indice i*/
void setVector(vectorDinamico *V, int indice, void *elemento);

/*Borrar elemento según indice, redimensión*/
void borrarVector(vectorDinamico *V, int indice);

#endif
#endif
