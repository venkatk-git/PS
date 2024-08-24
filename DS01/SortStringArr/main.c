/*
Sort the given string array
---------------------------
Given n number of strings as an array, sort the givent array.
While sorting print every iteration output.

Input Format:
First Line, An integer n representing the size of the string array.
Next n Lines, Each of the following n lines contains a single string element.

Example:
Input:
5
["Grape", "Orange", "Apple", "Pineapple", "Banana"]
Output:
Grape Apple Orange Banana Pineapple  (Iteration - 1)
Apple Grape Banana Orange Pineapple  (Iteration - 2)
Apple Banana Grape Orange Pineapple  (Iteration - 3)
Apple Banana Grape Orange Pineapple  (Iteration - 4)
*/

#include <stdio.h>
#include <string.h>

void printStringArr(int n, char s[n][20]);
void sort(int n, char s[n][20]);
void swap(int n, char s[n][20], int i, int j);

void main(){
    int n;
    scanf("%d", &n);
    char s[n][20];
    
    for(int i = 0; i < n; i++)
        scanf("%s", &s[i]);

    sort(n, s);
}

void sort(int n, char s[n][20]){
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n - i; j++)
            // if current word(s[j]) is larger than the previous word(s[j-1]) then perform swap 
            if(strcmp(s[j], s[j - 1]) < 0)
                swap(n, s, j, j - 1);
        printStringArr(n, s);
        printf("\n");
    }
}

void printStringArr(int n, char s[n][20]){
    for(int i = 0; i < n; i++)
        printf("%s ", s[i]);
}

void swap(int n, char s[n][20], int i, int j){
    char word[20];
    strcpy(word, s[i]);
    strcpy(s[i], s[j]);
    strcpy(s[j], word); 
}