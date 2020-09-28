#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char filename[80];
  char line[201];
  int numLinea = 1;
  // Abrir
  FILE *iF;
  fflush(stdin);
  strcpy(filename, argv[1]);
  printf("longuitud es: %d \n",argc);
  iF = fopen(filename,"r");
  // Chequear que no hayan errores
  if (iF == NULL) {
    printf("Error al abrir el archivo %s\n", filename);
    exit(-1);
  }
  // Procesarlo
  while(fgets(line, 201, iF)!=NULL) {
    printf("%-5d",numLinea++);
    printf("%s",line);
  } 

  // Cerrarlo
  fclose(iF);
  exit(0);
}