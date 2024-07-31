#include <stdio.h>

int isEqual(int arr1[], int arr2[], int n);

void main(){
    int arr1[] = {1, 2, 5, 4, 0, 2, 1};
    int arr2[] = {2, 4, 5, 0, 1, 1, 2};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    if(isEqual(arr1, arr2, n))
        printf("Yes");
    else    
        printf("No");
}

int isEqual(int arr1[], int arr2[], int n){
    int cache[100] = {0};
    
    for(int i = 0; i < n; i++)
        cache[arr1[i]] += 1;

    for(int i = 0; i < n; i++){
        if(cache[arr2[i]] == 0)
            return 0;
        cache[arr2[i]] -= 1;
    }

    return 1;
}
