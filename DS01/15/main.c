#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split(char *str){
    char *subString;
    char *subStringArr[9];
    int len = 0;

    subString = strtok(str, " ");
    while (subString != NULL){
        subStringArr[len++] = subString;
        subString = strtok(NULL, " ");
    }

    char *sortedString[len];

    for(int i = 0; i < len; i++){
        char *word = subStringArr[i];
        int index = word[strlen(word) - 1] - '0' - 1;
        word[strlen(word) - 1] = '\0';
        sortedString[index] = word;
    }

    for(int i = 0; i < len; i++){
        printf("%s ", sortedString[i]);
    }
}

void main(){
    char str[] = "Myself2 Me1 I4 and3";
    split(str);
}