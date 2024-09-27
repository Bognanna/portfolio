#include<stdio.h>
/*
Write a program to count how many input numbers are positive (i.e. > 0).
The input of the program will consist of any number of real values.
    */
int main()
{
    int n=0;
    double f;
    while(scanf("%lf", &f)){
        //printf("f %f",f);
        if(f>0){
            n+=1;
        }
    }
    printf("%d",n);

    return 0;
}
