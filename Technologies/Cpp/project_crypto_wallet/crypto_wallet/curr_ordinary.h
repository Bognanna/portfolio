#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Ordinary: public Currency{
public:
    Ordinary (string, int, float);
    void introduce_yourself();
};


