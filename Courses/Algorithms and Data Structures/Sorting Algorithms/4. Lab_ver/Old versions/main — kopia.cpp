#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
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

//MERGE SORT
void mer(int tab[], int l,int m, int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=tab[l+i];
    }

    for(int j=0;j<n2;j++)
    {
        R[j]=tab[m+j+1];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            tab[k]=L[i];
            i++;
        }
        else
        {
            tab[k]=R[j];
            j++;
        }
        k++;
    }

    for(i;i<n1;++i)
    {
        tab[k]=L[i];
        ++k;
    }

    for(j;j<n2;++j)
    {
        tab[k]=R[j];
        ++k;
    }
}

void MS(int tab[],int l,int r){
    if(l>=r) return;
    int m=l+(r-l)/2;
    MS(tab,l,m);
    MS(tab,m+1,r);
    mer(tab,l,m,r);
}

//QUICK SORT
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
void QS(int *tab, int lewy, int prawy)
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
	QS(tab, lewy, j);
	if(i < prawy)
	QS(tab, i, prawy);
}

double measure_of_copying_time(int tab_to_sort[], int tab[], int i){
        clock_t start = clock();
        for(int k = 0; k<100; ++k){
            for(int j=0;j<i;++j)
                tab_to_sort[j] = tab[j];
        }
        clock_t endu = clock();
        double time_to_sub = double(endu - start);
        return time_to_sub;
}
//-----------------------------------------MAIN----------------------------------------
int main()
{
    srand(time(NULL));
    clock_t start, endu, time_to_sub;
    fstream p_rand, p_cons, p_incr, p_decr, p_a, p_v;
    fstream plik;
    int no_inst = 24;
    int n[no_inst];
    for(int i=0;i<no_inst;++i)
        n[i]=2500*(i+1);

    plik.open("dane_test.txt");
    //String r_name;

//random
    //p_rand.open("p_rand.txt");
    p_rand.open("p_rand.csv",ios::in|ios::app);
    if (p_rand.good())
        cout<<"RANDOM GIT"<<endl;

    //p_rand<<"n\t"<<"QS\t"<<"HS\t"<<"MS\t"<<endl;
    p_rand<<"n,"<<"sort,"<<"time"<<endl;
    for(int i=0;i<no_inst;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];

        //p_rand<<n[i]<<"\t";
        for(int j=0;j<n[i];++j)
        {
            tab[j]=rand()%1000+1;
            q[j]=tab[j];
            h[j]=tab[j];
            m[j]=tab[j];
        }

        time_to_sub = measure_of_copying_time(q, tab, n[i]);

        cout<<"QS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            QS(q,0,n[i]-1);
            for(int j=0; j<n[i]; ++j)
                q[j] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_rand<<n[i]<<","<<"QS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_rand<<i<<","<<"QS"<<","<<0<<endl;
        }
        cout<<"QS ended"<<endl;

        cout<<"HS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            HS(h,n[i]);
            for(int j=0; j<n[i]; ++j)
                h[j] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_rand<<n[i]<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_rand<<i<<","<<"HS"<<","<<0<<endl;
        }
        cout<<"HS ended"<<endl;

        cout<<"MS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            MS(m,0,n[i]-1);
            for(int j=0; j<n[i]; ++j)
                m[j] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_rand<<n[i]<<","<<"MS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_rand<<i<<","<<"MS"<<","<<0<<endl;
        }
        cout<<"MS ended"<<endl;

        /*
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
        */
        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

    plik.close();
 //constant
    //p_cons.open("p_cons.txt");
    p_cons.open("p_cons.csv",ios::in|ios::app);
    if (p_cons.good())
        cout<<"CONSTANT GIT"<<endl;

    //p_cons<<"n\t"<<"QS\t"<<"HS\t"<<"MS\t"<<endl;
    p_cons<<"n,"<<"sort,"<<"time"<<endl;
    for(int i=0;i<no_inst;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];
        //p_cons<<n[i]<<"\t";
        for(int j=0;j<n[i];++j)
        {
            tab[j]=1;
            q[j]=tab[j];
            h[j]=tab[j];
            m[j]=tab[j];
        }

        time_to_sub = measure_of_copying_time(q, tab, n[i]);

        cout<<"QS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            QS(q,0,n[i]-1);
            for(int j=0; j<i; ++j)
                q[j] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_cons<<n[i]<<","<<"QS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_cons<<i<<","<<"QS"<<","<<0<<endl;
        }
        cout<<"QS ended"<<endl;

        cout<<"HS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            HS(h,n[i]);
            for(int j=0; j<i; ++j)
                h[j] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_cons<<n[i]<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_cons<<i<<","<<"HS"<<","<<0<<endl;
        }
        cout<<"HS ended"<<endl;

        cout<<"MS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            MS(m,0,n[i]-1);
            for(int j=0; j<i; ++j)
                m[j] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_cons<<n[i]<<","<<"MS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_cons<<i<<","<<"MS"<<","<<0<<endl;
        }
        cout<<"MS ended"<<endl;
        /*
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
        */
        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

