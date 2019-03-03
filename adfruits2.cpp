#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 10001


string lcs(string X, string Y, int n, int m){
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
                continue;
            }

            if(X[i-1] == Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // cout << "\n";

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout << dp[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";

    // BACKTRACK

    bool matchedX[n];
    bool matchedY[m];

    for(int i=0;i<n;i++) matchedX[i] = false;
    for(int i=0;i<m;i++) matchedY[i] = false;

    int i=n, j = m;
    while(true){
        if(i==0 || j==0){
            break;
        }

        if(X[i-1] == Y[j-1]){
            matchedX[i-1] = true;
            matchedY[j-1] = true;
            i--;
            j--;
        } else{
            if(dp[i-1][j] >= dp[i][j-1]){
                i--;
            } else{
                j--;
            }
        }
    }

    // cout << "\n";
    // for(int i=0;i<n;i++) cout << matchedX[i] << "\t";
    // cout << "\n";

    // for(int i=0;i<m;i++) cout << matchedY[i] << "\t";
    // cout << "\n";

    i=0;
    j=0;

    string ans = "";

    while(i<n && j<m){
        int temp = i;
        while(matchedX[temp]==false && temp<n){
            ans += X[temp];
            temp++;
        }

        int temp2 = j;
        while(matchedY[temp2] == false && temp2<m){
            ans += Y[temp2];
            temp2++;
        }

        while(matchedX[temp]==true && matchedY[temp2]==true && X[temp]==Y[temp2]){
            ans += X[temp];
            temp++;
            temp2++;
        }

        i = temp;
        j = temp2;
    }

    while(i<n){
        ans += X[i];
        i++;
    }

    while(j<m){
        ans += Y[j];
        j++;
    }

    return ans;


}

int main(){

    optimizar_io

    string X, Y;

    while(cin >> X && cin >> Y){
        cout << lcs(X, Y, X.length(), Y.length()) << "\n";
    }

    return 0;

}

