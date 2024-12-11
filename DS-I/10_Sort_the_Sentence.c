/*
Sorting the Sentence:

A sentence is a list of words that are separated by a single space with no leading or trailing spaces. 
Each word consists of lowercase and uppercase English letters.
A sentence can be shuffled by appending the 1-indexed word position to each word 
then rearrangingthe words in the sentence.

For example, the sentence,
"This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".

Given a shuffled sentence containing no more than 9 words, reconstruct and return the original sentence.
*/

#include<stdio.h>
#include<string.h>

void main() {
    char str[100];

    fgets(str, 100, stdin);
    
    str[strcspn(str, "\n")] = '\0';

    char *strArr[10];
    char *token = strtok(str, " ");

    int len = 0;
    while(token != NULL) {
        strArr[len++] = token ;
        token = strtok(NULL, " ");
    }

    char *strResult[len];
    
    for(int i = 0; i < len; i++) {
        char *word = strArr[i];
        
        // words last index
        int lastIndex = strlen(word) - 1;
        
        // Taking the desired index --> for is2 , index = 2
        int index = word[lastIndex] - '0';
        
        // replacing the lastelememt with '\0' --> ['i','s','2'] ==> is ['i','s','\0']
        word[lastIndex] = '\0';
        
        strResult[index - 1] = word;
    }

    for(int i = 0; i < len; i++) {
        printf("%s ", strResult[i]);
    }

}