#ifndef WALLET
#define WALLET

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

template <class Coin>

class Wallet{
private:
    string *owner;
    vector<Coin*> arr;
public:
    Wallet(string);
    ~Wallet();
    void operator+=(Coin &coin){
        arr.push_back(&coin);
    }
    void operator-=(int id){
        arr.erase(arr.begin() + id);
    }
    virtual void list_coins(); //prints the list of the coins in the wallet
    virtual int return_size(); //returns the size of the vector of coins
    virtual void buy_crypto(int);
    virtual float get_value(int); //allows to get the exchange rate of given by the index coin
    virtual int get_amount(int); //allows to get the amount of given by the index coin
    virtual string get_name(int); //allows to get the name of given by the index coin
    friend class Market;

};

template <class Coin>
Wallet<Coin>::Wallet(string name){
    owner = new string;
    *owner = name;
}

template <class Coin>
Wallet<Coin>::~Wallet(){
    delete owner;
}

template <class Coin>
void Wallet<Coin>::list_coins(){
    for(int i=0; i<arr.size(); ++i){
        cout<<"("<<i<<") ";
        arr[i]->introduce_yourself();
    }
}

template <class Coin>
int Wallet<Coin>::return_size(){
    return arr.size();
}

template <class Coin>
void Wallet<Coin>::buy_crypto(int i){
    arr[i]->buy_curr_crypto();
}

template <class Coin>
float Wallet<Coin>::get_value(int i){
    float v = arr[i]->return_curr_value();
    return v;
}

template <class Coin>
int Wallet<Coin>::get_amount(int i){
    int a = arr[i]->return_curr_amount();
    return a;
}

template <class Coin>
string Wallet<Coin>::get_name(int i){
    string n = arr[i]->return_curr_name();
    return n;
}
#endif // WALLET
