#ifndef MARKET
#define MARKET

#include <iostream>
#include <cstdio>
#include "wallet.h"
#include "currency.h"
#include "money.h"
using namespace std;

class Market{
private:
    float *pSell;
    float *pBuy;
public:
    Market(float, float);
    ~Market();
    void trade(Wallet<Currency>&);
};


#endif // MARKET
