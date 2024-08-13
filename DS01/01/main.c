/*
Search a 2D Matrix:
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if the target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity
*/

#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int arr[], int n, int target);
bool matrixSearch(int m, int n, int matrix[m][n], int target);

int main(){
    int m = 4;
    int n = 4;
    int matrix[][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 13;
    if(matrixSearch(m, n, matrix, target))
        printf("True");
    else 
        printf("False");
    
    return 0;
}

bool binarySearch(int arr[], int n, int target){
    int start = 0;
    int end = n - 1;
    int mid;

    while(start <= end){
        mid = (start + end) / 2;
        int currVal = arr[mid];
        if(currVal == target)
            return true;
        
        if(target < currVal)
            end = mid - 1;
        else 
            start = mid + 1;
    }

    return false;
}

bool matrixSearch(int m, int n, int matrix[m][n], int target){
    int start = 0; 
    int end = m - 1;
    int mid;

    while(start <= end){
        mid = (start + end) / 2;
        
        if(target >= matrix[mid][0]  && target <= matrix[mid][n - 1])
            return binarySearch(matrix[mid], n, target);
        
        if(target < matrix[mid][0])
            end = mid - 1;
        else    
            start = mid + 1;
    }

    return false;
}


