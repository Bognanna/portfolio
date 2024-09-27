#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include <ctime>
#include <unordered_set>

using namespace std;

int N = 100; //number of objects
int n = 1000; //number of iterations of heuristic function

int calc_fitness(string solution, int obj[]){

    int fit = 0;

    for(int i = 0; i < N; ++i){
        if(solution[i] == 0){
            fit += obj[i];
        }else{
            fit -= obj[i];
        }
    }
    return fit;
}

int main(){

    srand(time(NULL));
    unordered_set<string> sol_set;

    int objects[N];
    for(int i=0; i< N; ++i){
        objects[i] = rand()%1000;
    }

    string solution = "";
    for(int j = 0; j < N; ++j){
        if(rand()%2 == 0){
            solution += "0";
        }else{
            solution += "1";
        }
    }

    sol_set.insert(solution);
    string best_solution = solution;
    int best_fitness = calc_fitness(solution, objects);

    for(int i=0; i<n; ++i){
        string better_solution = solution;
        int better_fitness = 99999999;

        for(int j = 0; j<N; ++j){
            string curr_sol = better_solution;
            if(curr_sol[j] == '0'){
                curr_sol[j] = '1';
            }else{
                curr_sol[j] = '0';
            }

            if(sol_set.find(curr_sol) != sol_set.end()){
                continue;
            }else{
                sol_set.insert(curr_sol);
                if(abs(better_fitness) < abs(calc_fitness(curr_sol, objects))){
                    better_fitness = calc_fitness(curr_sol, objects);
                    better_solution = curr_sol;
                }
            }
        }

        solution = better_solution;
        if(abs(better_fitness) < abs(best_fitness)){
            best_fitness = better_fitness;
            best_solution = better_solution;
        }
        cout<<best_fitness<<endl;
    }

    cout<<best_fitness<<": "<<best_solution<<endl;

    return 0;
}
