/*
Selection Sort
*/

#include <stdio.h>
#include "../../../utils/printArr.c"
#include "../../../utils/swap.c"

void selectionSort(int arr[], int n);

void main(){
    int arr[] = {2, 4, 7, 1, 0, 12, 10, 9, 20, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    printArr(arr, n);
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int currMin = i;

        for(int j = i; j < n; j++)
            if(arr[j] < arr[currMin])
                currMin = j;

        swap(&arr[i], &arr[currMin]);
    }
}
