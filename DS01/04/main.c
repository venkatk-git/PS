#include <stdio.h>
#include <stdlib.h>

int *sort(int *arr1, int *arr2, int n, int m);

int main(){
    int arr1[] = {1, 3, 5, 0, 0, 0};
    int arr2[] = {2, 4, 6, 8, 10};
    int *sortedArr = sort(arr1, arr2, 3, 5);

    for(int i = 0; i < 3 + 5; i++){
        printf("%d ", sortedArr[i]);
    }

    return 0;
}

int *sort(int *arr1, int *arr2, int n, int m){
    int *sortedArr = malloc(n + m + 1 * sizeof(int));
    int k = 0;
    int i = 0;
    int j = 0;

    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
            sortedArr[k] = arr1[i];
            i++;
        } else{
            sortedArr[k] = arr2[j];
            j++;
        }

        k++;
    }

    while(i < n){
        sortedArr[k] = arr1[i];
        i++; k++;
    }

    while(j < m){
        sortedArr[k] = arr2[j];
        j++; k++;
    }

    return sortedArr;
}