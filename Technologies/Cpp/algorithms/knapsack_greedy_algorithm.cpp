#include<iostream>
#include<random>
#include<ctime>
#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

void heapify(float tab1[],int tab2[], int idx,int tab_size)
{
    int l=2*idx+1;
    int r=l+1;
    int smallest=idx;
    if(l < tab_size && tab1[l] < tab1[smallest]){smallest=l;}
    if(r < tab_size && tab1[r] < tab1[smallest]){smallest=r;}

    if(smallest!=idx)
    {
        float tem=tab1[idx];
        tab1[idx]=tab1[smallest];
        tab1[smallest]=tem;
        //swap(tab[idx],tab[smallest]);
        int temp=tab2[idx];
        tab2[idx]=tab2[smallest];
        tab2[smallest]=temp;
        heapify(tab1,tab2,smallest,tab_size);
    }
}

void HS(float tab1[], int tab2[], int tab_size)
{
    for(int i=(tab_size/2)-1;i>=0;i--)
    {
        heapify(tab1,tab2,i,tab_size);
    }
    for(int i=tab_size-1;i>0;i--)
    {
        float tem=tab1[0];
        tab1[0]=tab1[i];
        tab1[i]=tem;

        int temp=tab2[0];
        tab2[0]=tab2[i];
        tab2[i]=temp;
        //swap(tab[0],tab[i]);
        heapify(tab1,tab2,0,i);
    }
}

int main()
{
    fstream wyn, plik, sol;
    clock_t start, endu;
    //wyn.open("greedy.txt",ios::in|ios::app);
    wyn.open("greedy_br.txt",ios::in|ios::app);
    //plik.open("items.txt");
    plik.open("items_br.txt");
    //sol.open("solutions_GR.txt",ios::in|ios::app);

    if(!plik.good() || !wyn.good()){
        cout<<"Wrong file"<<endl;
        return -1;
    }


    char bin; // : ;
    int n, N; //number of rows, Number of items
    plik>>n;

    wyn<<"n,"<<" capacity,"<<" method,"<<" time,"<<" result"<<endl;
    for(int i=0;i<n;++i)
    {
        plik>>N;
        plik>>bin;
        float tab[N][2]; // weight, value
        float tab_ratio[N][2];
        for(int j=0;j<N;++j)
        {
            plik>>tab[j][0]; //weight
            plik>>tab[j][1]; //value
            plik>>bin;
            tab_ratio[j][0]=tab[j][1]/tab[j][0]; //ratio
            tab_ratio[j][1]=j; //index of element in tab
        }

        cout<<N<<endl;
        for(int c=100;c<=100;c+=100){ //dla ró¿nych obci¹¿eñ plecaka

            start = clock();
            int sorted_idx[N];
            float sorted_ratio[N];

            for(int j=0;j<N;++j){ //rozdzielamy 1 tab 2D na 2 tab 1D
                sorted_idx[j]=j;
                sorted_ratio[j]=tab_ratio[j][0];
            }

            HS(sorted_ratio,sorted_idx,N);

            int maxv=0; //max value
            int temv=0; // temporary value
            int temw=0; // temporary weight

            for(int k=0;k<N;++k){
                if(tab[sorted_idx[k]][0]+temw <= c){
                    temw+=tab[sorted_idx[k]][0];
                    temv+=tab[sorted_idx[k]][1];
                }
            }

            if(temv>maxv)
                maxv=temv;

            endu = clock();
            cout<<N<<", "<<c<<", "<<"GR, "<<double(endu-start)/double(CLOCKS_PER_SEC)<<", "<<maxv<<endl;
            //wyn<<N<<", "<<c<<", "<<"GR, "<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
            //cout<<N<<", "<<c<<", "<<"GR, "<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
        }

    }

    wyn.close();
    plik.close();
    return 0;
}

