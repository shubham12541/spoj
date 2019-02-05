#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 1000000005
#define MAX2 100005

int arr[MAX2];

int getMaxCows(int value, int n){
    int last = arr[0];
    int ans=1;

    for(int i=1;i<n; i++){
        if(arr[i] - last >= value){
            ans++;
            last = arr[i];
        }
    }

    return ans;
}

int main(){
    optimizar_io

    int t;
    cin >> t;

    while(t--){
        int n, c;
        cin >> n >> c;

        int max=0;
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }

        sort(arr, arr+n);


        int hi = arr[n-1];
        int lo = 0;

        while(hi > lo){
            int mid = lo + (hi-lo)/2;

            int maxCowsPossible = getMaxCows(mid, n);

            // cout << "mid: " << mid << " Cows: " << maxCowsPossible << "\n";
            

            if(maxCowsPossible < c){
                hi = mid;
            } else{
                lo = mid + 1;
            }
        }

        cout << lo - 1 << "\n";

    }

    return 0;
}
