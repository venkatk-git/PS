/*
Merge Two Sorted Arrays
Given two sorted arrays arr1 and arr2 of sizes m and n respectively, 
merge them into a single sorted array without using extra space. 
Assume arr1 has enough space (size of m + n) to hold additional 
elements from arr2 if needed.
*/


#include <stdio.h>

void merger(int arr1[], int arr2[], int m, int n);

void main(){
    int arr1[] = {1, 3, 5, 0, 0, 0};
    int arr2[] = {2, 4, 6};

    merger(arr1, arr2, 6 - 3, 3);
}

void merger(int arr1[], int arr2[], int m, int n){
    int i = 0;
    int j = 0;
    int k = 0;

    int sortedArr[m + n];

    while(i < m && j < n){
        if(arr1[i] < arr2[j])
            sortedArr[k++] = arr1[i++];
        else   
            sortedArr[k++] = arr2[j++];
    }

    while(i < m)
        sortedArr[k++] = arr1[i++];

    while(j < n)
        sortedArr[k++] = arr2[j++];   

    for(int i = 0; i < m + n; i++)
        printf("%d ", sortedArr[i]);
}