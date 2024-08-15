/****************************************
* Autor: Alejandra Abaunza Súarez
* Fecha: 15 de Agosto de 2024
* Materia: Sistemas Operativos
* Tema: Gestión de memoria
* Topico: Diferencia entre usar o no punteros
*********************************************/

#include <stdlib.h>
#include <stdio.h>

int main(){
  int n = 3;
  int size = n*n;
  int mA[size];
  int mB[size];
  int mC[size];
  
  /*Inicialización de matrices*/
  for(int i = 0; i <9; i++){
    mA[i] = 1;
    mB[i] = 2;
    mC[i] = 0;
  }
  
  /*Impresión*/
  for(int i = 0; i <size; i++){
    if(i%n==0)
      printf("\n");
    printf(" %d ", mA[i]);
  }
  
  printf("\n________________________\n");
  
  for(int i = 0; i <size; i++){
    if(i%n==0)
      printf("\n");
    printf(" %d ", mB[i]);
  }
  
  printf("\n________________________\n");
  
  for(int i = 0; i <size; i++){
    if(i%n==0)
      printf("\n");
    printf(" %d ", mC[i]);
  }
  
  printf("\n\n\n......... fin del programa \n\n");
  
  return 0;
}
