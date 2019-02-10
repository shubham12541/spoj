#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 10001

vector<int> *adj;

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


pair<int, int> bfs(int startIndex, int n){
    int dist[n+1];

    for(int i=0;i<=n;i++) dist[i] = -1;

    queue<int> q;
    q.push(startIndex);

    dist[startIndex] = 0;

    while(!q.empty()){
        int index = q.front();
        q.pop();

        for(int i=0;i<adj[index].size();i++){
            int curIndex = adj[index][i];
            
            if(dist[curIndex] == -1){
                dist[curIndex] = dist[index]+1;
                q.push(curIndex);
            }
        }
    }

    int maxDist = 0;
    int maxDistIndex = 0;

    for(int i=0;i<=n;i++){
        if(dist[i] > maxDist){
            maxDist = dist[i];
            maxDistIndex = i;
        }
    }

    return make_pair(maxDistIndex, maxDist);
}

int getDiameter(int n){
    pair<int, int> temp1 = bfs(1, n);

    pair<int, int> temp2 = bfs(temp1.first, n);

    return temp2.second;
}

int main(){
    optimizar_io

    int n;
    cin >> n;

    adj = new vector<int>[n+1];

    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;

        addEdge(u, v);
    }

    cout << getDiameter(n) << "\n";

    return 0;
}