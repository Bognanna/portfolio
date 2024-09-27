#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue>

#include INF 999999

int main(){

    int E, V;
    printf("NO edges: ");
    scanf("%d", &E); //number of edges
    printf("NO verteces: ");
    scanf("%d", &V); //number of verteces
    int edges[E][3];

    printf("Vertex1 Vertex2 Value\n");
    for(int i = 0; i<E; ++i){
        printf("%d: ", i);
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    int matrix[V][V];
    int dist[V];
    bool visit[V];
    priority_queue <int, int> Q;

    for(int i = 0; i < V; ++i){
        dist[i] = INF;
        visit[i] = false;
    }

    dist[0] = 0;

   int id;
   while(!Q.empty()){
       id = Q.top().second;
       Q.pop();

       if(visit[id]) continue;

       visit[id] = true;
       for(int i = 0; i < V; ++i){
           if(!visit[i]){
               if(dist[i] > dist[id] + edges[id][i]){
                   dist[i] = dist[id] + edges[id][i];
                   Q.push(dist[i], i);
               }
           }
       }
   }

    return 0;
}
