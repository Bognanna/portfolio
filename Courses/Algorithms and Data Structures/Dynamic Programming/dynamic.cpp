#include <iostream>
#include <string>
#include<random>
#include<ctime>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main()
{
    fstream wyn, plik, sol;
    clock_t start, endu;
    srand(time(NULL));

    //wyn.open("dynamic.txt",ios::in|ios::app);
    wyn.open("dynamic_br.txt",ios::in|ios::app);
    //plik.open("items.txt");
    plik.open("items_br.txt");

    if(!plik.good() || !wyn.good()){
        cout<<"Wrong file"<<endl;
        return 0;
    }

    char bin; // : ;
    int n, N; //number of rows, Number of items
    plik>>n;

    wyn<<"n,"<<" capacity,"<<" method,"<<" time,"<<" result"<<endl;
    for(int i=0;i<n;i++){
        plik>>N;
        plik>>bin;
        int* w = new int[N+1]; //weights
        int* v = new int[N+1]; //values
        v[0]=0; w[0]=0; //itemek o indeksie 0, ma wartosc i wage = 0
        for(int j=0;j<N;++j)
        {
            plik>>w[j+1]; //weight
            plik>>v[j+1]; //value
            plik>>bin;
        }

        //wyn<<N<<": ";
        cout<<N<<endl;

        for(int c=100;c<=100;c+=100) //for different capacities
        {
            start=clock();
            int **P = (int**)malloc((N+1) * sizeof(int*));
            int **Q = (int**)malloc((N+1) * sizeof(int*));

            for(int j = 0; j < N + 1; j++){
                P[j] = (int*)malloc(((c+1)*sizeof(int)));
                Q[j] = (int*)malloc(((c+1)*sizeof(int)));
            }

            for(int j=0;j<=N;++j){
                for(int k=0;k<=c;++k){
                    P[j][k]=0;
                    Q[j][k]=0;
                }
            }


            for(int j=1;j<=N;++j){
                for(int k=1;k<=c;++k){

                    if(k>=w[j] && P[j-1][k-w[j]]+v[j] > P[j-1][k]){
                        P[j][k]=P[j-1][k-w[j]]+v[j];
                        Q[j][k]=j;
                    }else{
                        P[j][k]=P[j-1][k];
                        Q[j][k]=Q[j-1][k];
                    }
                }
            }

            endu=clock();

            cout<<N<<", "<<c<<", "<<"DP, "<<double(endu-start)/double(CLOCKS_PER_SEC)<<", "<<P[N][c]<<endl;
            wyn<<N<<", "<<c<<", "<<"DP, "<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;

            for(int k = 0; k < (N + 1); k++){
                free(P[k]);
                free(Q[k]);
            }

            free(P);
            free(Q);
        }
        delete[] v;
        delete[] w;
    }

    plik.close();
    wyn.close();
    return 0;
}
