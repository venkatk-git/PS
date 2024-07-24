#include <stdio.h>

int search(int *arr, int n, int t);

int main(){
    int arr[] = {1,2,3,4,5,6};
    printf("%d", search(arr, 6, 45));
    return 0;
}

int search(int *arr, int n, int t){
    int l = 0;
    int r = n - 1;
    
    while (l <= r){
        int m = (l + r) / 2;

        if(arr[m] == t) return m;
        else if(arr[m] > t) r = m - 1;
        else l = m + 1;
    }

    return -1;
}