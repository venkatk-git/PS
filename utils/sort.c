#include <stdio.h>

void quickSort(int arr[], int s, int e);

void sort(int arr[], int n){
    quickSort(arr, 0, n - 1);
}

void quickSort(int arr[], int s, int e){
    if(s >= e) return;

    int pivot = arr[e];
    int startsWith = s;

    for(int i = s; i < e; i++)
        if(arr[i] < pivot)
            swap(&arr[i], &arr[startsWith++]);

    swap(&arr[e], &arr[startsWith]);

    quickSort(arr, s, startsWith - 1);
    quickSort(arr, startsWith + 1, e);
}