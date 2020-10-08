#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdint.h>

int main (int argc, char *argv[]){
    char filename[80];

    if(argc==1){
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i=1;i<argc;i++){
        FILE *iF;
        strcpy(filename, argv[i]);
        iF = fopen(filename,"r");
        if (iF == NULL) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }
    
    int a,b;
    
   while(!feof(iF)){
        if(fread(&a, 4, 1, iF) == 0){
        break;}
        int chek = fread(&b, 1, 1, iF);
        if(chek == 0){
        break;}
        for (int j=0;j<a;j++){
        printf("%c", b);
        }
   }
    
    


    }
}