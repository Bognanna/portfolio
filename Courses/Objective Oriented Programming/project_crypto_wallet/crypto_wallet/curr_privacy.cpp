#include "curr_privacy.h"

Privacy::Privacy(string curr_name, int curr_amount, float curr_value): Currency(curr_name, curr_amount, curr_value){
    value = new float;
    *value = curr_value + 3;
}

void Privacy::introduce_yourself(){
    cout<<"Hi! I'am privacy "<<*name<<" coin of amount "<<to_string(*amount)<<endl;
}
