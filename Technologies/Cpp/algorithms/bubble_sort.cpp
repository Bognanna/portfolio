#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <math.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

void bubble(int tab[], int s){
    for(int i=0;i<s-1;i++){
        for(int j=0;j<s-1;j++){
            if(tab[j]>tab[j+1])
                swap(tab[j+1],tab[j]);
        }
    }

}

int main()
{
    srand (time(NULL));
    int n_el=100;
    int tab[n_el];
    cout<<"Bubble sort"<<endl;
    for(int i=0;i<n_el;i++)
    {
        tab[i]=rand() % 100 + 1;
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    cout<<endl;
    bubble(tab,n_el);
    for(int i=0;i<n_el;i++){cout<<tab[i]<<", ";}
    return 0;
}


