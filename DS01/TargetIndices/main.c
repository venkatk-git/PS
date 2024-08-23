/*
Find Target Indices After Sorting Array
---------------------------------------
You are given a 0-indexed integer array nums and a target element target.
A target index is an index i such that nums[i] == target.
Return a list of the target indices of nums after sorting nums in non-decreasing order. 
If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

Example: 
Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.
*/

#include <stdio.h>
#include "../../utils/swap.c"

void findIndices(int arr[], int n, int target);
void sort(int arr[], int s, int e);
void printArr(int arr[], int n);

void main(){
    int arr[] = {1, 2, 5, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    findIndices(arr, n, target);
}

void findIndices(int arr[], int n, int target){
    sort(arr, 0, n - 1);
    int res[n];
    int resN = 0;

    for(int i = 0; i < n; i++)
        if(arr[i] == target)
            res[resN++] = i;

    printArr(res, resN);
}

void sort(int arr[], int s, int e){
    if(s >= e) return;

    int pivot = arr[e];
    int startsWith = s;

    for(int i = s; i <= e; i++)
        if(arr[i] < pivot)  
            swap(&arr[i], &arr[startsWith++]);

    swap(&arr[e], &arr[startsWith]);
    sort(arr, s, startsWith - 1);
    sort(arr, startsWith + 1, e);
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        if(i == 0)
            if(n == 1)
                printf("[%d]", arr[i]);
            else 
                printf("[%d,", arr[i]);
        else if(i == n - 1)
            printf("%d]", arr[i]);
        else
            printf("%d,", arr[i]);
    }
}
