#include <stdio.h>
#include <string.h>

void main(){
    char s[] = "This is a sentence.";
    char *sArr[100];
    char *delimeter = " ";
    int i = 0;

    char *token = strtok(s, delimeter);
    while(token != 0){
        sArr[i++] = token;
        token = strtok(NULL, delimeter);
    }

    for(int j = 0; j <= i; j++)
        printf("%s ",sArr[j]);
}