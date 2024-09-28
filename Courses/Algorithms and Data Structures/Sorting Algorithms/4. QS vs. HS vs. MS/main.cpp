#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include "MS.hpp"
#include "QS.hpp"
#include "HS.hpp"
using namespace std;

int main()
{
    srand(time(NULL));
    clock_t start,endu;
    fstream p_rand, p_cons, p_incr, p_decr, p_a, p_v;
    int n[15];
    for(int i=0;i<15;++i)
        n[i]=100*i;

//random
    p_rand.open("p_rand.txt",ios::in|ios::app);
    if (p_rand.good())
        cout<<"Git"<<endl;

    p_rand<<"n\t"<<"QS\t"<<"HS\t"<<"MS\t"<<endl;
    for(int i=0;i<15;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];

        p_rand<<n[i]<<"\t";
        for(int j=0;j<n[i];++j)
        {
            tab[j]=rand()%1000+1;
            q[j]=tab[j];
            h[j]=tab[j];
            m[j]=tab[j];
        }

        start=clock();
        QS(q,0,n[i]-1);
        endu=clock();
        p_rand<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        start=clock();
        HS(h,n[i]);
        endu=clock();
        p_rand<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        start=clock();
        MS(m,0,n[i]-1);
        endu=clock();
        p_rand<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        p_rand<<endl;

        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

 //constant
    p_cons.open("p_cons.txt",ios::in|ios::app);
    if (p_cons.good())
        cout<<"Git"<<endl;

    p_cons<<"n\t"<<"QS\t"<<"HS\t"<<"MS\t"<<endl;
    for(int i=0;i<15;++i)
    {
        int *tab = new int[n[i]];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];
        p_cons<<n[i]<<"\t";
        for(int j=0;j<n[i];++j)
        {
            tab[j]=1;
            q[j]=tab[j];
            h[j]=tab[j];
            m[j]=tab[j];
        }

        start=clock();
        QS(q,0,n[i]-1);
        endu=clock();
        p_cons<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        start=clock();
        HS(h,n[i]);
        endu=clock();
        p_cons<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        start=clock();
        MS(m,0,n[i]-1);
        endu=clock();
        p_cons<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        p_cons<<endl;

        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

//increasing
    p_incr.open("p_incr.txt",ios::in|ios::app);
    if (p_incr.good())
        cout<<"Git"<<endl;

    p_incr<<"n\t"<<"QS\t"<<"HS\t"<<"MS\t"<<endl;
    for(int i=0;i<15;++i)
    {
        int *tab = new int[n[i]];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];

        p_incr<<n[i]<<"\t";
        tab[0]=0;
        for(int j=1;j<n[i];++j)
        {
            tab[j]=tab[j-1]+1;
            q[j-1]=tab[j];
            h[j-1]=tab[j];
            m[j-1]=tab[j];
        }

        start=clock();
        QS(q,0,n[i]-1);
        endu=clock();
        p_incr<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        start=clock();
        HS(h,n[i]);
        endu=clock();
        p_incr<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        start=clock();
        MS(m,0,n[i]-1);
        endu=clock();
        p_incr<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        p_incr<<endl;

        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

//decreasing
    p_decr.open("p_decr.txt",ios::in|ios::app);
    if (p_decr.good())
        cout<<"Git"<<endl;

    p_decr<<"n\t"<<"QS\t"<<"HS\t"<<"MS\t"<<endl;
    for(int i=0;i<15;++i)
    {
        int *tab = new int[n[i]];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];
        p_decr<<n[i]<<"\t";
        tab[0]=n[14]*10;
        for(int j=1;j<n[i];++j)
        {
            tab[j]=tab[j-1]-1;
            q[j-1]=tab[j];
            h[j-1]=tab[j];
            m[j-1]=tab[j];
        }

        start=clock();
        QS(q,0,n[i]-1);
        endu=clock();
        p_decr<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        start=clock();
        HS(h,n[i]);
        endu=clock();
        p_decr<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        start=clock();
        MS(m,0,n[i]-1);
        endu=clock();
        p_decr<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        p_decr<<endl;

        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

//A-shape
    p_a.open("p_a.txt",ios::in|ios::app);
    if (p_a.good())
        cout<<"Git"<<endl;

    p_a<<"n\t"<<"QS\t"<<"HS\t"<<"MS\t"<<endl;
    for(int i=0;i<15;++i)
    {
        int *tab = new int[n[i]+1];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];
        p_a<<n[i]<<"\t";
        tab[0]=0;

        for(int j=1;j<(n[i]/2+1);j++)
        {
            tab[j]=tab[j-1]+2;
            q[j-1]=tab[j]-1;
            q[15-j]=tab[j];
            h[j-1]=tab[j]-1;
            h[15-j]=tab[j];
            m[j-1]=tab[j]-1;
            m[15-j]=tab[j];
        }

        start=clock();
        QS(q,0,n[i]-1);
        endu=clock();
        p_a<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        start=clock();
        HS(h,n[i]);
        endu=clock();
        p_a<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        start=clock();
        MS(m,0,n[i]-1);
        endu=clock();
        p_a<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        p_a<<endl;
        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;

    }

//V-SHAPE
    p_v.open("p_v.txt",ios::in|ios::app);
    if (p_v.good())
        cout<<"Git"<<endl;

    p_v<<"n\t"<<"QS\t"<<"HS\t"<<"MS\t"<<endl;
    for(int i=0;i<15;++i)
    {
        int *tab = new int[n[i]+1];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];
        p_v<<n[i]<<"\t";
        tab[0]=n[14]*10;

        for(int j=1;j<(n[i]/2)+1;j++)
        {
            tab[j]=tab[j-1]-2;
            q[j-1]=tab[j]+1;
            q[15-j]=tab[j];
            h[j-1]=tab[j]+1;
            h[15-j]=tab[j];
            m[j-1]=tab[j]+1;
            m[15-j]=tab[j];
        }

        start=clock();
        QS(q,0,n[i]-1);
        endu=clock();
        p_v<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        start=clock();
        HS(h,n[i]);
        endu=clock();
        p_v<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        start=clock();
        MS(m,0,n[i]-1);
        endu=clock();
        p_v<<(double(endu-start)/double(CLOCKS_PER_SEC))<<"\t";

        p_v<<endl;

        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

    p_rand.close();
    p_cons.close();
    p_incr.close();
    p_decr.close();
    p_a.close();
    p_v.close();
    return 0;
}
