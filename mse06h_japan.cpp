#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 2000


int main(){
    optimizar_io

    int t;
    cin >> t;

    while(t--){
        int n, m, k;
        cin >> n >> m >> k;

        int arr[n][m];
        int dp[n][m];

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) arr[i][j] = 0;

        while(k--){
            int a, b;
            cin >> a >> b;
            arr[--a][--b] = 1;
        }

        long long int ans = 0;

        cout << "\n";
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << arr[i][j] << "\t";
            }
            cout << "\n";
        }

        cout <<  "\n";
        


        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                int tempMax = 0;

                if(i==0 && j== m-1){
                    dp[i][j] = 0;
                    continue;
                } else if(j == m-1){
                    tempMax = max(tempMax, dp[i-1][j]);
                } else if(i == 0){
                    tempMax = max(tempMax, dp[i][j+1]);
                } else{
                    tempMax = max(dp[i-1][j+1],  max( dp[i-1][j], dp[i][j+1]));
                }

                if(arr[i][j]){
                    dp[i][j] = 1 + tempMax;
                    ans += dp[i][j];
                } else{
                    dp[i][j] = tempMax;
                }

            }
        }

        cout << "\n";

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << dp[i][j] << "\t";
            }
            cout << "\n";
        }

        cout <<  "\n";

        cout << ans << "\n";

    }

    return 0;
}