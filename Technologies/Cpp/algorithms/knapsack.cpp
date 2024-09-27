#include <iostream>
#include <string>
using namespace std;

int main(){
    int n = 4, m = 7; //number of items, capacity
    int v[] = {0,1,2,3,4}; //values
    int w[] = {0,1,3,4,5}; //weights

    int P[n+1][m+1]; //knapsack table
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=m; ++j)
            P[i][j] = 0;
    }

    //dynamic, no items repeated or partioned
    for(int i=1; i<=n; ++i){
        for(int j=0; j<=m; ++j){
            if(j>=w[i] && P[i-1][j-w[i]] + v[i] > P[i-1][j])
                P[i][j] = P[i-1][j-w[i]] + v[i];
            else
                P[i][j] = P[i-1][j];
        }
    }

    //printing knapsack table
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=m; ++j)
            cout<<P[i][j]<<'\t';
        cout<<endl;
    }
    cout<<endl;

    //printing solution
    int current = P[n][m];
    int sol_table[n+1];
    for(int i = 0; i <= n; ++i)
        sol_table[i] = 0;

    int x = n;
    int y = m;
    while(current != 0){
        while(x > 0 && current == P[x-1][y]){
            x --;
        }
        sol_table[x] ++;
        y -= w[x];
        current = P[x][y];
    }

    for(int i = 0; i <= n; ++i)
        cout<<i<<": "<<sol_table[i]<<endl;

    return 0;
}
