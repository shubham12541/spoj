#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 20001

int value[MAX];
int parent[MAX];

void bfs(int n){
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int current = q.front();
        q.pop();
        parent[1] = 0;

        // cout << current << " Parent: " << parent[current] << " Value: " << value[current] << endl;

        if(current == 0){
            stack<int> st;

            while(parent[current]){
                // cout << "Current: " << current << " Value: " << value[current] << " Parent: " << parent[current] << "\n";
                st.push(value[current]);
                current = parent[current];
            }
            st.push(1);

            while(!st.empty()){
                cout << st.top();
                st.pop();
            }

            cout << "\n";
            break;
        }

        int temp = (current*10)%n;
        if(parent[temp] == -1){
            q.push(temp);
            parent[temp] = current;
            value[temp] = 0;
        }

        temp = ((current*10) + 1)%n;
        if(parent[temp] == -1){
            q.push(temp);
            parent[temp] = current;
            value[temp] = 1;
        }
    }
}

int main(){

    optimizar_io

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for(int i=0;i<MAX;i++){
            parent[i] = -1;
        }

        bfs(n);
    }

    return 0;
}