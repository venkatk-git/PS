#include <stdio.h>

int floorSearch(int arr[], int n, int x);

int main(){
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 0;

    int result = floorSearch(arr, n, x);
    printf("%d",result);
}

int floorSearch(int arr[], int n, int x){
    if(arr[n - 1] < x)
        return arr[n - 1];
    
    if(arr[0] > x)
        return -1;

    for(int i = 0; i < n; i++){
        if(arr[i] > x){
            return arr[i - 1];
        }
    }

    return -1;
}