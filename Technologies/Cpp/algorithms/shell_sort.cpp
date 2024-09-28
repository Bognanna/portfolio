#include<iostream>
#include<vector>
#include<ctime>
#include<cmath>
#include<stdlib.h>
using namespace std;

void SHS2(int tab[], int n, vector <int> h)
{
    for(int k=h.size();k>0;--k)
    {
        int step=h[k-1];
        for(int i=step;i<n;++i)
        {
            int tem = tab[i];
            /*
            for(int j=i+1;j<n;j+=step)
            {
                if(tab[mini]>tab[j])
                {
                    mini=j;
                }
            }
            */
            int j;
            for(j = i; j >= step && tab[j - step] > tem; j-= step){
                tab[j] = tab[j - step];
            }
            tab[j] = tem;
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

int main()
{
    int n=100;
    srand(time(NULL));
    int tab[n];
    cout<<"Shell sort"<<endl;
    for(int i=0;i<n;++i)
    {
        tab[i]=rand()%100+1;
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    cout<<endl;
    SHS(tab,n);
    for(int i=0;i<n;++i)
    {
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}
