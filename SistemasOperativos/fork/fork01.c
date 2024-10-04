/********************************************
* Autor: A. Abaunza
* Fecha: Octubre 03 - 2024
* Materia: Sistemas Operativos
* Tema: Creación de Fork "Arbol de Creación"
*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void creacion_fork(int linea){
      pid_t proceso; 
      proceso = fork();
      if(proceso<0){
          printf("Error creación proceso\n");
          exit(0);
      }else if (proceso==0)
          printf("%d: Proceso =HIJO=: %d\n",linea, getpid());
      else
          printf("%d: Proceso =PADRE= %d\n",linea, getpid());
  }
  
int main(int argc, char *argv[]){
      int p = (int) atoi(argv[1]);
      for(int i=0; i<p; i++)
          creacion_fork(i);
  
  
      printf("\n");
      return 0;
  }
