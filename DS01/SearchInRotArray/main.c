/*
Search a element in Sorted but Rotated Array
Example:
arr = [4, 5, 6, 7, 8, 1, 2, 3]
el = 7
Output:
3 (arr[3] = 7)
*/

#include <stdio.h>

int search(int arr[], int n, int el);

void main(){
    int arr[] = {5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int el = 5; 

    printf("%d", search(arr, n, el));
}

int search(int arr[], int n, int el){
    int s = 0;
    int e = n - 1;
    int m;

    while(s <= e){
        m = (s + e) / 2;
        if(arr[m] == el)
            return m;
        
        if(arr[m] >= arr[s]){
            if(el >= arr[s] && el <= arr[m])
                e = m - 1;
            else
                s = m + 1;
        }
        
        if(arr[m] <= arr[e]){
            if(el >= arr[m] && el <= arr[e])
                s = m + 1;
            else 
                e = m - 1;
        }
    }

    return -1;
}