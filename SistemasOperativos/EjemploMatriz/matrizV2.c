/****************************************
* Autor: Alejandra Abaunza Súarez
* Fecha: 15 de Agosto de 2024
* Materia: Sistemas Operativos
* Tema: Gestión de memoria
* Topico: Diferencia entre usar o no punteros
*********************************************/

#include <stdlib.h>
#include <stdio.h>

int imprimirMatriz(int *matriz, int n){
  for(int i = 0; i <n*n; i++){
    if(i%n==0)
      printf("\n");
    printf(" %d ", *(matriz+i));
  }
  
  printf("\n________________________\n");
}

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
  
  imprimirMatriz(mA,n);
  imprimirMatriz(mB,n);
  imprimirMatriz(mC,n);
  printf("\n\n\n......... fin del programa \n\n");
  
  return 0;
}
