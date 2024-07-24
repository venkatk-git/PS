#include <stdio.h>

int find(int arr[], int n);

int main(){
    int arr[] = {3,4,5,1,2};
    printf("%d", arr[find(arr, 5)]);
    return 0;
}

int find(int arr[], int n){
    int l = 0;
    int r = n - 1;

    while(l <= r){
        int m = (l + r) / 2;
    
        if(arr[l] <= arr[r]){
            return arr[l];
        }

        if(arr[m] > arr[r]){
            l = m + 1;
        } else{
            r = m; 
        }
    }
    return -1;
}