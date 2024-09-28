#include "BS.hpp"

void BS(int tab[], int s)
{
    for(int i=0;i<s-1;i++)
    {
        for(int j=0;j<s-1;j++)
        {
            if(tab[j]>tab[j+1])
            {
                int tem=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=tem;
                //swap(tab[j],tab[j+1]);
            }
        }
    }
}
