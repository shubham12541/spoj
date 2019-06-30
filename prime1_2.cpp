#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);


void storeSieve(int limit, vector<int> &primes, int low, int high){
    bool marked[limit+1];
    memset(marked, true, sizeof(marked));

    for(int i=2;i*i<limit;i++){

        if(marked[i]){

            for(int j=i*2;j<limit;j+=i){
                marked[j] = false;
            }
        }
    }

    for(int i=2;i<limit;i++){
        if(marked[i]) {
            primes.push_back(i);

            if(i>=low && i<=high){
                cout << i << "\n";
            }
        }
    }

}

int main(){

    optimizar_io

    int t;
    cin >> t;

    while(t--){
        long long int a, b;
        cin >> a >> b;

        vector<int> primes;
        int limit = floor(sqrt(b)) + 1;

        storeSieve(limit, primes, a, b);

        long long int segLow = a;
        long long int segHigh = b;

        if(segLow < limit){
            segLow = limit;
        }

        bool marked[(segHigh - segLow) + 1];
        memset(marked, true, sizeof(marked));

        for(int i=0;i<primes.size();i++){

            int loLim = floor(segLow/primes[i])*primes[i];
            if(loLim < segLow){
                loLim += primes[i];
            }

            for(int j=loLim;j <= segHigh;j += primes[i]){
                marked[j-segLow] = false;
            }
        }

        for(int i=segLow;i <= segHigh;i++){
            if(marked[i-segLow] && i >= a && i <= b){
                cout << i << "\n";
            }
        }

        cout << "\n";

    }

}

