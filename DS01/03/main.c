#include <stdio.h>
#include <string.h>

void numOfAtoms(char *s);

int main(){
    char *str = "H2SO4";
    numOfAtoms(str);
}

void numOfAtoms(char *s){

    printf("%s", s);
}