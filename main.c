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
    char character;
    int cnt = 0;
    int max = 10;
    //Initial malloc for char
    fileName = (char*)malloc(max*sizeof(char));
    printf("Zadajte subora:\n");
    while ((input=scanf("%c",&character))==1 && character!='\0')
    {
        //Reallocing char
        if(cnt>=max){
            max*=max*1.5;
            fileName=(char*)realloc(fileName,max*sizeof(char));
            if(fileName==NULL){
                return NULL;
            }
        }
        fileName[cnt]=character;
        cnt++;
    }
    //If something went wrong during reading input and its not EOF return NULL
    if(input!=EOF){
        return NULL;
    }
    file = fopen(fileName,"r");
    //If file does not exist return NULL
    if(file==NULL){
        return NULL;
    }
    return file;
}

int readOperation(){
    int operation = 0;
    printf("1-Kompresia\n");
    printf("2-Dekompresia\n");
    printf("Zadajte operaciu:\n");
    if(scanf("%d",&operation)!=1 && (operation!=1 || operation!=2)){
        return -1;
    }
    else{
        return operation;
    }
}

int main(void){

    FILE*inputFile = readFile();
    if(inputFile==NULL){
        printf("Nespravny vstup.\n");
        return 1;
    }
    FILE*outputFile = readFile();
    if(outputFile==NULL){
        printf("Nespravny vstup.\n");
        return 1;
    }
    switch (readOperation())
    {
        case 1:{
            printf("Kompresia dat\n");
            break;
        }
        case 2:{
            printf("Dekompresia dat\n");
            break;
        }
        
        default:{
            printf("Nespravna operacia.\n");
            return -1;
        }
    }


    return 0;
}