//increasing
    //p_incr.open("p_incr.txt");
    p_incr.open("p_incr.csv",ios::in|ios::app);
    if (p_incr.good())
        cout<<"INCREASING GIT"<<endl;

    //p_incr<<"n\t"<<"QS\t"<<"HS\t"<<"MS\t"<<endl;
    p_incr<<"n,"<<"sort,"<<"time"<<endl;
    for(int i=0;i<no_inst;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];

        //p_incr<<n[i]<<"\t";
        tab[0]=0;
        for(int j=1;j<n[i];++j)
        {
            tab[j]=tab[j-1]+1;
            q[j-1]=tab[j];
            h[j-1]=tab[j];
            m[j-1]=tab[j];
        }

        time_to_sub = measure_of_copying_time(q, tab, n[i]);

        cout<<"QS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            QS(q,0,n[i]-1);
            for(int j=1; j<n[i]; ++j)
                q[j-1] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_incr<<n[i]<<","<<"QS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_incr<<i<<","<<"QS"<<","<<0<<endl;
        }
        cout<<"QS ended"<<endl;

        cout<<"HS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            HS(h,n[i]);
            for(int j=1; j<n[i]; ++j)
                h[j-1] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_incr<<n[i]<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_incr<<i<<","<<"HS"<<","<<0<<endl;
        }
        cout<<"HS ended"<<endl;

        cout<<"MS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            MS(m,0,n[i]-1);
            for(int j=1; j<n[i]; ++j)
                m[j-1] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_incr<<n[i]<<","<<"MS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_incr<<i<<","<<"MS"<<","<<0<<endl;
        }
        cout<<"MS ended"<<endl;

        /*
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
        */
        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

//decreasing
    //p_decr.open("p_decr.txt");
    p_decr.open("p_decr.csv",ios::in|ios::app);
    if (p_decr.good())
        cout<<"DECREASING GIT"<<endl;

    //p_decr<<"n\t"<<"QS\t"<<"HS\t"<<"MS\t"<<endl;
    p_decr<<"n,"<<"sort,"<<"time"<<endl;
    for(int i=0;i<no_inst;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];
        //p_decr<<n[i]<<"\t";
        tab[0]=n[no_inst - 1]*10;
        for(int j=1;j<n[i];++j)
        {
            tab[j]=tab[j-1]-1;
            q[j-1]=tab[j];
            h[j-1]=tab[j];
            m[j-1]=tab[j];
        }

        time_to_sub = measure_of_copying_time(q, tab, n[i]);

        cout<<"QS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            QS(q,0,n[i]-1);
            for(int j=1; j<n[i]; ++j)
                q[j-1] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_decr<<n[i]<<","<<"QS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_decr<<i<<","<<"QS"<<","<<0<<endl;
        }
        cout<<"QS ended"<<endl;

        cout<<"HS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            HS(h,n[i]);
            for(int j=1; j<n[i]; ++j)
                h[j-1] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_decr<<n[i]<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_decr<<i<<","<<"HS"<<","<<0<<endl;
        }
        cout<<"HS ended"<<endl;

        cout<<"MS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            MS(m,0,n[i]-1);
            for(int j=1; j<n[i]; ++j)
                m[j-1] = tab[j];
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_decr<<n[i]<<","<<"MS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_decr<<i<<","<<"MS"<<","<<0<<endl;
        }
        cout<<"MS ended"<<endl;

        /*
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
        */
        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

