#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 2000
#define ll long long int


int bit[MAX];

struct Road{
    int u, v;
};

void update(int index, int val, int m){
    while(index <= m){
        bit[index] += val;
        index += index & (-index);
    }
}

ll read(int index){
    ll ans = 0;
    while(index > 0){
        ans += bit[index];
        index -= index & (-index);
    }

    return ans;
}

bool compare(Road a, Road b){
    if(a.u == b.u){
        return b.v < a.v;
    } else{
        return b.u < a.u;
    }
}

int main(){
    optimizar_io

    int t;
    cin >> t;

    for(int t_i=0;t_i<t;t_i++){
        int n, m, k;
        cin >> n >> m >> k;

        memset(bit, 0, sizeof(bit));

        Road roads[k];

        for(int i=0;i<k;i++){
            cin >> roads[i].u >> roads[i].v;
        }

        sort(roads, roads+k, compare);

        ll ans = 0;
        for(int i=0;i<k;i++){
            ans += read(roads[i].v - 1);
            update(roads[i].v, 1, m);
        }

        cout << "Test case " << t_i + 1 << ": " << ans << "\n";
    }

    return 0;
}