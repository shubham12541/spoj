#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 1000001

struct Node{
    int dest, weight;
    vector<Node *> adj;
} graph[MAX];

int V;

void addEdge(int u, int v, int weight){
    Node *temp = new Node;
    temp->dest = v;
    temp->weight = weight;
    graph[u].adj.push_back(temp);

    Node *temp2 = new Node;
    temp2->dest = u;
    temp2->weight = weight;
    graph[v].adj.push_back(temp2);
}



int dijkstra(int source, int destination){
    int dist[V+1];
    for(int i=0;i<=V;i++) dist[i] = INT_MAX;

    priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;

    dist[source] = 0;
    pq.push(make_pair(0, source));

    while(!pq.empty()){

        pair<int, int> temp = pq.top();
        pq.pop();

        int u = temp.second;
        int distTemp = temp.first;

        if(distTemp > dist[u]){
            continue;
        }

        // for(int i=0;i<graph[u].adj.size();i++){
        for(Node* temp2: graph[u].adj){
            int v = temp2->dest;
            int weight = temp2->weight;

            if(dist[u] != INT_MAX && dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair( dist[v], v ));
            }
        }
    }

    return dist[destination];
}


int main(){
    optimizar_io

    int t;
    cin >> t;

    while(t--){
        cin >> V;
        int edges;
        cin >> edges;

        // int src, destination;
        // cin >> src >> destination;

        for(int i=0;i<edges;i++){
            int u, v, weight;
            cin >> u >> v >> weight;

            addEdge(u, v, weight);
        }

        int queries;
        cin >> queries;

        while(queries--){
            int src, destination;
            cin >> src >> destination;
            cout << dijkstra(src, destination) << "\n";
        }

    }

    return 0;
    
}