//A-shape
    //p_a.open("p_a.txt");
    p_a.open("p_a.csv",ios::in|ios::app);
    if (p_a.good())
        cout<<"A-SHAPE GIT"<<endl;

    //p_a<<"n\t"<<"QS\t"<<"HS\t"<<"MS\t"<<endl;
    p_a<<"n,"<<"sort,"<<"time"<<endl;
    for(int i=0;i<no_inst;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]+1];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];
        //p_a<<n[i]<<"\t";
        tab[0]=0;

        for(int j=1;j<(n[i]/2+1);j++)
        {
            tab[j]=tab[j-1]+2;
            q[j-1]=tab[j]-1;
            q[n[i]-j]=tab[j];
            h[j-1]=tab[j]-1;
            h[n[i]-j]=tab[j];
            m[j-1]=tab[j]-1;
            m[n[i]-j]=tab[j];
        }

        /*
        for(int j=0; j < n[i]; ++j){
            cout<<q[j]<<" ";
        }
        cout<<endl;
        */

        time_to_sub = measure_of_copying_time(q, tab, n[i]);

        cout<<"QS started"<<endl;
        start=clock();
        for(int k = 0; k<10; ++k){
            QS(q,0,n[i]-1);
            for(int j=1; j<n[i]/2+1; ++j){
                q[j-1]=tab[j]-1;
                q[n[i]-j]=tab[j];
            }
        }
        endu=clock();
        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 10) >= 0.00001){
            p_a<<n[i]<<","<<"QS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_a<<i<<","<<"QS"<<","<<0<<endl;
        }
        cout<<"QS ended"<<endl;

        cout<<"HS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            HS(h,n[i]);
            for(int j=1; j<n[i]/2+1; ++j){
                h[j-1]=tab[j]-1;
                h[n[i]-j]=tab[j];
            }
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_a<<n[i]<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_a<<i<<","<<"HS"<<","<<0<<endl;
        }
        cout<<"HS ended"<<endl;

        cout<<"MS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            MS(m,0,n[i]-1);
            for(int j=1; j<n[i]/2+1; ++j){
                m[j-1]=tab[j]-1;
                m[n[i]-j]=tab[j];
            }
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_a<<n[i]<<","<<"MS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_a<<i<<","<<"MS"<<","<<0<<endl;
        }
        cout<<"MS ended"<<endl;

        /*
        start=clock();
        //QS(q,0,n[i]-1);
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
        */
        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;

    }

//V-SHAPE
    p_v.open("p_v.txt");
    p_v.open("p_v.csv",ios::in|ios::app);
    if (p_v.good())
        cout<<"V-SHAPE GIT"<<endl;

    //p_v<<"n\t"<<"QS\t"<<"HS\t"<<"MS\t"<<endl;
    p_v<<"n,"<<"sort,"<<"time"<<endl;

    for(int i=0;i<no_inst;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]+1];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];
        //p_v<<n[i]<<"\t";
        //tab[0]=n[no_inst - 1]*10;
        tab[0] = n[i];

        for(int j=1;j<(n[i]/2)+1;j++)
        {
            tab[j]=tab[j-1]-2;
            q[j-1]=tab[j]+1;
            q[n[i]-j]=tab[j];
            h[j-1]=tab[j]+1;
            h[n[i]-j]=tab[j];
            m[j-1]=tab[j]+1;
            m[n[i]-j]=tab[j];
        }

        time_to_sub = measure_of_copying_time(q, tab, n[i]);

        cout<<"QS started"<<endl;
        start=clock();
        for(int k = 0; k<10; ++k){
            QS(q,0,n[i]-1);
            for(int j=1; j<n[i]/2; ++j){
                q[j-1]=tab[j]+1;
                q[n[i]-j]=tab[j];
            }
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 10) >= 0.00001){
            p_v<<n[i]<<","<<"QS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_v<<i<<","<<"QS"<<","<<0<<endl;
        }
        cout<<"QS ended"<<endl;

        cout<<"HS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            HS(h,n[i]);
            for(int j=1; j<n[i]/2; ++j){
                h[j-1]=tab[j]+1;
                h[n[i]-j]=tab[j];
            }
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_v<<n[i]<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_v<<i<<","<<"HS"<<","<<0<<endl;
        }
        cout<<"HS ended"<<endl;

        cout<<"MS started"<<endl;
        start=clock();
        for(int k = 0; k<100; ++k){
            MS(m,0,n[i]-1);
            for(int j=1; j<n[i]/2; ++j){
                m[j-1]=tab[j]+1;
                m[n[i]-j]=tab[j];
            }
        }
        endu=clock();

        if((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100) >= 0.00001){
            p_v<<n[i]<<","<<"MS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<endl;
        }else{
            p_v<<i<<","<<"MS"<<","<<0<<endl;
        }
        cout<<"MS ended"<<endl;

        /*
        for(int j=0; j < n[i]; ++j){
            cout<<q[j]<<" ";
        }
        cout<<endl;
        */

        /*
        start=clock();
        //QS(q,0,n[i]-1);
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
        */
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
