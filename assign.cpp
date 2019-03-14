#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long int
#define MAX 20

int like[MAX][MAX];
ll dp[1 << MAX];

// check ith bith in x
bool checkBit(int x, int i){
    return ((x>>i) & 1);
}

int main(){
    optimizar_io

    int t;
    cin >> t;

    while(t--){
        int N;
        cin >> N;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cin >> like[i][j];
            }
        }
        int NMAX = (1<<N);
        for(int i=0;i<NMAX;++i) {
            dp[i] = 0;
        }
        dp[NMAX-1] = 1;
        for(int b=NMAX-1;b>=0; --b) {
            int n = b;
            int k = 0;
            while(n){
                k += (n&1);
                n /= 2;
            }
            for(int i=0;i<N;++i){
                if(like[k][i] && !(b & (1<<i))){
                    dp[b] += dp[b | (1<<i)];
                }
            }
        }
        cout << dp[0] << endl;

    }

    return 0;
}