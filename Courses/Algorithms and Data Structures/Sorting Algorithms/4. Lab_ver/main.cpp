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
    int l=2*idx+1;  //calculating pos of the left child
    int r=l+1;      //calculating pos of the right child
    int biggest=idx; //value of the root

    if(l < tab_size && tab[l] > tab[biggest])
        biggest=l;

    if(r < tab_size && tab[r] > tab[biggest])
        biggest=r;

    if(biggest!=idx){

        int tem=tab[idx];
        tab[idx]=tab[biggest];
        tab[biggest]=tem;

        heapify(tab,biggest,tab_size);
    }
}

void HS(int tab[], int tab_size)
{
    //in-place
    //O(n * log(n))
    for(int i=(tab_size/2)-1;i>=0;i--){
        //i - index of the parent
        heapify(tab,i,tab_size);
    }

    for(int i=tab_size-1;i>0;i--){
        //swap current root with the last element
        int tem=tab[0];
        tab[0]=tab[i];
        tab[i]=tem;

        heapify(tab,0,i);
    }
}

//MERGE SORT
void mer(int tab[], int l,int m, int r)
{
    int n1 = m-l+1; //size of the left array
    int n2 = r-m; //size of the right array
    int L[n1], R[n2];

    for(int i=0;i<n1;i++)
        L[i]=tab[l+i];

    for(int j=0;j<n2;j++)
        R[j]=tab[m+j+1];

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2){
        //if the element from the left tab is smaller than the element from the right tab
        if(L[i]<=R[j]){
            tab[k]=L[i]; //add left element
            i++;
        }else{
            tab[k]=R[j]; //else add to the sorted array right element
            j++;
        }
        k++;
    }

    //if some elements remain add them at the end
    for(i;i<n1;++i){
        tab[k]=L[i];
        ++k;
    }

    for(j;j<n2;++j){
        tab[k]=R[j];
        ++k;
    }
}

void MS(int tab[],int l,int r){
    //always O(n * log(n))
    if(l>=r) return;
    int m=l+(r-l)/2; //middle point
    //divide and conquer approach
    MS(tab,l,m);
    MS(tab,m+1,r);
    //call merge procedure
    mer(tab,l,m,r);
}

//QUICK SORT

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
    int no_inst = 10;
    int n[no_inst];
    for(int i=0;i<no_inst;++i)
        n[i]=2500*(i+1);

//random
    p_rand.open("p_rand.txt");

    if (p_rand.good())
        cout<<"RANDOM GIT"<<endl;

    p_rand<<"n,"<<"sort,"<<"time,"<<"data"<<endl;
    for(int i=0;i<no_inst;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];

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
            p_rand<<n[i]<<","<<"QS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",random"<<endl;
        }else{
            p_rand<<i<<","<<"QS"<<","<<0<<",random"<<endl;
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
            p_rand<<n[i]<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",random"<<endl;
        }else{
            p_rand<<i<<","<<"HS"<<","<<0<<",random"<<endl;
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
            p_rand<<n[i]<<","<<"MS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",random"<<endl;
        }else{
            p_rand<<i<<","<<"MS"<<","<<0<<",random"<<endl;
        }
        cout<<"MS ended"<<endl;

        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

    plik.close();

 //constant

    p_cons.open("p_const.txt");

    if (p_cons.good())
        cout<<"RANDOM GIT"<<endl;

    p_cons<<"n,"<<"sort,"<<"time,"<<"data"<<endl;
    for(int i=0;i<no_inst;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];
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
            p_cons<<n[i]<<","<<"QS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",constant"<<endl;
        }else{
            p_cons<<i<<","<<"QS"<<","<<0<<",constant"<<endl;
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
            p_cons<<n[i]<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",constant"<<endl;
        }else{
            p_cons<<i<<","<<"HS"<<","<<0<<",constant"<<endl;
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
            p_cons<<n[i]<<","<<"MS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",constant"<<endl;
        }else{
            p_cons<<i<<","<<"MS"<<","<<0<<",constant"<<endl;
        }
        cout<<"MS ended"<<endl;

        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

