#include <stdio.h>
#include <string.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

