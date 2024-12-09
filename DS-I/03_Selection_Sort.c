/*
Sort the given array using "Selection Sort" and print by every iteration of the Selection Sort.

Input:
5
10 8 7 3 1

Output: 
Iteration 1 --> 1 8 7 3 10
Iteration 2 --> 1 3 7 8 10
Iteration 3 --> 1 3 7 8 10
Iteration 4 --> 1 3 7 8 10
Iteration 5 --> 1 3 7 8 10
Final Array --> 1 3 7 8 10
*/

#include<stdio.h>

void selectionSort(int nums[], int n);
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

    selectionSort(nums, n);

    printf("Final Array --> ");
    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }    
}

void selectionSort(int nums[], int n) {
    for(int i = 0; i < n; i++) {
        
        int minIndex = i;
        
        for(int j = i + 1; j < n; j++) {
            if(nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        
        swap(&nums[i], &nums[minIndex]);

        // Printing current iteration
        printf("Iteration %d --> ", i + 1);
        for(int i = 0; i < n; i++) {
            printf("%d ", nums[i]);
        }  
        printf("\n");
    }
}
