#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 100005
#define MAX2 1000000

pair<int, int> arr[MAX];
int counter[MAX2];

int compare(pair<int, int> a, pair<int, int> b){
    return (a.second - a.first) - (b.second - a.first);
}

bool isPossible(int u, int v){
    for()
}

int main(){
    optimizar_io

    int t;
    cin >> t;

    while(t--){
        int n;

        for(int i=0;i<n;i++) {
            cin >> arr[i].first >> arr[i].second;

        }

        sort(arr, arr+n, compare);

        int ans = 0;

        for(int i=0;i<n;i++){
            
        }
    }

    return 0;
}