#include<iostream>
#include<ctime>
#include<fstream>
#include<cmath>
#include <stdlib.h>
#include "BS.hpp"
#include "HS.hpp"
#include "CS.hpp"
#include "SHS.hpp"
using namespace std;

void show_tab(int tab[], int n){

    for(int i = 0; i<n; ++i){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    fstream plik;
    srand (time(NULL));
    plik.open("dane.csv",ios::in|ios::app);
    plik<<"n,"<<"BS,"<<"HS,"<<"CS,"<<"SHS"<<endl;
    if (plik.good())
    {
        cout<<"Git"<<endl;
    }
    clock_t start,endu;
    for(int i=1000;i<=15000;i+=1000)
    {
        int tab[i];
        int tab_to_sort[i];
        for(int j=0;j<i;++j)
        {
            tab[j]=rand()%100000+1;
        }
        plik<<i<<",";

        for(int j=0;j<i;++j)
            tab_to_sort[j] = tab[j];

        //Bubble sort
        start=clock();
        BS(tab_to_sort,i);
        endu=clock();
        plik<<(double(endu-start)/double(CLOCKS_PER_SEC))<<",";

        for(int j=0;j<i;++j)
            tab_to_sort[j] = tab[j];

        //Heap Sort
        start=clock();
        HS(tab_to_sort,i);
        endu=clock();
        plik<<(double(endu-start)/double(CLOCKS_PER_SEC))<<",";

        for(int j=0;j<i;++j)
            tab_to_sort[j] = tab[j];

        //Counting sort
        start=clock();
        CS(tab_to_sort,i);
        endu=clock();
        plik<<(double(endu-start)/double(CLOCKS_PER_SEC))<<",";

        for(int j=0;j<i;++j)
            tab_to_sort[j] = tab[j];

        //Shell Sort
        start=clock();
        SHS(tab_to_sort,i);
        endu=clock();
        plik<<(double(endu-start)/double(CLOCKS_PER_SEC))<<endl;

    }
    plik.close();
    return 0;
}

