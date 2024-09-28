#include "MS.hpp"

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
