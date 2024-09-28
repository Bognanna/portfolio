#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <math.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

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

/*
void quick_sort(int tab[], int p, int k){
    int mid;
    if(p < k){
        mid = middle(tab, p ,k);
        quick_sort(tab, p, mid);
        quick_sort(tab, mid+1, k);
    }
}
*/

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

void QS(int *tab, int l, int r)
{
    //average O(n*log(n))
    //for a-shape, v-shape O(n^2)
    //not stable
	if(r <= l) return;

	int i = l - 1;
	int j = r + 1;
	int pivot = tab[(l+r)/2];

	while(1){
		while(pivot>tab[++i]);

		while(pivot<tab[--j]);

		if( i <= j)
			swap(tab[i],tab[j]);
		else
			break;
	}

	if(j > l)
        QS(tab, l, j);

	if(i < r)
        QS(tab, i, r);
}

int main()
{
    srand (time(NULL));
    int n_el=100;
    int tab[n_el];
    cout<<"Quick sort"<<endl;
    for(int i=0;i<n_el;i++)
    {
        tab[i]=rand() % 100 + 1;
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    cout<<endl;
    QS(tab,0,n_el-1);
    for(int i=0;i<n_el;i++){cout<<tab[i]<<", ";}

}



