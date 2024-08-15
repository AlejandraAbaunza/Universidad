/************************************
* Autor: Alejandra Abaunza Suárez
* Fecha: 8-8-2024
* Materia: Sistemas Operativos
* Tema: Puntero a puntero
************************************/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  
  int var = 480;
  int *varptr = &var;
  int **doubleptr = &varptr;
  
  printf("Valor de la variable\t\t= %d\n", var);
  printf("Valor del puntero\t\t= %d\n", *varptr);
  printf("Valor del puntero doble\t\t= %p\n", *doubleptr);
  
  printf("Dirección de la variable\t\t= %p\n", &var);
  
  printf("Direccion del puntero\t\t= %p\n", &varptr);
  printf("Valor en el puntero\t\t= %p\n", varptr);
  
  printf("Direccion del puntero doble\t\t= %p\n", *doubleptr);
  printf("Valor en el puntero doble\t\t= %p\n", doubleptr);
 
  
return 0;
  
  
}
