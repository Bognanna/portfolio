#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

bool terminate(double start){
    if((double(clock()) - start)/double(CLOCKS_PER_SEC) > 300) return true;
    return false;
}

void addEdge(vector<int> graph[], int curr_v, int next_v){
    graph[curr_v].emplace_back(next_v);
    graph[next_v].emplace_back(curr_v);
}

void removeEdge(vector<int> graph[], int curr_v, int next_v){
    vector<int>::iterator it;
    it = find(graph[next_v].begin(), graph[next_v].end(), curr_v);
    *it = -1;
	it = find(graph[curr_v].begin(), graph[curr_v].end(), next_v);
    *it = -1;
}

int dfsCount(vector<int> graph[], int curr_v, vector<bool>& visited){
   visited[curr_v] = true;
   int counting = 1;

   // Recur for all vertices adjacent to this vertex
   for(int i : graph[curr_v]){
        if( i!= -1 && !visited[i])
            counting += dfsCount(graph, i, visited);
   }
   return counting;
}

bool isValidNextEdge(vector<int> graph[], int curr_v, int next_v, int v){
	int counting = 0;

    for(int i : graph[curr_v]){
        if(i != -1)
            counting++;
    }

    if (counting == 0)
        return false;

    if (counting == 1)
	    return true;

    vector<bool> visited(v, false);
    int count1 = dfsCount(graph, curr_v, visited);

    removeEdge(graph, curr_v, next_v);
    fill(visited.begin(), visited.end(), false);

    int count2 = dfsCount(graph, curr_v, visited);

    addEdge(graph, curr_v, next_v);

    if(count1>count2)
    {
        return (false);
    }
    else{ return(true); }
}

void eulerCycle(vector<int> graph[], int curr_v, int v){

    for(int i : graph[curr_v]){

        if(i != -1 && isValidNextEdge(graph, curr_v, i, v)){

            //cout << curr_v << "-" << i << "  ";
            removeEdge(graph, curr_v, i);
            eulerCycle(graph, i, v);
        }
    }
}

int main(){

    srand((unsigned)time(NULL));
    clock_t start, endu;
    fstream wyn;

    wyn.open("wyn2.txt");
    if(!wyn.good()){
        cout<<"Filed to open a file";
        return -1;
    }

    int no_inst = 50;   //number of instances
    int n[no_inst];
    for(int i=0; i<no_inst; ++i)
        n[i]=10*(i+1); //Odd number of vertices

    float sat_inst[] = {0.2, 0.3, 0.4, 0.6, 0.8, 0.95};
    float sat;          //saturation
    int v;              //number of vertices

    int rep = 1;

    cout<<"n, "<<"sat, "<<"algorithm, "<<"time"<<endl;
    wyn<<"n,"<<"sat,"<<"algorithm,"<<"time"<<endl;

    for(int REP = 0; REP < rep; ++REP){
        for(int I = 0; I < no_inst; ++ I){
            for(float J : sat_inst){
                v = n[I] - 1 ;
                sat = J;
                int *vertices = new int[v + 1];
                vector<int> *list_of_incidents = new vector<int>[v + 1]; //graph in form of the list of incidents

                //  *** GENERATE EULERIAN GRAPH ***

                for(int i=0; i < v; ++i){ //Initialize tab of vertices (But without the last edge!)
                    vertices[i] = i;
                }

                for(int i = v-1; i>0; --i){ //Shuffle
                    swap(vertices[i], vertices[rand()%(i+1)]);
                }

                for(int i=0; i<v; ++i){ //Create main core of the graph
                    list_of_incidents[vertices[i%v]].push_back(vertices[(i+1)%v]);
                    list_of_incidents[vertices[(i+1)%v]].push_back(vertices[i%v]);
                }

                for(int i=0; i<v; ++i){ //Fill the graph with edges
                    for(int j = 0; j<v; ++j){

                        bool add = false;
                        if(j != i && (float)rand()/RAND_MAX < sat){
                            add = true;

                            for(int curr_v : list_of_incidents[i]){
                                if(j == curr_v){
                                    add = false;
                                    break;
                                }
                            }
                        }

                        if(add){
                           list_of_incidents[i].push_back(j);
                           list_of_incidents[j].push_back(i);
                        }
                    }
                }

                for(int i=0; i<v; ++i){
                    if(list_of_incidents[i].size()%2 == 1){
                        list_of_incidents[i].push_back(v);
                        list_of_incidents[v].push_back(i);
                    }
                }

                if(list_of_incidents[v].size() > 0) v+=1; //Last Vertex is the pom vertex

                for(int i=0; i<v; ++i){
                    sort(list_of_incidents[i].begin(), list_of_incidents[i].end());
                }

                /*
                for(int i = 0; i<v; ++i){
                    cout<<i<<": ";
                    for(int j : list_of_incidents[i]){
                        cout<<j<<" ";
                    }
                    cout<<endl;
                }
                */

                //  *** EULER CYCLE ***

                start=clock();
                eulerCycle(list_of_incidents, 0, v);
                endu=clock();

                cout<<v<<", "<<sat<<", "<<"EC, "<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
                wyn<<v<<", "<<sat<<", "<<"EC, "<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;

            }
        }
    }

    wyn.close();
    return 0;
}
