#include<iostream>
#include<ctime>
#include<fstream>
#include<cmath>
#include<vector>
#include <stdlib.h>
using namespace std;

//HEAP SORT
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

//COUNTING SORT
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

//BUBBLE SORT
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

//SHELL SORT
void SHS2(int tab[], int n, vector <int> h)
{
    for(int k=h.size();k>0;--k)
    {
        int step=h[k-1];
        for(int i=step;i<n;++i)
        {
            int tem = tab[i];
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
    //plik.open("dane_R.csv",ios::in|ios::app);
    //plik.open("dane_2500_50000_2500.csv");
    plik.open("dane_2500_50000_2500_only_SHS.csv",ios::in|ios::app);
    //plik<<"n,"<<"BS,"<<"HS,"<<"CS,"<<"SHS"<<endl;
    plik<<"n,"<<"sort,"<<"time"<<endl;
    if (plik.good())
    {
        cout<<"Git"<<endl;
    }else{
        cout<<"Something is wrong"<<endl;
        return 0;
    }

    clock_t start, endu;
    clock_t start_cs, endu_cs;
    double time_to_sub;

    for(int i=2500;i<=50000;i+=2500)
    {
        cout<<endl<<i<<":"<<endl;
        int tab[i];
        int tab_to_sort[i];
        for(int j=0;j<i;++j)
        {
            //tab[j]=rand()%100000+1; //in every experiment <1, 100000>
            tab[j] = (rand()%100 *100 + rand()%100); //in every experiment <1, 100000000>
        }
        //plik<<i<<",";

        for(int j=0;j<i;++j)
            tab_to_sort[j] = tab[j];
        /*
        //Bubble SORT
        cout<<"BS started"<<endl;
        start=clock();
        BS(tab_to_sort,i);
        endu=clock();
        //plik<<(double(endu-start)/double(CLOCKS_PER_SEC))<<",";
        plik<<i<<","<<"BS"<<","<<(double(endu-start)/double(CLOCKS_PER_SEC))<<endl;
        cout<<"BS ended"<<endl;
        */

        //Measure a time of copying an array multiple times
        start_cs = clock();
        for(int k = 0; k<100; ++k){
            for(int j=0;j<i;++j)
                tab_to_sort[j] = tab[j];
        }
        endu_cs = clock();
        time_to_sub = double(endu_cs - start_cs);
        /*
        //Heap SORT
        cout<<"HS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            HS(tab_to_sort, i);
            for(int j=0; j<i; ++j)
                tab_to_sort[j] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            //plik<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<","; //Divide obtained result by 100
            plik<<i<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            //plik<<0<<",";
            plik<<i<<","<<"HS"<<","<<0<<endl;
        }
        cout<<"HS ended"<<endl;


        for(int j=0;j<i;++j)
            tab_to_sort[j] = tab[j];

        //show_tab(tab_to_sort, i);

        //Counting SORT
        cout<<"CS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            CS(tab_to_sort, i);
            for(int j=0; j<i; ++j)
                tab_to_sort[j] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            //plik<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<","; //Divide obtained result by 100
            plik<<i<<","<<"CS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            //plik<<0<<",";
            plik<<i<<","<<"CS"<<","<<0<<endl;
        }
        cout<<"CS ended"<<endl;

        for(int j=0;j<i;++j)
            tab_to_sort[j] = tab[j];

        //show_tab(tab_to_sort, i);
        */
        //Shell SORT
        cout<<"SHS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            SHS(tab_to_sort, i);
            for(int j=0; j<i; ++j)
                tab_to_sort[j] = tab[j];
        }
        endu=clock();
        //plik<<(double(endu-start)/double(CLOCKS_PER_SEC))<<endl;
        //plik<<i<<","<<"SHS"<<","<<(double(endu-start)/double(CLOCKS_PER_SEC))<<endl;
        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            //plik<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<","; //Divide obtained result by 100
            plik<<i<<","<<"SHS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            //plik<<0<<",";
            plik<<i<<","<<"SHS"<<","<<0<<endl;
        }
        cout<<"SHS ended"<<endl;

    }
    plik.close();
    return 0;
}
