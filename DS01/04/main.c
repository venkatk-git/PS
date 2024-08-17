/*
Find Minimum in Rotated Sorted Array:
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.

For example, the array nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array 
[a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.
*/

#include <stdio.h>

int minInRotArray(int nums[], int n);

void main(){
    int nums[] = {3, 1, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int minVal = minInRotArray(nums, n);
    printf("%d", minVal);
}

int minInRotArray(int nums[], int n){
    int s = 0;
    int e = n - 1;
    int m;

    while(s <= e){
        if(nums[s] <= nums[e])
            return nums[s];

        m = (s + e) / 2;

        if(nums[m] < nums[s]){
            e = m;
        } else{
            s = m + 1;
        }
    }
}
