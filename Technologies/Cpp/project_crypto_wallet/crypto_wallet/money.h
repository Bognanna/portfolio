#ifndef MONEY
#define MONEY

#include<iostream>
#include<cstdio>
using namespace std;

class Money{
private:
    string *name;
    float *amount;
public:
    Money(string, float);
    ~Money();
    void operation(float);
    void saldo();
};

#endif // MONEY
