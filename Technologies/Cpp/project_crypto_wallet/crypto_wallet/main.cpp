#include <iostream>
#include <cstdio>
#include <random>
#include <ctime>
#include <vector>
#include <string>

#include "wallet.h"
#include "market.h"
#include "currency.h"
#include "curr_privacy.h"
#include "curr_crypto.h"
#include "curr_ordinary.h"
#include "curr_alien.h"
#include "money.h"
using namespace std;

/*
Quick explanation:
In all the classes of Wallet project:
Value - means the exchange rate of given coin (currency)
Amount - the number of coins (int)

The Money class is the non crypto-currency class
The Currency calass is the class of all the crypto-currencies
The Market class performes the trade() operation
*/

//arrays which are used to create random coin names
string names[10] = {"Amy", "Bob", "Cloe", "David", "Eric", "Franz", "Hagrid", "Ines", "John", "Katy"};
string prefixes[10] = {"de", "von", "el", "van", "super", "der", "die", "das", "dem", "den"};
string surnames[10] = { "White", "Yellow", "Orange", "Red", "Pink", "Purple", "Blue", "Green", "Gray", "Black"};

//function, which returns the random name of the coin
string coin_name(){
    return names[rand()%10]+" "+prefixes[rand()%10]+surnames[rand()%10];
}

//function, which prints all the coins form the wallet
void print_coins(Wallet<Currency> &w){
    cout<<endl;
    w.list_coins();
}

//function which displays instruction
void instruction(){
    cout<<endl;
    cout<<"-> Type 1 to list all available coins\n";
    cout<<"-> Type 2 to add new coins to the wallet\n";
    cout<<"-> Type 3 to remove coins from the wallet\n";
    cout<<"-> Type 4 to trade\n";
    cout<<"-> Type 5 to exit\n";
}

//function which adds a coin to the wallet
void add_new_coins(Wallet<Currency> *w){
    string coin_name; int amount;
    cout<<"Type name of the coin: ";
    cin>>coin_name;
    cout<<"Type amount of the coin: ";
    cin>>amount;

    int x1;
    Currency** curr = new Currency* [1];
    cout<<endl;
    cout<<"-> Type 1 to add privacy coin\n";
    cout<<"-> Type 2 to add ordinary coin\n";
    cout<<"-> Type 3 to add alien coin\n";
    cout<<"-> Type 4 to add crypto coin\n";
    cin>>x1;
    switch(x1){
    case 1:
        curr[0] = new Privacy( coin_name, amount, rand()%100 * 0.001);
        break;
    case 2:
        curr[0] = new Ordinary( coin_name, amount, rand()%100 * 0.001);
        break;
    case 3:
        curr[0] = new Alien( coin_name, amount, rand()%100 * 0.001);
        break;
    case 4:
        curr[0] = new Crypto( coin_name, amount, rand()%100 * 0.001);
        break;
    default:
        return;
    }
    *w+=*curr[0]; //operand += allows to add a coin to the wallet
    cout<<"Done"<<endl;
}

//function which removes given coin, the coin must be pointed by its index
void remove_coins(Wallet<Currency> *w){
    int x1;
    cout<<"Give the index of the coin you want to remove: ";
    cin>>x1;
    *w-=x1;

}

//function which starts the trade operation
void trade(Wallet<Currency> *w){
    float pS; float pB;
    cout<<"Enter the probability of selling coins: ";
    cin>>pS;
    cout<<"Enter the probability of buying coins: ";
    cin>>pB;
    Market market(pS, pB);
    market.trade(*w);
}

int main(){
    srand(time(NULL));

    string owner;
    cout<<"Set the wallet's owner name"<<endl;
    cin>>owner;
    cin.clear();

    int n;
    cout<<"Set number of random coins"<<endl;
    cin>>n;
    cin.clear();

    Wallet<Currency> wallet(owner); //the wallet is created
    Currency** curr = new Currency* [n];
    //the loop which creates given by the user number of random coins
    for(int i=0; i<n; ++i){
        if(rand()%4==0){
            curr[i] = new Privacy( coin_name(), rand()%10+1, rand()%100 * 0.001);
        }else if(rand()%4==1){
            curr[i] = new Crypto( coin_name(), rand()%10+1, rand()%100 * 0.001);
        }else if(rand()%4==2){
            curr[i] = new Ordinary( coin_name(), rand()%10+1, rand()%100 * 0.001);
        }else{
            curr[i] = new Alien( coin_name(), rand()%10+1, rand()%100 * 0.001);
        }
        wallet+=*curr[i]; //operand += allows to add a coin to the wallet
    }

    //Application
    char answer = 'n';
    int x;
    instruction();
    while(true){
        cout<<endl<<"Enter the number of action: ";
        cin>>x;
        cin.clear();
        switch(x){
        case 1:
            print_coins(wallet);
            break;
        case 2:
            add_new_coins(&wallet);
            break;
        case 3:
            remove_coins(&wallet);
            break;
        case 4:
            trade(&wallet);
            break;
        case 5:
            cout<<"Do you want to exit? [y/n]: ";
            cin>>answer;
            cin.clear();
            break;
        default:
            cout<<"Invalid input. Need some help?\n";
            instruction();
        }

        if(answer=='y' || answer=='Y')
            break;
    }

    return 0;
}
