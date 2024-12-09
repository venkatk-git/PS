/*
Sort the given array using "Merge Sort".

Input:
5
10 8 7 3 1

Output:
1 3 7 8 10
*/

#include<stdio.h>

void mergeSort(int nums[], int s, int e);
void merger(int nums[], int s, int m, int e);

void main() {
    int n;
    
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    mergeSort(nums, 0, n - 1);

    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
}

void mergeSort(int nums[], int s, int e) {
    if(s < e) {
        int m = (s + e) / 2;

        mergeSort(nums, s, m);
        mergeSort(nums, m + 1, e);
        merger(nums, s, m, e);
    }
}

void merger(int nums[], int s, int m, int e) {
    int ln = m - s + 1;
    int rn = e - m;

    int L[ln];
    for(int i = 0; i < ln; i++) {
        L[i] = nums[i + s];
    }

    int R[rn];
    for(int i = 0; i < rn; i++) {
        R[i] = nums[m + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = s;

    while(i < ln && j < rn) {
        if(L[i] < R[j]) {
            nums[k++] = L[i++];
        } else {
            nums[k++] = R[j++];
        }
    }

    while(i < ln) {
        nums[k++] = L[i++];
    }

    while(j < rn) {
        nums[k++] = R[j++];
    }
}