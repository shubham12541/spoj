#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 10000005
#define INF 1061109567

struct Node{
    int dest, weight;
    vector<Node *> adj;
};

void addEdge(int u, int v, int weight, Node* graph, Node* graphRev){
    Node* temp = new Node;
    temp->dest = v;
    temp->weight = weight;
    graph[u].adj.push_back(temp);

    // Reverse graph
    Node* temp2 = new Node;
    temp2->dest = u;
    temp2->weight = weight;
    graphRev[v].adj.push_back(temp2);
}

void djikstra(Node graph[], int source, int V, int* dist){
    for(int i=0;i<=V;i++) dist[i] = INF;

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

    dist[source] = 0;
    pq.push(make_pair( 0, source ));

    while(!pq.empty()){

        pair<int, int> temp = pq.top();
        pq.pop();

        int u = temp.second;

        for(Node* temp2: graph[u].adj){
            int v = temp2->dest;
            int weight = temp2->weight;

            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair( dist[v], v ));
            }
        }
    }
}

int main(){
    optimizar_io

    int t;
    cin >> t;

    while(t--){
        int n, m, k, source, destination;
        cin >> n >> m >> k >> source >> destination;

        Node* graph = new Node[n+1];
        Node* graphRev = new Node[n+1];

        for(int i=0;i<m;i++){
            int u, v, weight;
            cin >> u >> v >> weight;
            addEdge(u, v, weight, graph, graphRev);
        }
        int dist[n+1];
        int dist2[n+1];

        djikstra(graph, source, n, dist);
        djikstra(graphRev, destination, n, dist2);

        // cout << "\nForward Dist: \n";
        // for(int i=0;i<=n;i++) cout << dist[i] << "\t";

        // cout << "\nRev Dist: \n";
        // for(int i=0;i<=n;i++) cout << dist2[i] << "\t";
        // cout << "\n";

        int minVal = dist[destination];

        for(int i=0;i<k;i++){
            int u, v, weight;
            cin >> u >> v >> weight;
            minVal = min(minVal, min(dist[u]+weight+dist2[v], dist[v]+weight+dist2[u]));
        }

        if(minVal == INF){
            minVal = -1;
        }

        cout << minVal << "\n";

    }


    return 0;
}