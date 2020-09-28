#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(int argc, char *argv[]) {
  char filename[80];
  char line[201];
  // Abrir
  FILE *iF;
  if (argv[1]== NULL){
    exit(0);
  }
  
  for (int i=1; i<argc;i++){
    strcpy(filename, argv[i]);
    iF = fopen(filename,"r");
  // Chequear que no hayan errores
    if (iF == NULL) {
    printf("wcat: cannot open file\n");
    exit(1);
    }
  // Procesarlo
    while(fgets(line, 201, iF)!=NULL) {
    printf("%s",line);
    }     
  }

// Cerrarlo
fclose(iF);
exit(0);
}