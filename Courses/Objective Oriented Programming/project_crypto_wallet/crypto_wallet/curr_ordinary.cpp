#include "curr_ordinary.h"

Ordinary::Ordinary(string curr_name, int curr_amount, float curr_value): Currency(curr_name, curr_amount, curr_value){
    value = new float;
    *value = curr_value + 5;
}

void Ordinary::introduce_yourself(){
    cout<<"Hi! I'am ordinary "<<*name<<" coin of amount "<<to_string(*amount)<<endl;
}
