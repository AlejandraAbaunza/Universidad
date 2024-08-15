/****************************************
* Autor: Alejandra Abaunza Súarez
* Fecha: 15 de Agosto de 2024
+ Materia: Sistemas Operativos
+ Tema: Gestión de memoria
****************************************/

#include <stdlib.h>
#include <stdio.h>

int main(){
  
  int mA[9];
  int mB[9];
  int mC[9];
  
  /*Inicialización*/
  for(int i = 0; i <9; i++){
    mA[i] = 1;
    mB[i] = 2;
    mC[i] = 0;
  }
  
  /*Impresión*/
  for(int i = 0; i <9; i++){
    if(i%3==0)
      printf("\n");
    printf(" %d ", mA[i]);
  }
  
  printf("\n\n\n......... fin del programa \n");
  
  return 0;
}
