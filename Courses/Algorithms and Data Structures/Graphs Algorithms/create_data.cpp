#include<iostream>
#include<ctime>
//#include<random>
#include<stdlib.h>
#include<string>
#include<fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int myrandom (int i) { return rand()%i;}

int main()
{

    fstream plik1, plik2, plik3, plik4, plik5;
    srand(time(NULL));

    plik1.open("adjecency.txt");
    plik2.open("edge_list.txt");
    plik3.open("list_of_incidents.txt");
    plik4.open("incident.txt");
    plik5.open("ne.txt"); //stores info about number of vertices and number of edges

    /*
    plik1.open("adjecency.txt",ios::in|ios:app);
    plik2.open("incident.txt",ios::in|ios::app);
    plik3.open("edge_list.txt",ios::in|ios::app);
    plik4.open("list_of_incidents.txt",ios::in|ios::app);
    plik5.open("ne.txt");
    */

    //UNDIRECTED GRAPH
    int n=100; //number of vertices
    int e=((n*(n-1))/2); // max number of edges
    float sat=0.6;//saturation

    int edgs[int(round(e*sat))*2][2];
    int tab[e][2];
    int edg_id = 0;

    vector<int> temp1;

    plik5<<n<<" "<<(int(round(e*sat)))<<endl;
    plik5.close();

    cout<<"The vertices are numbered from 0"<<endl;

    for(int i=0;i<n;i++){ //create tab of all possible edges
        for(int j=0;j<i;j++){
            tab[edg_id][0]=i; //vertex1
            tab[edg_id][1]=j; //vertex2
            temp1.push_back(edg_id);
            edg_id++;
        }
    }
    random_shuffle ( temp1.begin(), temp1.end(), myrandom);

    for(int i=0;i<int(round(e*sat));i++){ //pass only e*sat edges to init graph

        edgs[i*2][0]=tab[temp1[i]][0];
        edgs[i*2][1]=tab[temp1[i]][1];

        edgs[i*2+1][0]=edgs[i*2][1]; //graph is undirected, so we just copy values of previous edges (but in opposite direction)
        edgs[i*2+1][1]=edgs[i*2][0];
    }




    //  *** Adjacency Matrix ***

    cout<<"\n  *** Adjacency Matrix ***"<<endl;
    int adjm[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            adjm[i][j]=0; //set all connections between vertices to 0
    }

    for(int i=0;i<int(round(e*sat))*2;i++)
        adjm[edgs[i][0]][edgs[i][1]]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            plik1<<adjm[i][j]<<" ";
        }
        plik1<<endl;
    }
    plik1<<"end"<<endl;
    plik1.close();




    //  *** Edge list ***

    cout<<"\n  *** Edge list ***"<<endl;
    int edge_list[int(round(e*sat))*2][2];
    edg_id=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjm[i][j]==1){ //To create Edge List, we need adjecency matrix
                    plik2<<i<<" "<<j<<endl;
                    edge_list[edg_id][0]=i;
                    edge_list[edg_id][1]=j;
                    edg_id++;
            }
        }
    }
    plik2<<"end"<<endl;
    plik2.close();




    //  *** Incidence list ***

    cout<<"\n *** Incidence list ***"<<endl;
    vector<int> inci_list[n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjm[i][j]==1)
                inci_list[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++){
        plik3<<inci_list[i].size()<<"\t";

        for(int j=0;j<inci_list[i].size();j++){
            plik3<<inci_list[i][j]<<" ";
        }

        plik3<<endl;
    }
    plik3<<"end"<<endl;
    plik3.close();





    //  *** Incidence matrix ***

    cout<<"\n *** Incidence matrix ***"<<endl;
    int inci_mat[int(round(e*sat))][n];
    edg_id=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<int(round(e*sat));j++)
            inci_mat[j][i]=0; //initialize incidence matrix
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(adjm[i][j]==1){
                inci_mat[edg_id][i]=1;
                inci_mat[edg_id][j]=1;
                edg_id++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<int(round(e*sat));j++){
            plik4<<inci_mat[j][i]<<" ";
        }

        plik4<<endl;
    }

    plik4<<"end"<<endl;
    plik4.close();

    return 0;
}
