#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 10001

struct Node{
    int u, v, weight;
    vector<Node *> adj;
} graph[MAX];

int V;

Node* newNode(int u, int v, int weight){
    Node *temp = new Node;
    temp->u = u;
    temp->v = v;
    temp->weight = weight;

    return temp;
}


int main(){
    optimizar_io

    int t;
    cin >> t;

    while(t--){
        cin >> V;
        int edges;
        cin >> edges;

        for(int i=0;i<edges;i++){
            int u, v, weight;
            cin >> u >> v >> weight;

            Node* temp = newNode(u, v, weight);
            graph[u].adj.push_back(temp);
        }
    }

    return 0;
    
}