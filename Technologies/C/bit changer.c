#include<stdio.h>

/* Write a C program that reads two unsigned integers from the standard input.
The second integer is a bit position (0-31). The program should print the value
of the first integer with the bit set to 1 on the given position.
    */

int main(){
    int n, b;
    scanf("%d %d", &n, &b);
    int bin = 1;
    for(int i=0;i<b;++i){
        bin= bin*2;
    }

    n = n|bin;
    printf("%d", n);
    return 0;
}
