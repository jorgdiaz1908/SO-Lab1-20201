#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search( const char *const filename, char *comp){
    FILE *iF;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    iF = fopen(filename,"r");

    if(iF == NULL){
        printf("wgrep: cannot open file\n");
        exit(1);
    }
    while((read = getline(&line, &len, iF)) != -1){
        if(strstr(line, comp) != NULL){
            printf("%s", line);
        }
    }
    free(line);
}

int main(int argc, char *argv[]) {
  char *name, linea;
  int i = 2;

  
  if(argc < 2){
      printf("wgrep: searchterm [file ...]\n");
      exit(1);
  }

  char *string = argv[1];

  if(argc == 2){
    char *line = NULL;
    size_t len = 0;
      while((linea =  getline(&line, &len, stdin)) != -1){
if(strstr(line, string) != NULL){
            printf("%s", line);
        }    }

       
  }

 
  for(i = 2; i < argc; ++i){
      name = argv[i];
      search(name, string);
  }
  
  exit(0);
}