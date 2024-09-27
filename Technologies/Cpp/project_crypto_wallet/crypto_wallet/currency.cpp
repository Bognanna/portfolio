#include "currency.h"

Currency::Currency(string curr_name, int curr_amount, float curr_value){
    name = new string;
    amount = new int;
    value = new float;
    *name = curr_name;
    *amount = curr_amount;
    *value = curr_value;
}

Currency::~Currency(){
    delete name;
    delete amount;
    delete value;
}

void Currency::introduce_yourself(){
    cout<<"Hi! I'am just "<<*name<<" coin of amount "<<to_string(*amount)<<endl;
}

void Currency::buy_curr_crypto(){
    (*amount)++;
}

float Currency::return_curr_value(){
    return *value;
}

int Currency::return_curr_amount(){
    return *amount;
}

string Currency::return_curr_name(){
    return *name;
}
