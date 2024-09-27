#include "curr_crypto.h"

Crypto::Crypto(string curr_name, int curr_amount, float curr_value): Currency(curr_name, curr_amount, curr_value){
    value = new float;
    *value = curr_value + 2;
}

void Crypto::introduce_yourself(){
    cout<<"Hi! I'am crypto "<<*name<<" coin of amount "<<to_string(*amount)<<endl;
}

