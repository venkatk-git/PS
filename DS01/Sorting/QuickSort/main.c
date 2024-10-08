/*
Quick Sort
*/

#include <stdio.h>
#include "../../../utils/printArr.c"
#include "../../../utils/swap.c"

void quickSort(int arr[], int s, int e);

void main(){
    int arr[] = {2, 4, 7, 1, 0, 12, 10, 9, 20, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    printArr(arr, n);
}

void quickSort(int arr[], int s, int e){
    if(s < e){
        int pivot = arr[e];
        int startsWith = s;

        for(int i = s; i < e; i++){
            if(arr[i] < pivot)
                swap(&arr[i], &arr[startsWith++]);
        }

        swap(&arr[e], &arr[startsWith]);
        
        quickSort(arr, s, startsWith - 1);
        quickSort(arr, startsWith + 1, e);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[], int n){
    printf("[");

    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
        if(i != n - 1)
            printf(", ");
    }
    
    printf("]");
}
