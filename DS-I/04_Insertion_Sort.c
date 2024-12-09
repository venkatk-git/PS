/*
Sort the given array using "Insertion Sort" and print by every iteration of the Insertion Sort.

Input:
5
10 8 7 3 1

Output: 
Iteration 1 --> 8 10 7 3 1 
Iteration 2 --> 7 8 10 3 1 
Iteration 3 --> 3 7 8 10 1 
Iteration 4 --> 1 3 7 8 10 
Final Array --> 1 3 7 8 10
*/

#include<stdio.h>

void insertionSort(int nums[], int n);
void swap(int *a, int *b) {
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

    insertionSort(nums, n);

    printf("Final Array --> ");
    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }    
}

void insertionSort(int nums[], int n) {
    for(int i = 1; i < n; i++) {
        int j = i;

        while(j > 0 && nums[j - 1] > nums[j]) {
            swap(&nums[j - 1], &nums[j]);
            j--;
        }

        // Printing current iteration
        printf("Iteration %d --> ", i);
        for(int i = 0; i < n; i++) {
            printf("%d ", nums[i]);
        }  
        printf("\n");
    }
}
