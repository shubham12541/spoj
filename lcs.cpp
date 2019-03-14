#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 50002


void lcs(char *X, char *Y, int n, int m){
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }

            if(X[i-1] == Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else{
                dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // BACKTRACK

    int i = n+1;
    int lastJ = m+1;

    int currentMatch = dp[n][m];

    while(i>0){
        int j = lastJ;
        while(j>0){
            if(dp[i][j] == dp[i-1][j-1] && )
        }

        i--;
    }

}

int main(){

}