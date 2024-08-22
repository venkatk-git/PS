/*
Bubble Sort
*/

#include <stdio.h>

void bubbleSort(int arr[], int n);
#include "../../../utils/printArr.c"
#include "../../../utils/swap.c"

void main(){
    int arr[] = {2, 4, 7, 1, 0, 12, 10, 9, 20, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);
    printArr(arr, n);
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n - i; j++){
            if(arr[j] < arr[j - 1])
                swap(&arr[j], &arr[j - 1]);
        }
    }
}
