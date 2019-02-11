#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 10005

struct subset{
    int parent, rank;
} subsets[MAX];

struct edge{
    int u, v, cost;
} edges[MAX*MAX];


int Find(subset subsets[], int index){
    if(subsets[index].parent != index){
        subsets[index].parent = Find(subsets, subsets[index].parent);
    }

    return subsets[index].parent;
}

void Union(subset subsets[], int x, int y){
    int xroot = Find(subsets, x);
    int yroot = Find(subsets, y);

    if(subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    } else if(subsets[yroot].rank > subsets[xroot].rank){
        subsets[xroot].parent = yroot;
    } else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool isCycle(subset subsets[], edge curEdge){
    int startRoot = Find(subsets, curEdge.u);
    int endRoot = Find(subsets, curEdge.v);

    if(startRoot != endRoot){
        return false;
    }
    return true;
}

int compare(edge a, edge b){
    return a.cost < b.cost;
}

void kruskal(int noOfEdges, int noOfNodes){
    for(int i=0;i<=noOfNodes;i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // for(int i=0;i<noOfEdges;i++){
    //     cout << edges[i].u << "\t" << edges[i].v << "\tWeight: " << edges[i].cost << "\n";
    // }

    // cout << "\nSort\n";

    sort(edges, edges+noOfEdges, compare);

    // for(int i=0;i<noOfEdges;i++){
    //     cout << edges[i].u << "\t" << edges[i].v << "\tWeight: " << edges[i].cost << "\n";
    // }

    int ansCost = 0;
    int edgesTaken =0;

    for(int i=0;i<noOfEdges;i++){
        edge temp = edges[i];

        int rootIndex1 = Find(subsets, temp.u);
        int rootIndex2 = Find(subsets, temp.v);

        if(rootIndex1 != rootIndex2){
            ansCost += temp.cost;
            Union(subsets, temp.u, temp.v);
            edgesTaken++;
        }

        if(edgesTaken == noOfNodes - 1){
            break;
        }
    }

    cout << ansCost << "\n";
}

int main(){

    optimizar_io

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int noOfEdges = 0;

        for(int i=0;i<=n;i++){
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }

        for(int i=1;i<=n;i++){
            string name;
            cin >> name;

            int p;
            cin >> p;
            while(p--){
                int v, cost;
                cin >> v >> cost;

                if(v > i){
                    edges[noOfEdges].u = i;
                    edges[noOfEdges].v = v;
                    edges[noOfEdges].cost = cost;
                    noOfEdges++;
                }
            }
        }

        kruskal(noOfEdges, n);

    }

    return 0;
}



