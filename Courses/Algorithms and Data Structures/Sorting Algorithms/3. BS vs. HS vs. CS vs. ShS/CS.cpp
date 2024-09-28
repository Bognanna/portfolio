#include "CS.hpp"

void CS(int tab[],int tab_size)
{
    int range=0;
    int unsorted[tab_size];
    for(int i=0;i<tab_size;i++)
    {
        if(range<tab[i])
        {
            range=tab[i];
        }
        //range=max(range,tab[i]);
        unsorted[i]=tab[i];
    }
    int counting_tab[range+1];
    for(int i=0;i<range+1;i++){counting_tab[i]=0;}
    for(int i=0;i<tab_size;i++){counting_tab[tab[i]]++;}
    for(int i=1;i<range+1;i++){counting_tab[i]+=counting_tab[i-1];}
    for(int i=0;i<tab_size;i++){tab[counting_tab[unsorted[i]]-1]=unsorted[i];counting_tab[unsorted[i]]--;}
}
