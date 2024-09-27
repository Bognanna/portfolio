#include<stdio.h>

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
