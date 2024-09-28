#include "HS.hpp"

void heapify(int tab[], int idx,int tab_size)
{
    int l=2*idx+1;
    int r=l+1;
    int biggest=idx;
    if(l < tab_size && tab[l] > tab[biggest]){biggest=l;}
    if(r < tab_size && tab[r] > tab[biggest]){biggest=r;}

    if(biggest!=idx)
    {
        int tem=tab[idx];
        tab[idx]=tab[biggest];
        tab[biggest]=tem;
        //swap(tab[idx],tab[biggest]);
        heapify(tab,biggest,tab_size);
    }
}

void HS(int tab[], int tab_size)
{
    for(int i=(tab_size/2)-1;i>=0;i--)
    {
        heapify(tab,i,tab_size);
    }
    for(int i=tab_size-1;i>0;i--)
    {
        int tem=tab[0];
        tab[0]=tab[i];
        tab[i]=tem;
        //swap(tab[0],tab[i]);
        heapify(tab,0,i);
    }
}

