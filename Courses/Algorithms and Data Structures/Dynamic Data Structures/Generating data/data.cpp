#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<stdlib.h> //rand()
#include<stdio.h>
using namespace std;

int main()
{
    int N = 9; //number of iterations
    int n = 10; //number of records
    int step = 10;//step
    fstream plik, app, del, sea;
    srand(time(NULL));
    plik.open("data.txt");
    del.open("delete.txt");
    sea.open("search.txt");

    if(!plik.good() || !del.good() || !sea.good())
    {
        cout<<"Wrong file"<<endl;
        return 0;
    }

    plik<<N<<endl;
    for(int k=0;k<N;++k)
    {
        int m = n+k*step;
        plik<<m<<endl;

        int tab[m];
        cout<<"n: "<<k<<endl;
        cout<<"indexes"<<endl;
        for(int i=0;i<m;++i)
        {
            bool repeated;
            int idx;

            do{
                repeated = 0;
                idx = (rand()*rand())%9000000 + 1000000;
                for(int j=0;j<i;++j)
                {
                    if(tab[j]==idx)
                    {
                        repeated = 1;
                        break;
                    }
                }
            }while(repeated);

            tab[i] = idx;
        }

        cout<<"append"<<endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<12;++j) //name
            {
                plik<<char(rand()%26+65);
            }
            plik<<" ";

            for(int j=0;j<12;++j) //surname
            {
                plik<<char(rand()%26+65);
            }
            plik<<" ";
            plik<<tab[i]<<endl; //index
        }

        cout<<"delete"<<endl;
        for(int i=0;i<m;++i){
            swap(tab[(rand()*rand())%m],tab[(rand()*rand())%m]);
        }
        for(int i=0;i<m;++i){
            del<<tab[i]<<endl;
        }

        cout<<"search"<<endl;
        for(int i=0;i<m;++i){
            swap(tab[(rand()*rand())%m],tab[(rand()*rand())%m]);
        }
        for(int i=0;i<m;++i){
            sea<<tab[i]<<endl;
        }
    }


    plik.close();
    //app.close();
    del.close();
    sea.close();
    return 0;
}
