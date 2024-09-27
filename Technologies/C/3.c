#include<stdio.h>

int main(){
    char name[20];
    char surname[20];
    int age;
    float income;
    scanf("%s %s %d %f", &name, &surname, &age, &income);
    printf("%s %s %d %.2f", name, surname, age, income);

    return 0;
}
