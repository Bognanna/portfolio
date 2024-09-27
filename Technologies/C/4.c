#include<stdio.h>

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
