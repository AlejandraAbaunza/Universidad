/*******************************************************
* Autor: Alejandra Abaunza Suárez
* Fecha: 8-8-2024
* Materia: Sistemas Operativos
* Tema: Asignación de Memoria Dinámica
        Asignación del tamaño en Bytes de almacenamiento
********************************************************/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  
  int *vP1 = calloc(4, sizeof(int)); //Asignación para un vector INT de size 4, inicializado en 0
  int *vP2 = calloc(1, sizeof(int[4])); //Asignación para un vector INT de size 4, inicializado en 0
  int *vP3 = calloc(4, sizeof *vP3); //Asignación para un vector INT de size 4, inicializado en 0
                        
  if(vP2){
    for(int i=0; i<4; ++i){
      printf("vP2[%d]\t == %d\n", i, vP2[i]);
    }
  }                  
  printf("Se libera memoria reservada\n");
  free(vP1);
  free(vP2);                       
  free(vP3);
  
  return 0;

}
