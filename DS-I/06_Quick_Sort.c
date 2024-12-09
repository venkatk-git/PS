/*
Sort the given array using "Quick Sort".

Input:
5
10 8 7 3 1

Output:
1 3 7 8 10
*/

#include<stdio.h>

void quickSort(int nums[], int s, int e);
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main() {
    int n;
    
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    quickSort(nums, 0, n - 1);

    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
}

void quickSort(int nums[], int s, int e) {
    if(s < e) {
        int pivot = nums[e];
        int swapWith = s;

        for(int i = s; i < e; i++) {
            if(nums[i] <= pivot) {
                swap(&nums[i], &nums[swapWith++]);
            }
        }

        swap(&nums[swapWith], &nums[e]);
        quickSort(nums, s, swapWith - 1);
        quickSort(nums, swapWith + 1, e);
    }
}
