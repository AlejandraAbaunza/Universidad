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

#include "librerialab.h"

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
