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

void counting_sort(int tab[],int tab_size)
{
    int range=0;
    int unsorted[tab_size];
    for(int i=0;i<tab_size;i++)
    {
        range=max(range,tab[i]);
        unsorted[i]=tab[i];
    }
    int counting_tab[range+1];
    for(int i=0;i<range+1;i++){counting_tab[i]=0;}
    for(int i=0;i<tab_size;i++){counting_tab[tab[i]]++;}
    for(int i=1;i<range+1;i++){counting_tab[i]+=counting_tab[i-1];}
    for(int i=0;i<tab_size;i++){tab[counting_tab[unsorted[i]]-1]=unsorted[i];counting_tab[unsorted[i]]--;}
    //tab=sorted;
    //for(int i=0;i<tab_size;i++){cout<<sorted[i]<<endl;}
}

int main()
{
    srand (time(NULL));
    int n_el=100;
    int tab[n_el];
    cout<<"Counting sort"<<endl;
    for(int i=0;i<n_el;i++)
    {
        tab[i]=rand() % 100 + 1;
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    cout<<endl;
    counting_sort(tab,n_el);
    for(int i=0;i<n_el;i++){cout<<tab[i]<<", ";}
}


