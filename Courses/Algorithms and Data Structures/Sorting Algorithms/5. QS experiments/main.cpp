#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;

void QS(int *tab, int l, int r){
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

main(){

    int no_inst = 3;
    int n[] = {49999, 50000, 50001};

    clock_t start, endu;

    //A-SHAPE
    cout<<"A-SHAPE"<<endl;
    for(int i=0;i<no_inst;++i)
    {
        cout<<n[i]<<endl;
        int *tab = new int[n[i]+1];
        int *q = new int[n[i]];
        tab[0]=0;

        for(int j=1;j<(n[i]/2+1);j++){
            tab[j]=tab[j-1]+2;
            q[j-1]=tab[j]-1;
            q[n[i]-j]=tab[j];
        }

        start=clock();
        QS(q, 0, n[i]-1);
        endu=clock();

        cout<<n[i]<<": "<<((double(endu-start))/ (double(CLOCKS_PER_SEC)))<<endl;

        delete[] tab;
        delete[] q;
    }

    //V-SHAPE
    cout<<"V-SHAPE"<<endl;
    for(int i=0;i<no_inst;++i)
    {
        cout<<n[i]<<endl;
        int *tab = new int[n[i]+1];
        int *q = new int[n[i]];
        tab[0]=0;

        for(int j=1;j<(n[i]/2)+1;j++){
            tab[j]=tab[j-1]-2;
            q[j-1]=tab[j]+1;
            q[n[i]-j]=tab[j];
        }

        start=clock();
        QS(q, 0, n[i]-1);
        endu=clock();

        cout<<n[i]<<": "<<((double(endu-start))/ (double(CLOCKS_PER_SEC)))<<endl;

        delete[] tab;
        delete[] q;
    }

    return 0;
}