//increasing
    p_incr.open("p_incr.txt");
    if (p_incr.good())
        cout<<"INCREASING GIT"<<endl;

    p_incr<<"n,"<<"sort,"<<"time,"<<"data"<<endl;
    for(int i=0;i<no_inst;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];

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
            p_incr<<n[i]<<","<<"QS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",increasing"<<endl;
        }else{
            p_incr<<i<<","<<"QS"<<","<<0<<",increasing"<<endl;
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
            p_incr<<n[i]<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",increasing"<<endl;
        }else{
            p_incr<<i<<","<<"HS"<<","<<0<<",increasing"<<endl;
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
            p_incr<<n[i]<<","<<"MS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",increasing"<<endl;
        }else{
            p_incr<<i<<","<<"MS"<<","<<0<<",increasing"<<endl;
        }
        cout<<"MS ended"<<endl;

        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

//decreasing
    p_decr.open("p_decr.txt");
    if (p_decr.good())
        cout<<"DECREASING GIT"<<endl;

    p_decr<<"n,"<<"sort,"<<"time,"<<"decreasing"<<endl;
    for(int i=0;i<no_inst;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];
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
            p_decr<<n[i]<<","<<"QS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",decreasing"<<endl;
        }else{
            p_decr<<i<<","<<"QS"<<","<<0<<",decreasing"<<endl;
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
            p_decr<<n[i]<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",decreasing"<<endl;
        }else{
            p_decr<<i<<","<<"HS"<<","<<0<<",decreasing"<<endl;
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
            p_decr<<n[i]<<","<<"MS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",decreasing"<<endl;
        }else{
            p_decr<<i<<","<<"MS"<<","<<0<<",decreasing"<<endl;
        }
        cout<<"MS ended"<<endl;

        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;
    }

//A-shape
    p_a.open("p_a.txt");
    if (p_a.good())
        cout<<"A-SHAPE GIT"<<endl;

    p_a<<"n,"<<"sort,"<<"time,"<<"data"<<endl;
    for(int i=0;i<no_inst;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]+1];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];
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
            p_a<<n[i]<<","<<"QS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",a-shape"<<endl;
        }else{
            p_a<<i<<","<<"QS"<<","<<0<<",a-shape"<<endl;
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
            p_a<<n[i]<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",a-shape"<<endl;
        }else{
            p_a<<i<<","<<"HS"<<","<<0<<",a-shape"<<endl;
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
            p_a<<n[i]<<","<<"MS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",a-shape"<<endl;
        }else{
            p_a<<i<<","<<"MS"<<","<<0<<",a-shape"<<endl;
        }
        cout<<"MS ended"<<endl;

        delete[] tab;
        delete[] q;
        delete[] h;
        delete[] m;

    }

//V-SHAPE
    p_v.open("p_v.txt");
    if (p_v.good())
        cout<<"V-SHAPE GIT"<<endl;

    p_v<<"n,"<<"sort,"<<"time,"<<"data"<<endl;

    for(int i=0;i<no_inst;++i)
    {
        cout<<i<<endl;
        int *tab = new int[n[i]+1];
        int *q = new int[n[i]];
        int *h = new int[n[i]];
        int *m = new int[n[i]];
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
            p_v<<n[i]<<","<<"QS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",v-shape"<<endl;
        }else{
            p_v<<i<<","<<"QS"<<","<<0<<",v-shape"<<endl;
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
            p_v<<n[i]<<","<<"HS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",v-shape"<<endl;
        }else{
            p_v<<i<<","<<"HS"<<","<<0<<",v-shape"<<endl;
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
            p_v<<n[i]<<","<<"MS"<<","<<((double(endu-start) - time_to_sub)/ (double(CLOCKS_PER_SEC) * 100))<<",v-shape"<<endl;
        }else{
            p_v<<i<<","<<"MS"<<","<<0<<",v-shape"<<endl;
        }
        cout<<"MS ended"<<endl;

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
