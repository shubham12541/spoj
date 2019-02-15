#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 10001

int graph[MAX][MAX];
int V;


int minDistance(int dist[], bool sptSet[]){
    int min = INT_MAX, minIndex = -1;

    for(int i=0;i<V;i++){
        if(!sptSet[i] && dist[i] <= min){
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int dijkstra(int source, int destination){
    int dist[V+1];
    bool sptSet[V+1];

    for(int i=0;i<=V;i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[source] = 0;
    sptSet[source] = true;

    for(int i=0;i<V-1;i++){
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for(int v=0;v<V;v++){
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v] ){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    return dist[destination];
}

int main(){
    optimizar_io

    int V = 5;

    int t;
    cin >> t;

    while(t--){
        cin >> V;

        int edges;
        cin >> edges;

        for(int i=0;i<edges;i++){
            int u, v, temp;
            cin >> u >> v >> temp;

            graph[u][v] = temp;
        }
    }

    return 0;
}