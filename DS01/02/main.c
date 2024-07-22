#include <stdio.h>
#include <string.h>

int search(int n, char *inventory[n], char *target);

void main(){
    char *inventory[5] = {"Bluetooth Speaker", "Laptop Bag", "Wireless Headphones", "Wired Earbuds", "Wireless Mouse"};

    char *target = "Laptop Bag";
    int result = search(5, inventory, target);

    printf("%d",result);
    return; 
}

int search(int n, char *inventory[n], char *target){
    int l = 0;
    int r = n;

    while(l <= r){
        int m = (l + r) / 2;
        int cmpVal = strcmp(inventory[m],target);
        
        if(cmpVal == 0) return m;
        else if(cmpVal > 0){
            r = m - 1;
        } else{
            l = m + 1;
        }
    }

    return -1;
}