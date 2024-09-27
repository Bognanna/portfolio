#include "market.h"

Market::Market(float sell_per, float buy_per){
    pSell = new float;
    pBuy = new float;
    *pSell = sell_per;
    *pBuy = buy_per;
}

Market::~Market(){
    delete pSell;
    delete pBuy;
}

void Market::trade(Wallet<Currency> &w){
    int s = w.return_size();
    int s_minus;
    float pS, pB;
    Money money("dollar", 0);

    while(w.return_size()!=0){
        s = w.return_size();
        s_minus = 0;
        for(int i=0; i<s; ++i){
            pS = rand()%100*0.01;
            pB = rand()%100*0.01;
            if(pB < *pBuy){
                money.operation(-1 * w.get_value(i-s_minus));
                cout<<"Bought "<<w.get_name(i-s_minus)<<endl;
                w.buy_crypto(i-s_minus);
                w.list_coins();
                money.saldo();
                cout<<endl;
            }

            if(pS < *pSell){
                money.operation(w.get_value(i-s_minus)*float(w.get_amount(i-s_minus)));
                cout<<"Sold "<<w.get_name(i-s_minus)<<endl;
                w-=(i-s_minus);
                w.list_coins();
                money.saldo();
                s_minus ++;
                cout<<endl;
            }
        }
    }

}
