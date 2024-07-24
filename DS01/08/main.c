#include <stdio.h>

void sort(int arr[], int n);

int main(){
    int arr[] = {10, 4, 8, 2, 6, 7, 1, 5, 9, 3};
    sort(arr, 10);
    int k = 0;
    scanf("%d", &k);
    printf("%d", arr[k - 1]);
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}