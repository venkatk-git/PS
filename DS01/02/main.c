/*
Finding a Specific Product in a Sorted Inventory using Binary Search:
You have a sorted array inventory that contains the names of all the products in the store's inventory.
A customer comes to you and asks if the store has the product "Wireless Headphones". Your goal is to write
a function that can efficiently determine whether the requested product is in the
store's inventory and, if so, return its index in the inventory array using binary search.
*/

#include <stdio.h>
#include <string.h>

int search(int n, char *inventory[n], char *target);

void main(){
    char *inventory[5] = {"Bluetooth Speaker", "Laptop Bag", "Wired Earbuds", "Wireless Headphones", "Wireless Mouse"};

    char *target = "Wired Earbuds";
    int result = search(5, inventory, target);

    printf("%d",result);
    return; 
}

int search(int n, char *inventory[n], char *target){
    int start = 0;
    int end = n - 1;
    int mid;

    while(start <= end){
        mid = (start + end) / 2;
        int cmp = strcmp(inventory[mid], target);

        if(cmp == 0)
            return mid;
        
        if (cmp < 0)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;

}