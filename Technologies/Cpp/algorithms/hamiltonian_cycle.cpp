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

bool can_be_added(int vertex, vector<int> graph[], int sol[], int pos, double start){

    if(terminate(start)) return false;

    bool connected = false;
    for(int u : graph[sol[pos - 1]]){
        if(terminate(start)) return false;
        if(u == vertex){
            connected = true;
        }
    }

    if(!connected){
        //cout<<vertex<<" is not connected with "<<sol[pos -1]<<endl;
        return false;
    }



    for(int i = 0; i < pos; ++i){
        if(terminate(start)) return false;
        if(sol[i] == vertex){
            //cout<<i<<" is currently added to the solution"<<endl;
            return false;
        }
    }

    return true;
}

bool hamiltonianCycle(vector<int> graph[], int sol[], int pos, int v, double start){

    //If searches too long for a cycle
    if(terminate(start)) return false;

    //If algorithm found path, check is it also a cycle
    if(pos == v){
        for(int u : graph[sol[pos - 1]]){
            if(u == sol[0]){
                return true;
            }
            if(terminate(start)) return false;
        }
        return false;
    }

    //Try to add a vertex to the path
    for(int i = 1; i < v; ++i){

        if(terminate(start)) return false;
        if(can_be_added(i, graph, sol, pos, start)){
            sol[pos] = i;
            if(terminate(start)) return false;

            if(hamiltonianCycle(graph, sol, pos+1, v, start)){
                if(terminate(start)) return false;
                return true;
            }

            sol[pos] = -1;
        }
    }
    return false;
}

double HC(vector<int> graph[], int v){

    clock_t start = clock();

    int *sol = new int[v];
    for(int i = 0; i < v; ++i){
        sol[i] = -1;
    }

    sol[0] = 0;

    hamiltonianCycle(graph, sol, 1, v, double(start));
    return min((double(clock()) - start)/double(CLOCKS_PER_SEC), 300.0);
}

int main(){

    srand((unsigned)time(NULL));
    double search_time;
    fstream wyn;

    wyn.open("wyn1.txt");
    if(!wyn.good()){
        cout<<"Filed to open a file";
        return -1;
    }

    int no_inst = 50;   //number of instances
    int n[no_inst];
    for(int i=0; i<no_inst; ++i)
        n[i]=10*(i+1);

    float sat_inst[] = {0.2, 0.3, 0.4, 0.6, 0.8, 0.95};
    float sat;          //saturation
    int v;              //number of vertices

    int rep = 10; //

    //  *** RUN EXPERIMENTS ***

    cout<<"n, "<<"sat, "<<"algorithm, "<<"time"<<endl;
    wyn<<"n,"<<"sat,"<<"algorithm,"<<"time"<<endl;

    for(int REP = 0; REP < rep; ++REP){
        for(int I = 0; I < no_inst; ++ I){
            for(float J : sat_inst){
                v = n[I];
                sat = J;
                int *vertices = new int[v];
                vector<int> *list_of_incidents = new vector<int>[v]; //graph in form of the list of incidents

                //  *** GENERATE CONNECTED GRAPH ***

                for(int i=0; i < v; ++i){ //Initialize tab of vertices
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
                    sort(list_of_incidents[i].begin(), list_of_incidents[i].end());
                }
    /*
                for(int i = 0; i < v; ++i){
                    cout<<i<<"\t";
                    for(int u : list_of_incidents[i]){
                        cout<<u<<", ";
                    }
                    cout<<endl;
                }
    */


                //  *** HAMILTONIAN CYCLE ***
                search_time = HC(list_of_incidents, v);
                cout<<v<<", "<<sat<<", "<<"HC, "<<search_time<<endl;
                wyn<<v<<","<<sat<<","<<"HC,"<<search_time<<endl;

                //cout<<endl;

                //Clear the graph
                for(int i = 0; i < v; ++i){
                    list_of_incidents[i].clear();
                }

                delete[] vertices;
                delete[] list_of_incidents;
            }
        }
    }

    wyn.close();
    return 0;
}
