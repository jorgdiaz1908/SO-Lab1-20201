#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
    char filename[80];
    char letter;
    char letterfront;
    char first=1;
    int counter =1;
    if(argc==1){
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    for (int i=1;i<argc;i++){
        FILE *iF;
        strcpy(filename, argv[i]);
        iF = fopen(filename,"r");
  // Chequear que no hayan errores
    if (iF == NULL) {
        printf("wzip: cannot open file\n");
        exit(1);
    }
 // Procesarlo
    letter=fgetc(iF);
    while(letter != EOF){
        if (letter == letterfront) {
            counter +=1;
        }else{
            if (first != 1){
                fwrite(&counter, 1, sizeof(counter), stdout);
                printf("%c", letterfront);
            }
            counter = 1;
            }
    letterfront = letter;
    letter= fgetc(iF);
    first = 2;
    }
fclose(iF);
}
fwrite(&counter, 1, sizeof(counter), stdout);
printf("%c", letterfront);
return 0;
}
