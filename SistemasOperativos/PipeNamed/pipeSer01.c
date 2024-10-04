/*****************************************
* Autor: A. Abaunza
* Fecha: Octubre 03 - 2024
* Materia: Sistemas Operativos
* Tema: Pipe Named o FIFO o Tubería
* Tópico: Comunicación Uni-Direccional
*         ****** SERVIDOR ******
******************************************/

#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_FILE "MYFIFO"
  int main() {
    int fd;
    char readbuf[80];
    char end[10];
    int to_end;
    int read_bytes;
    
    /* Create the FIFO if it does not exist */
    mknod(FIFO_FILE, S_IFIFO|0640, 0);
    strcpy(end, "end");
    while(1) {
       fd = open(FIFO_FILE, O_RDONLY);
      read_bytes = read(fd, readbuf, sizeof(readbuf));
      readbuf[read_bytes] = '\0'; 
       printf("Received string: \"%s\" and length is %d\n", readbuf, (int)strlen    (readbuf));
       to_end = strcmp(readbuf, end);
       if (to_end == 0) {
          close(fd);
          break;
       }
    }
  }
