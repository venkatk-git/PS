/*
Insertion Sort
*/

#include <stdio.h>

void insertionSort(int arr[], int n);
void printArr(int arr[], int n);
void swap(int *a, int *b);

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

