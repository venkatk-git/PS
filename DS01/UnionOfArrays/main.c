/*
Union of Arrays
---------------
*/
#include <stdio.h>

void unionArr(int arr1[], int arr2[], int n, int m);

void main(){
    int arr1[] = {1, 2, 3, 5};
    int arr2[] = {1, 5, 8, 7, 3};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    unionArr(arr1, arr2, n, m);
}

void unionArr(int arr1[], int arr2[], int n, int m){
    int cache[100] = {0};
    for(int i = 0; i < n; i++)
        cache[arr1[i]]++;

    int res[n + m];
    int len = 0;
    for(int i = 0; i < n; i++){
        if(cache[arr1[i]] != -1)
            res[len++] = arr1[i];
        cache[arr1[i]] = -1;
    }

    for(int i = 0; i < m; i++){
        if(cache[arr2[i]] != -1)
            res[len++] = arr2[i];
        cache[arr2[i]] = -1;
    }

    for(int i = 0; i < len; i++)
        printf("%d ", res[i]);
}
