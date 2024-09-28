#include<iostream>
//#include<random>
#include<ctime>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int n = 20000;
float sat = 0.3;
vector<bool> visited;
vector<int> sorted;
//list<int>[n] list_of_incidents;
vector<vector<int>> list_of_incidents(n); //graph in form of the list of incidents

void dfs(int vertex){

    visited[vertex] = true;
    int connected_v = list_of_incidents[vertex].size();

    for(int i = 0; i < connected_v; ++i){
        int curr_vertex = list_of_incidents[vertex][i];
        if (visited[curr_vertex] == false)
            dfs(curr_vertex);
    }

    sorted.push_back(vertex);
}

void topological_sort(){

    visited.assign(n, false);
    sorted.clear();

    for(int i = 0; i < n; ++i){
        if( visited[i] == false) dfs(i);
    }
}

int main()
{
    fstream plik;
    srand((unsigned)time(NULL));
    clock_t start, endu;

    //plik.open("wyn2.txt",ios::in|ios::app);
    plik.open("wyn2.txt");


    //  *** GENERATE DAG ***

    int vertices[n];

    for(int i=0; i < n; ++i){ //Initialize tab of vertices
        vertices[i] = i;
    }

    for(int i = n-1; i>0; --i){ //Shuffle
        swap(vertices[i], vertices[rand()%(i+1)]);
    }

    for(int i=0;i<n;i++){ //Create DAG
        for(int j=i+1;j<n;j++){
            if((float)rand()/RAND_MAX < sat*2)
                list_of_incidents[vertices[i]].push_back(vertices[j]);
        }
    }

    for(int i=0; i<n-1; ++i){ //Make sure, graph is fully connected
        if(list_of_incidents[vertices[i]].size() == 0){
            list_of_incidents[vertices[i]].push_back(vertices[i + 1 + rand()%(n - i - 1)]);
        }
    }

/*
    for(int i = 0; i < n; ++i){
        cout<<i<<"\t";
        for(int u : list_of_incidents[i]){
            cout<<u<<", ";
        }
        cout<<endl;
    }
*/
    //  *** TOPOLOGICAL SORT ***
    start=clock();
    topological_sort();
    endu=clock();

/*
    for(int i=sorted.size(); i > 0; --i){
        cout<<sorted[i-1]<<" ";
    }

*/
    cout<<endl<<"Time:\t"<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
    plik<<n<<","<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;

    plik.close();

    return(0);

}
