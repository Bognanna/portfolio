#include "QS.hpp"
#include<cmath>
#include<algorithm>
using namespace std;

int middle(int tab[], int p, int k){
    int pivo = tab[p]; // tab[(p+k)/2]
    int i = p; //lewy
    int j = k; //prawy

    while(true){
        while(pivo > tab[i]) ++i;
        while(pivo < tab[j]) --j;
        if(i < j){
            swap(tab[i], tab[j]);
            ++i;
            --j;
        }else
            return j;
    }
}

void QS(int tab[], int p, int k){
    int mid;
    if(p < k){
        mid = middle(tab, p ,k);
        QS(tab, p, mid);
        QS(tab, mid+1, k);
    }
}
