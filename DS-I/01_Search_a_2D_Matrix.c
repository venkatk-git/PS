/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if the target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.

Test case 1:
[[1,3,5,7],
[10,11,16,20],
[23,30,34,60]]
target = 3

Output: true

Test case 2:
Input:
[[1,3,5,7],
[10,11,16,20],
[23,30,34,60]], 
target = 13

Output: false
*/

#include<stdio.h> 
#include<stdbool.h>

bool search2d(int n, int m, int matrix[n][m], int t);
bool search (int *arr, int n, int t);

void main() {
    int n;
    int m;
    scanf("%d %d", &n, &m);
    
    int matrix[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int t; 
    scanf("%d", &t);

    printf(search2d(n, m, matrix, t) ? "true" : "false");
}

bool search2d (int n, int m, int matrix[n][m], int t) {
    int s = 0;
    int e = n - 1;

    while(s <= e) {
        int mid = (s + e) / 2;
        int f = matrix[mid][0];
        int l = matrix[mid][m - 1];

        if(t >= f && t <= l) {
            return search(matrix[mid], m, t);
        }

        if(t < f) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    return false;
}

bool search (int *arr, int n, int t) {
    int s = 0;
    int e = n - 1;

    while(s <= e) {
        int m = (s + e) / 2;

        if(arr[m] == t) {
            return true;
        }

        if(arr[m] < t) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }

    return false;
}