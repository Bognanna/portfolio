#include <stdlib.h>
#include <stdio.h>

#define INF 999999

int m;
int n;

int main(){
    scanf("%d", &n); //number of edges
    scanf("%d", &m); //number of verteces
    int edges[n][3];

    for(int i = 0; i<n; ++i){
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    int matrix[m][m];
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            matrix[i][j] = INF;
            if(i == j){
                matrix[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        matrix[edges[i][0] - 1][edges[i][1] - 1] = edges[i][2];
        matrix[edges[i][1] - 1][edges[i][0] - 1] = edges[i][2];
    }

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
