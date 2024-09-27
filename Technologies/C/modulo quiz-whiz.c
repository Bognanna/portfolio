#include<stdio.h>

/* Write a full C program that reads an integer from standard input and prints:
- the word 'Quiz' if the given number is divisible by 5,
- the word 'Whiz' if the given number is divisible by 7,
- the word 'QuizWhiz' if the given number is divisible by both 5 and 7,
- the number itself otherwise.
    */

int main(){
    int n;
    scanf("%d", &n);
    if(n%5 == 0 && n%7 == 0)
        printf("QuizWhiz");
    else if(n%5 == 0)
        printf("Quiz");
    else if(n%7 == 0)
        printf("Whiz");
    else
        printf("%d", n);

    return 0;
}
