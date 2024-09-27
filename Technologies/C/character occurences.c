#include <stdio.h>

/* Write a full C program that will read a character and a word from the standard input.
The program should print all indices of occurrences of the character in the word in increasing order.
Note: The word will be no longer than 1 KiB (=1024 bytes).
    */

int main(){
    char c, l;
    scanf("%c", &c);
    int n = 0;
    while(scanf("%c", &l)){
        if(l == c)
            printf("%d ", n);
        n++;
    }
    return 0;
}

