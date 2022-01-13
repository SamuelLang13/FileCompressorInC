#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Skomprimuje súbor in a zapíše do súboru out. 
 * @arg in smerník na otvorený vstupný súbor (na čítanie)
 * @arg out smerník na otvorený výstupný súbor (na zápis)
 * @return počet bajtov skomprimovaného súboru
 */
// int compress(FILE* in, FILE* out){

// }
/**
 * Dekomprimuje súbor in a zapíše do súboru out. 
 * @arg in smerník na otvorený vstupný súbor (na čítanie)
 * @arg out smerník na otvorený výstupný súbor (na zápis)
 * @return počet bajtov dekomprimovaného  súboru
 */
// void decompress(FILE* in, FILE* out){

// }

FILE*readFile(){

    FILE*file;
    char*fileName;
    int input = 0;
    printf("Zadajte nazov vstupneho subora:\n");
    char character;
    int cnt = 0;
    int max = 10;
    fileName = (char*)malloc(max*sizeof(char));
    while ((input=scanf("%c",&character))==1 && character!='\0')
    {
        if(cnt>=max){
            max*=max*1.5;
            fileName=(char*)realloc(fileName,max*sizeof(char));
        }
        fileName[cnt]=character;
        cnt++;
    }
    if(input!=EOF){
        return NULL;
    }
    printf("%s\n",fileName);
    

    return file;
}


int main(void){

    FILE*inputFile = readFile();
    FILE*outputFile = readFile();
    if(inputFile==NULL || outputFile==NULL){
        printf("Nespravny vstup.\n");
        return 1;
    }

    return 0;
}