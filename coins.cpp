#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 1000000001
#define ll long long int

vector<ll> dp(MAX, -1);
// ll* dp = new ll[MAX];

ll getAns(ll n){
    if(dp[n] != -1) return dp[n];
    dp[n] = max(n, getAns(n/2) + getAns(n/3) + getAns(n/4));
    return dp[n];
}

int main(){
    optimizar_io

    ll n;

    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=4;
    
    while(cin >> n){
        cout << getAns(n) << "\n";
    }

    return 0;
}