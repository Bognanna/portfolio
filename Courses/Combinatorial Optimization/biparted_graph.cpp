#include <iostream>
#include <cstdio>
//#include <stdbool.h>
using namespace std;

//heapsort for 2 arrays
void heapify(int tab1[],int tab2[], int idx,int tab_size)
{
    int l=2*idx+1;
    int r=l+1;
    int smallest=idx;
    if(l < tab_size && tab1[l] < tab1[smallest]){smallest=l;}
    if(r < tab_size && tab1[r] < tab1[smallest]){smallest=r;}

    if(smallest!=idx)
    {
        int tem=tab1[idx];
        tab1[idx]=tab1[smallest];
        tab1[smallest]=tem;

        int temp=tab2[idx];
        tab2[idx]=tab2[smallest];
        tab2[smallest]=temp;
        heapify(tab1,tab2,smallest,tab_size);
    }
}

void HS(int tab1[], int tab2[], int tab_size)
{
    for(int i=(tab_size/2)-1;i>=0;i--)
    {
        heapify(tab1,tab2,i,tab_size);
    }
    for(int i=tab_size-1;i>0;i--)
    {
        int tem=tab1[0];
        tab1[0]=tab1[i];
        tab1[i]=tem;

        int temp=tab2[0];
        tab2[0]=tab2[i];
        tab2[i]=temp;

        heapify(tab1,tab2,0,i);
    }
}

int main(){
    cout<<"Number of edges: ";
    int e; //number of edges
    cin>>e;

    cout<<"Number of verteces: ";
    int v;
    cin>>v;

    int list_of_edges1[e];
    int list_of_edges2[e];
    int colour[v];

    for(int i=0; i<e; ++i){
        cout<<i<<" Vertex1 Vertex2: "<<endl;
        cin>>list_of_edges1[i];
        cin>>list_of_edges2[i];
        colour[min(i, v-1)] = 0;
    }
    //HS(list_of_edges1, list_of_edges2, e);

    int v1, v2;
    bool biparted = 1;
    for(int i=0; i<e; ++i){
        v1 = list_of_edges1[i];
        v2 = list_of_edges2[i];
        if(colour[v1]==0){
            colour[v1] = 1;
            colour[v2] = 2;
        }else if(colour[v1]==1 && colour[v2]==0){
            colour[v2] = 2;
        }else if(colour[v1]==2 && colour[v2]==0){
            colour[v2] = 1;
        }else if(colour[v1]==colour[v2]){
            biparted = 0;
            break;
        }
    }

    if(biparted){
        cout<<"The graph is biparted"<<endl;
    }else{
        cout<<"The graph is not biparted"<<endl;
    }

    return 0;
}
