#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 100005
#define MAX2 1000000

pair<int, int> arr[MAX];
pair<int, int> accepted[MAX];

int compare(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second){
        return a.second < b.second;
    } else{
        return a.first < a.first;
    }
    // return (a.second - a.first) < (b.second - b.first);
}

bool isPossible(int u, int v, int noOfAccepted){
    bool ans = true;
    for(int i=0;i<noOfAccepted;i++){
        if(v <= accepted[i].first || u >= accepted[i].second){
            // nothing
        } else{
            ans = false;
            break;
        }
    }
    return ans;
}

int main(){
    optimizar_io

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for(int i=0;i<n;i++) {
            cin >> arr[i].first >> arr[i].second;
        }

        // for(int i=0;i<n;i++){
        //     cout << arr[i].first << " " << arr[i].second << "\t";
        // }

        // cout << "\nSort\n";


        sort(arr, arr+n, compare);

        // for(int i=0;i<n;i++){
        //     cout << arr[i].first << " " << arr[i].second << "\t";
        // }

        int ans = 0;

        for(int i=0;i<n;i++){
            if(isPossible(arr[i].first, arr[i].second, ans)){
                accepted[ans++] = arr[i];
            }
        }

        cout << ans << "\n";

        for(int i=0;i<n;i++){
            arr[i].first = 0;
            arr[i].second = 0;

            accepted[i].first = 0;
            accepted[i].second = 0;
        }
    }

    return 0;
}