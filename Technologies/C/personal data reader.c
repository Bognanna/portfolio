#include<stdio.h>

/* Write a program in C that reads the following entries from the standard input:
first name, last name, age, and income.
The program should fill the provided structure with the data.
    */
int main(){
    char name[20];
    char surname[20];
    int age;
    float income;
    scanf("%s %s %d %f", &name, &surname, &age, &income);
    printf("%s %s %d %.2f", name, surname, age, income);

    return 0;
}
