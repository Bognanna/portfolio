#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

int N = 100; //number of objects
int pop_size = 100; //size of the population
int generations = 10; //number of generations
float solution_pressure = 1;

//heapsort for 2 arrays
void heapify(int tab1[],string tab2[], int idx,int tab_size)
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

        string temp=tab2[idx];
        tab2[idx]=tab2[smallest];
        tab2[smallest]=temp;
        heapify(tab1,tab2,smallest,tab_size);
    }
}

void HS(int tab1[], string tab2[], int tab_size)
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

        string temp=tab2[0];
        tab2[0]=tab2[i];
        tab2[i]=temp;

        heapify(tab1,tab2,0,i);
    }
}

string crossing_over(string parent1, string parent2){

    string child = "";

    for(int i = 0; i<N; ++i){
        if(rand()%2 == 0){
            child += parent1[i];
        }else{
            child += parent2[i];
        }
    }

    return child;
}

string mutation(string child, float prob_of_mutation){

    for(int i=0; i<N; ++i){
        if(rand()%1000/1000 < prob_of_mutation){
            child[i] = (child[i] + 1)%2;
        }
    }

    return child;
}

int calc_fitness(string child, int obj[]){

    int fit = 0;

    for(int i = 0; i < N; ++i){
        if(child[i] == 0){
            fit += obj[i];
        }else{
            fit -= obj[i];
        }
    }
    return fit;
}

int main(){

    srand(time(NULL));
    int objects[N];
    for(int i=0; i< N; ++i){
        objects[i] = rand()%1000;
    }

    //Initialize first population
    string population[pop_size];
    int fitness[pop_size];

    for(int i = 0; i < pop_size; ++i){
        string individual = "";
        for(int j = 0; j < N; ++j){

            if(rand()%2 == 0){
                individual += "0";
                fitness[i] += objects[i];
            }else{
                individual += "1";
                fitness[i] -= objects[i];
            }
        }
        fitness[i] = abs(fitness[i]);
        population[i] = individual;

        //cout<<i<<": "<<fitness[i]<<" "<<population[i]<<endl;
    }

    HS(fitness, population, pop_size);

    cout<<"-----------------------------------------------------------"<<endl;
    for(int i = 0; i < pop_size; ++i){
        cout<<i<<": "<<fitness[i]<<" "<<population[i]<<endl;
    }

    for(int i = 0; i < generations; ++i){

        //string new_population[pop_size];
        //int new_fitness[pop_size];
        string temp_population[pop_size];
        int temp_fitness[pop_size];

        for(int j = 0; j < pop_size; ++j){
            temp_population[j] = crossing_over(population[(j%pop_size)], population[(j+1)%pop_size]);
            temp_population[j] = mutation(temp_population[j], 0.01);
            temp_fitness[j] = calc_fitness(temp_population[j], objects);
        }

        HS(temp_fitness, temp_population, pop_size);

        for(int j = 0; j <pop_size; ++j){
            if(fitness[j] > temp_fitness[j]){
                //nothing
            }else{
                fitness[j] = temp_fitness[j];
                population[j] = temp_population[j];
            }
        }
    }

    cout<<"-----------------------------------------------------------"<<endl;
    for(int i = 0; i < pop_size; ++i){
        cout<<i<<": "<<fitness[i]<<" "<<population[i]<<endl;
    }

    return 0;
}
