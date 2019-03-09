#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 5005

int dp[MAX];


bool isDual(char prev, char current){
    if(prev == '1' || (prev == '2' && (current-'0') <= 6 )) return true;
    else return false;
}

int main(){
    optimizar_io

    string arr;
    while(true){
        cin >> arr;
        if(arr == "0") break;

        for(int i=0;i<=arr.length();i++) dp[i] = 0;

        bool invalid = false;

        for(int i=0;i<arr.length();i++){
            if(i==0){
                if(arr[i] == '0'){
                    invalid = true;
                    break;
                }
                dp[i] = 1;
                continue;
            }
            // if(i==0 && arr[i] != '0'){
            //     dp[i] = 1;
            //     continue;
            // }

            if(i==1){
                if(arr[i] == '0'){
                    if(arr[i-1] == '1' || arr[i-1] == '2'){
                        dp[i] = 1;
                        continue;
                    } else{
                        invalid=true;
                        break;
                    }
                }

                if(isDual(arr[i-1], arr[i])){
                    dp[i] = 2;
                } else{
                    dp[i] = dp[i-1];
                }
                continue;
            }

            if(arr[i] == '0'){
                if(arr[i-1]=='1' || arr[i-1] == '2'){
                    dp[i] = dp[i-2];
                    continue;
                } else{
                    invalid = true;
                    break;
                }
            }

            if(isDual(arr[i-1], arr[i])){
                dp[i] = dp[i-1] + dp[i-2];
            } else{
                dp[i] = dp[i-1];
            }
        }

        // cout << "\n";
        // for(int i=0;i<arr.length();i++){
        //     cout << dp[i] << "\t";
        // }
        // cout << "\n";

        if(invalid){
            cout << "0\n";
        } else{
            cout << dp[arr.length()-1] << "\n";
        }
    }

    return 0;
}
