#include <iostream>
#include <ctime>
#include <cmath>
#include <math.h>
#include <stdio.h> //no errors in compiling
#include <stdlib.h> //random
using namespace std;

void mer(int tab[], int l,int m, int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=tab[l+i];
    }

    for(int j=0;j<n2;j++)
    {
        R[j]=tab[m+j+1];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            tab[k]=L[i];
            i++;
        }
        else
        {
            tab[k]=R[j];
            j++;
        }
        k++;
    }

    for(i;i<n1;++i)
    {
        tab[k]=L[i];
        ++k;
    }

    for(j;j<n2;++j)
    {
        tab[k]=R[j];
        ++k;
    }
}

void MS(int tab[],int l,int r){
    if(l>=r) return;
    int m=l+(r-l)/2;
    MS(tab,l,m);
    MS(tab,m+1,r);
    mer(tab,l,m,r);
}

int main()
{
    srand(time(NULL));
    int n = 100;
    int tab[n];
    cout<<"Merge sort"<<endl;
    for (int i=0;i<n;++i)
    {
        tab[i]=rand()%100+1;
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    cout<<endl;
    MS(tab,0,n-1);
    for(int i=0;i<n;++i)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
    return 0;
}
