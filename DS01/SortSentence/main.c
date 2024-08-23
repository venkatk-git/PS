/*
Sorting the Sentence
--------------------
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. 
Each word consists of lowercase and uppercase English letters.
A sentence can be shuffled by appending the 1-indexed word position to each word 
then rearranging the words in the sentence.

For example,
The sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".

Given a shuffled sentence containing no more than 9 words, reconstruct and return the original sentence.
*/

#include <stdio.h>
#include <string.h>

int main(){
    char s[] = "is2 sentence4 This1 a3";
    char *sArr[10];
    int len = 0;
    
    char *token = strtok(s, " ");
    while(token != NULL){
        sArr[len++] = token;
        token = strtok(NULL, " ");
    }

    char *sortedSArr[len];
    int index;
    for(int i = 0; i < len; i++){
        char *word = sArr[i];
        index = word[strlen(word) - 1] - '0';
        word[strlen(word) - 1] = 0;
        sortedSArr[index - 1] = word;
    }

    for(int i = 0; i < len; i++)
        printf("%s ", sortedSArr[i]);
    
    return 0;
}