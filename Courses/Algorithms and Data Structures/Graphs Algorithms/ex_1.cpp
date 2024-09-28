#include<iostream>
//#include<random>
#include<ctime>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

int str_to_int(string liczba)
{
    int n=0;
    for(int i=0;i<liczba.size();++i)
    {
        n+=n*10+(int(liczba[i])-48);
    }
    return n;
}
int main()
{
    fstream plik1, plik2, plik3, plik4, plik5, wyn;
    int n,e;
    srand(time(NULL));
    clock_t start, endu;

    plik1.open("adjecency.txt");
    plik2.open("incident_m.txt");
    plik3.open("edge_list.txt");
    plik4.open("list_of_incidents.txt");
    plik5.open("ne.txt");

    wyn.open("wyn.txt",ios::in|ios::app);

    plik5>>n;
    plik5>>e;

    int tab1[n][n]; //adjecency matrix
    int tab2[n][e]; //incident matrix
    int tab3[e][2]; //edge list
    vector<int> tab4[n]; //list of incidents



    //  *** GETTING DATA FROM FILES ***


    for(int i=0;i<n;++i){    //  ADJECENCY MATRIX
        for(int j=0;j<n;++j)
            plik1>>tab1[i][j];
    }


    for(int i=0;i<n;++i){    //  INCIDENT MATRIX
        for(int j=0;j<e;++j)
            plik2>>tab2[i][j];
    }


    for(int i=0;i<e*2;++i){    //  EDGE LIST
        for(int j=0;j<2;++j)
            plik3>>tab3[i][j];
    }


    for(int i=0;i<n;++i){    //  LIST OF INCIDENTS

        int no_connections,edge;
        plik4>>no_connections;

        for(int j=0;j<no_connections;j++){
            plik4>>edge;
            tab4[i].push_back(edge);
        }
    }

    //  *** MAKING MEASUREMENTS ***


    int m1=1; //the number of tests
    int m2=100000; //the number of tests for one test
    int v1,v2;
    bool exists;

    //  adjecency matrix

    for(int i=0;i<m1;++i)
    {
        start=clock();
        for(int j=0;j<m2;++j)
        {
            v1=rand()%n;
            v2=rand()%n;
            if(tab1[v1][v2]==1)
                exists=true;
            else
                exists=false;

        }
        endu=clock();
        cout<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
        wyn<<n<<",adjecency matrix,";
        wyn<<double(endu-start)/m2/double(CLOCKS_PER_SEC)<<endl;
    }

    //  incident matrix

    for(int i=0;i<m1;++i)
    {
        start=clock();
        for(int j=0;j<m2;++j)
        {
            v1=rand()%n;
            v2=rand()%n;
            for(int k=0;k<e;++k)
            {
                if(tab2[v1][k]+tab2[v2][k]==2)
                    exists=true;
                else
                    exists=false;
            }
        }
        endu=clock();
        cout<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
        wyn<<n<<",incident matrix,";
        wyn<<double(endu-start)/m2/double(CLOCKS_PER_SEC)<<endl;
    }

    //  list of edges

    for(int i=0;i<m1;++i)
    {
        start=clock();
        for(int j=0;j<m2;++j)
        {
            v1=rand()%n;
            v2=rand()%n;
            for(int k=0;k<e*2;++k)
            {
                if(tab3[k][0]==v1 && tab3[k][1]==v2)
                    exists=true;
                else if(tab3[k][0]==v2 && tab3[k][1]==v1)
                    exists=true;
                else
                    exists=false;
            }
        }
        endu=clock();
        cout<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
        wyn<<n<<",edge list,";
        wyn<<double(endu-start)/m2/double(CLOCKS_PER_SEC)<<endl;
    }

    //  list of incidents

    for(int i=0;i<m1;++i)
    {
        start=clock();
        for(int j=0;j<m2;++j)
        {
            v1=rand()%n;
            v2=rand()%n;
            int k1=0;
            int k2=0;
            exists=false;
            for(int k=0;k<tab4[v1].size();k++)
            {
                if(tab4[v1][k]==v2){exists=true;}else{exists=false;}
            }
        }
        endu=clock();
        cout<<double(endu-start)/double(CLOCKS_PER_SEC)<<endl;
        wyn<<n<<",incident list,";
        wyn<<double(endu-start)/m2/double(CLOCKS_PER_SEC)<<endl;
    }

    plik1.close();
    plik2.close();
    plik3.close();
    plik4.close();
    plik5.close();
    wyn.close();
    return 0;
}
