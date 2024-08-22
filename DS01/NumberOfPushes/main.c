/*
You are given a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters,
which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"],
we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be
remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to 
find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.
Note that 1, *, #, and 0 do not map to any letters.

Example:
Input: word = "abcde"
Output: 5
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
*/

#include <stdio.h>
#include <string.h>
#include "../../utils/swap.c"

void quickSort(int arr[], int s, int e){
    if(s >= e) return;

    int pivot = arr[e];
    int startsWith = s;

    for(int i = s; i < e; i++)
        if(arr[i] > pivot)
            swap(&arr[i], &arr[startsWith++]);

    swap(&arr[e], &arr[startsWith]);

    quickSort(arr, s, startsWith - 1);
    quickSort(arr, startsWith + 1, e);
}

int main(){
    char *word = "aabbccddeeffgghhiiiiii";
    int cache[26] = {0};

    for(int i = 0; i < strlen(word); i++)
        cache[word[i] - 97]++;

    quickSort(cache, 0, 25);

    int res = 0;
    for(int i = 0; i < 26; ++i)
        res += (i / 8 + 1) * cache[i];

    printf("%d", res);
    return 0;
}

