#include "money.h"

Money::Money(string money_name, float money_amount){
    name = new string;
    amount = new float;
    *name = money_name;
    *amount = money_amount;
}

Money::~Money(){
    delete name;
    delete amount;
}

void Money::operation(float a){
    *amount = *amount + a;
}

void Money::saldo(){
    cout<<"Saldo: "<<*amount<<" "<<*name<<endl;
}

