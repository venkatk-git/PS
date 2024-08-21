/*
Maximum product of three elements in a given array.
Example 1:
arr = [1,2,3,4]
Output : 24  
Example 2: 
arr = [1, 5, 9, 100, -100, 20, 3, 23, 200, -25]
Output : 500000
*/

#include <stdio.h>

int maxProductThree(int arr[], int n);
int max(int a, int b);
void sort(int arr[], int n);
void swap(int *a, int *b);

void main(){
    int arr[] = {1, 5, 9, 100, -100, 20, 3, 23, 200, -25};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);
    int result = maxProductThree(arr, n);
    printf("%d", result);
}

int maxProductThree(int arr[], int n){
    int a = arr[n - 1];
    int b = arr[n - 2];
    int c = arr[n - 3];

    int max1 = a * b * c;
    int max2 = arr[0] * arr[1] * a;

    return max(max1, max2);
}

int max(int a, int b){
    return a > b ? a : b;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n - i; j++){
            if(arr[j] < arr[j - 1])
                swap(&arr[j], &arr[j - 1]);
        }
    }
}