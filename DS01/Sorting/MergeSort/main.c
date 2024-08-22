/*
Merge Sort
*/

#include <stdio.h>
#include "../../../utils/printArr.c"

void mergeSort(int arr[], int s, int e);

void main(){
    int arr[] = {2, 4, 7, 1, 0, 12, 10, 9, 20, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    printArr(arr, n);
}

void mergeSort(int arr[], int s, int e){
    if(s < e){
        int m = (s + e) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m + 1, e);
        merger(arr, s, m, e);
    }
}

void merger(int arr[], int s, int m, int e){
    int Ln = m - s + 1;   
    int Rn = e - m;

    int L[Ln];
    int R[Rn];

    for(int i = 0; i < Ln; i++)
        L[i] = arr[s + i];
    
    for(int i = 0; i < Rn; i++)
        R[i] = arr[m + i + 1];
    
    int l = 0;
    int r = 0;
    int i = s;
    while(l < Ln && r < Rn){
        if(L[l] < R[r])
            arr[i++] = L[l++];
        else
            arr[i++] = R[r++];
    }

    while(l < Ln)  
        arr[i++] = L[l++];
    
    while(r < Rn)
        arr[i++] = R[r++];
}

