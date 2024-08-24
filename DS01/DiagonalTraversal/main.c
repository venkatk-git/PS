/*
Diagonal Traversal
------------------
Given a matrix of 2D array of n rows and m columns. Print this matrix in ZIG-ZAG fashion as shown in figure. 
Example:
Input: {
    {1, 2, 3}
    {4, 5, 6}
    {7, 8, 9}
}
Output: [1, 2, 4, 7, 5, 3, 6, 8, 9]
*/

#include <stdio.h>
#include <stdbool.h>
#include "../../utils/printArr.c"

void zigzag(int n, int m, int matrix[n][m]);

int main(){
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);
    
    zigzag(n, m, matrix);
    return 0;
}

void zigzag(int n, int m, int matrix[n][m]){
    int arr[m * n];
    int k = 0;
    bool r = true;
    int i = 0, j = 0;

    while(i < n && j < m){
        if(r){
            arr[k++] = matrix[i][j];
            
            if(j + 1 < m)
                j += 1;
            else
                i += 1;
            
            while (i + 1 < n && j - 1 >= 0)
                arr[k++] = matrix[i++][j--];
        } else{
            arr[k++] = matrix[i][j];

            if(i + 1 < n)
                i += 1;
            else 
                j += 1;

            while (i - 1 >= 0 && j + 1 < m)
                arr[k++] = matrix[i--][j++];
        }
        
        r = !r;
    }

    printArr(arr, m*n);
}