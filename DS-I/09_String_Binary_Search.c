/*
You have a sorted array inventory that contains the names of all the products in the store's inventory. 
A customer comes to you and asks if the store has the product "Wireless Headphones".

Your goal is to write a function that can efficiently determine whether the requested product is in the store's inventory and, 
if so, return its index in the inventory array using binary search.

Test Case 01:
Input:
inventory = ["Bluetooth Speaker", "Laptop Bag", "Wireless Headphones", "Wired Earbuds", "Wireless Mouse"]
target = "Wireless Headphones"

Output: 
2

Test Case 02:
Input:
inventory = ["Bluetooth Speaker", "Laptop Bag", "Wireless Headphones", "Wired Earbuds", "Wireless Mouse"]
target = "Smartphone"

Output:
-1
*/
#include<stdio.h>
#include<string.h>

int binarySearchOnString(char **strArr, int n, char *str);
void sortStrings(char **strArr, int n);

void main() {
    int n = 5;
    char *strArr[] = {"Bluetooth Speaker", "Laptop Bag", "Wireless Headphones", "Wired Earbuds", "Wireless Mouse"};
    char *str = "Laptop Bag";

    printf("%d", binarySearchOnString(strArr, n, str));
}

int binarySearchOnString(char **strArr, int n, char *str) {
    int s = 0;
    int e = n - 1;
    sortStrings(strArr, n);

    while(s <= e) {
        int m = (s + e) / 2;

        if(strcmp(strArr[m], str) == 0) {
            return m;
        }

        if(strcmp(strArr[m], str) < 0) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }    

    return -1;
}

void sortStrings(char **strArr, int n) {
    for(int i = 1; i < n; i++) {
        int j = i;
        
        while(j > 0 && strcmp(strArr[j - 1], strArr[j]) > 0) {
            char *temp = strArr[j - 1];
            strArr[j - 1] = strArr[j];
            strArr[j] = temp;
        }
    }
}
