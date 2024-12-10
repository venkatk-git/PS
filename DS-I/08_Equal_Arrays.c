/*
Given two arrays, arr1 and arr2 of equal length N, the task is to determine if the given arrays are equal or not. 

Two arrays are considered equal if:
Both arrays contain the same set of elements.
The arrangements (or permutations) of elements may be different.

If there are repeated elements, the counts of each element must be the same in both arrays.

Test Case 01:
Input: arr1[] = {1, 2, 5, 4, 0}, arr2[] = {2, 4, 5, 0, 1}

Test Case 2:
Input: arr1[] = {1, 2, 5, 4, 0, 2, 1}, arr2[] = {2, 4, 5, 0, 1, 1, 2}
Output: Yes
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isEquals(int *a, int n, int *b, int m);
void sort(int *nums, int n);

void main() {
    int n, *a;
    int m, *b;

    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    b = (int*)malloc(sizeof(int) * m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }


    if(isEquals(a, n, b, m)) {
        printf("Yes");
    } else {
        printf("No");
    }

    free(a);
    free(b);
}

bool isEquals(int *a, int n, int *b, int m) {
    if(n != m) return false;

    sort(a, n);
    sort(b, m);

    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

void sort(int *nums, int n) {
    for(int i = 0; i < n; i++) {
        int j = i;

        while(j > 0 && nums[j - 1] > nums[j]) {
            int temp = nums[j - 1];
            nums[j - 1] = nums[j];
            nums[j] = temp;
            j--;
        }
    }
}