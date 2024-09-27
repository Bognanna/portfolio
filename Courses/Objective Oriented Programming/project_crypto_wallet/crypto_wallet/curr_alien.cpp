#include "curr_alien.h"


Alien::Alien(string curr_name, int curr_amount, float curr_value): Currency(curr_name, curr_amount, curr_value){
    value = new float;
    *value = curr_value + 1;
}

void Alien::introduce_yourself(){
    cout<<"Hi! I'am alien "<<*name<<" coin of amount "<<to_string(*amount)<<endl;
}
