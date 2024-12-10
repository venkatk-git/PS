/*
You are given a sorted array of integers in ascending order. 
Write a program to implement a binary search algorithm to find the position of a given integer in the array. 
If the integer is found, the program should return its position (index), otherwise, 
it should return -1 indicating that the integer is not present in the array.

Input: 
Array: [3, 8, 12, 16, 21, 39, 42, 54] 
Search Element: 16

Expected Output: 
Position/Index: 3
*/

#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *nums, int n, int t);

void main() {
    int n, *nums, t;
    scanf("%d", &n);

    nums = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &t);

    int ans = binarySearch(nums, n, t);
    printf("%d", ans);

    free(nums);
}

int binarySearch(int *nums, int n, int t) {
    int l = 0; 
    int r = n - 1;

    while(l <= r) {
        int m = (l + r) / 2;

        if(nums[m] == t) {
            return m;
        }

        if(nums[m] < t) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return -1;
}