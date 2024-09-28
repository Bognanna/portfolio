#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
#include<string>
using namespace std;

/*
int middle(int tab[], int p, int k){
    int pivo = tab[p];
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
*/
/*
//Another solution
void quick_sort(int *tab, int lewy, int prawy)
{
	if(prawy <= lewy) return;

	int i = lewy - 1, j = prawy + 1,
	pivot = tab[(lewy+prawy)/2];

	while(1)
	{
		while(pivot>tab[++i]);

		while(pivot<tab[--j]);

		if( i <= j)
			swap(tab[i],tab[j]);
		else
			break;
	}

	if(j > lewy)
	quick_sort(tab, lewy, j);
	if(i < prawy)
	quick_sort(tab, i, prawy);
}
*/

int middle(int tab[], int p, int k){
    int pivo = tab[p];
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

int main(){
    //int tab[10];
    int tab[] = {1, 3, 5, 7, 9, 8, 6, 4, 2, 0};
    //quick_sort(tab, 0, 9);
    QS(tab, 0, 9);

    for(int i=0; i<10; ++i)
        cout<<tab[i]<<" ";
}
