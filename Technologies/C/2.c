#include <stdio.h>


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

