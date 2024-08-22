/*
Insertion Sort
*/

#include <stdio.h>
#include "../../../utils/printArr.c"
#include "../../../utils/swap.c"

void insertionSort(int arr[], int n);

void main(){
    int arr[] = {2, 4, 7, 1, 0, 12, 10, 9, 20, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArr(arr, n);
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j - 1]){
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
    }
}



