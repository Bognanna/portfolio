#include "SHS.hpp"
#include<vector>
using namespace std;

void SHS2(int tab[], int n, vector <int> h)
{
    for(int k=h.size();k>0;--k)
    {
        int step=h[k-1];
        for(int i=0;i<n;++i)
        {
            int mini=i;
            for(int j=i+1;j<n;j+=step)
            {
                if(tab[mini]>tab[j])
                {
                    mini=j;
                }
            }
            swap(tab[i],tab[mini]);
        }
    }
}

void SHS(int tab[], int n)
{
    vector <int> h;
    int i=0;
    while(2*i*i+1<n)
    {
        h.push_back(2*i*i+1);
        ++i;
    }
    SHS2(tab,n,h);
}

