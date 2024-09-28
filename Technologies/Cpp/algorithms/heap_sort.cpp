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


void heapify(int tab[], int idx,int tab_size)
{
    int l=2*idx+1;
    int r=l+1;
    int biggest=idx;
    if(l < tab_size && tab[l] > tab[biggest]){biggest=l;}
    if(r < tab_size && tab[r] > tab[biggest]){biggest=r;}

    if(biggest!=idx)
    {
        swap(tab[idx],tab[biggest]);
        heapify(tab,biggest,tab_size);
    }
}

void heapsort(int tab[], int tab_size)
{
    for(int i=(tab_size/2)-1;i>=0;i--)
    {
        heapify(tab,i,tab_size);
    }
    for(int i=tab_size-1;i>0;i--)
    {
        swap(tab[0],tab[i]);
        heapify(tab,0,i);
    }
}


int main()
{
    srand (time(NULL));
    int n_el=100;
    int tab[n_el];
    cout<<"Heap sort"<<endl;
    for(int i=0;i<n_el;i++)
    {
        tab[i]=rand() % 100 + 1;
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    cout<<endl;
    heapsort(tab,n_el);
    for(int i=0;i<n_el;i++){cout<<tab[i]<<", ";}
}


