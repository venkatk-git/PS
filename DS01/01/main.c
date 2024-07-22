#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int rowLen, int colLen,int matrix[][rowLen], int target);

void main(){
    int mat[][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    if(searchMatrix(3, 4, mat, 11)) printf("True");
    else printf("False");
    return;
}

bool searchMatrix(int rowLen, int colLen,int matrix[][rowLen], int target) {
        int rs = 0;
        int re = rowLen - 1;
        int cs = 0;
        int ce = colLen - 1;

        while (rs <= re) {
            int m1 = (rs + re) / 2;
            if (target >= matrix[m1][cs] && target <= matrix[m1][ce]) {
                int s = 0;
                int e = ce;
                while (s <= e) {
                    int m2 = (e + s) / 2;
                    if (matrix[m1][m2] == target) {
                        return true;
                    } else if (target < matrix[m1][m2]) {
                        e = m2 - 1;
                    } else if (target > matrix[m1][m2]) {
                        s = m2 + 1;
                    }
                }
                return false;
            } else if (target < matrix[m1][0]) {
                re = m1 - 1;
            } else if (target > matrix[m1][ce]) {
                rs = m1 + 1;
            }
        }
        return false;
}