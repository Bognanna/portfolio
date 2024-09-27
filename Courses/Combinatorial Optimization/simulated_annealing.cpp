#include <iostream>
#include <random>
#include <fstream>
#include <ctime>
using  namespace std;

int main(){
    srand(time(NULL));
    fstream plik;
    plik.open("graph1.txt");
    if(!plik.good()){
        return -1;
    }

    int v;
    plik>>v;

    int matrix[v][v];
    for(int i = 0; i < v; ++i){
        for(int j = 0; j < v; ++j){
            plik>>matrix[i][j];
        }
    }

    for(int i = 0; i < v; ++i){
        for(int j = 0; j < v; ++j){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

//simulated annealing
    float n = 10;
    int tab[] = {0,1,2,3,4};
    int v1, v2;
    float e1, e2;
    float kb = 1;
    float p;
    float To = 100;
    float T;
    float best = 999999;
    for(int i = 0; i<n; ++i){
        e1 = 0;
        e2 = 0;
        v1 = (rand()%5);
        v2 = (rand()%5);
        while(v1 == v2){
            v2 = (rand()%5 + 1);
        }

        for(int j=1; j<v; ++j){
            e1 += matrix[tab[j-1]][tab[j]];
        }
        swap(tab[v1], tab[v2]);

        for(int j=1; j<v; ++j){
            e2 += matrix[tab[j-1]][tab[j]];
        }

        T = (n-float(i))/n * To;
        p = pow(2.71,(-((e2-e1)/kb*T)));
        if(e1>e2){
             if(rand()%1000/1000>p){
                swap(tab[v1], tab[v2]);
            }
        }
        if(e1 < best){
            best = e1;
        }
    }

    cout<<best;

    plik.close();
    return 0;

}
