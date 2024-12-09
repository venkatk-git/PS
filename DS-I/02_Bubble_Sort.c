/*
Sort the given array using "Bubble Sort" and print by every iteration of the Bubble Sort.

Input:
5
10 8 7 3 1

Output: 
Iteration 1 --> 8 7 3 1 10
Iteration 2 --> 7 3 1 8 10
Iteration 3 --> 3 1 7 8 10
Iteration 4 --> 1 3 7 8 10
Iteration 5 --> 1 3 7 8 10
Final Array --> 1 3 7 8 10
*/

#include<stdio.h>

void bubbleSort(int nums[], int n);
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

    bubbleSort(nums, n);

    printf("Final Array --> ");
    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }    
}

void bubbleSort(int nums[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(nums[j] > nums[j + 1]) {
                swap(&nums[j], &nums[j + 1]);
            }
        }
        printf("Iteration %d --> ", i + 1);
        for(int i = 0; i < n; i++) {
            printf("%d ", nums[i]);
        }  
        printf("\n");
    }
}
