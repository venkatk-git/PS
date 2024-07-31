#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int key);

void main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 26};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 26;

    int result = jumpSearch(arr, n, key);
    printf("%d", result);
}

int jumpSearch(int arr[], int n, int key){
    int s = 0; 
    int e = sqrt(n);

    while(arr[e] < key && s < n){
        s = e;
        e += sqrt(n);
        if(e > n){
            e = n - 1;
            break;
        } 
    }

    for(int i = s; i <= e; i++)
        if(arr[i] == key)
            return i;

    return -1;
}
