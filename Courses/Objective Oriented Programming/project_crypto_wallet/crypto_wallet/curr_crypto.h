#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Crypto: public Currency{
public:
    Crypto(string, int, float);
    void introduce_yourself();
};


