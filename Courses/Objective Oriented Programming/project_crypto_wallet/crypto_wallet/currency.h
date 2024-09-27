#ifndef CURRENCY
#define CURRENCY

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Currency{
protected:
    string *name;
    int *amount;
    float *value;
public:
    Currency(string, int, float);
    ~Currency();
    virtual void introduce_yourself();
    virtual void buy_curr_crypto();
    virtual float return_curr_value();
    virtual int return_curr_amount();
    virtual string return_curr_name();
};

#endif // CURRENCY
