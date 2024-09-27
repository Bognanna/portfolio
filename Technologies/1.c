#include<stdio.h>
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
