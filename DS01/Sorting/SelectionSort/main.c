/*
Selection Sort
*/

#include <stdio.h>

void selectionSort(int arr[], int n);
void printArr(int arr[], int n);
void swap(int *a, int *b);

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
