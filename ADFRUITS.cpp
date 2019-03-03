#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 105

string lcs(string X, string Y, int n, int m){
    int arr[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                arr[i][j] = 0;
                continue;
            }

            if(X[i-1] == Y[j-1]){
                arr[i][j] = 1 + arr[i-1][j-1];
            } else {
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }

    // cout << "\n";

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout << arr[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";

    // BACKTRACK

    int lcsLength = arr[n][m];
    bool matched[m];
    for(int i=0;i<=m;i++) matched[i] = false;

    int mapLcs[m];

    int i=n;
    // int j=m;
    int maxJ = m;
    while(i>0){
        int j = maxJ;

        while(j>0){
            if(arr[i][j] == lcsLength &&  arr[i][j] == arr[i-1][j-1] + 1 && X[i-1] == Y[j-1]){
                lcsLength--;
                matched[j-1] = true;
                mapLcs[j-1] = i-1;
                maxJ = j-1;
                break;
            }
            j--;
        }
        i--;
    }

    int inserted = 0, lastCommon = 0, allUpdated = 0;

    vector<char> ans(m+n-arr[n][m]);
    for(int i=0;i<n;i++){
        ans[i] = X[i];
    }

    for(int i=0;i<m;i++){
        // cout << i << "\t" << Y[i] << "\t" << matched[i] << "\n";
        if(!matched[i]){
            // cout << lastCommon << "\t" << inserted << "\t" << Y[i] << "\n";
            ans.insert(ans.begin() + lastCommon + inserted, Y[i]);
            inserted++;
            allUpdated++;
        } else{
            lastCommon = allUpdated + mapLcs[i] + 1;
            inserted = 0;
        }
    }

    string temp;

    for(int i=0;i<ans.size();i++){
        temp += ans[i];
    }

    return temp;
}

int main(){
    optimizar_io

    // char str[1000];
    string first, second;

    while(cin >> first && cin >> second)
	// while(scanf(" %[^\n]s", str) > 0)
	{
		// char first[200], second[200];
		// sscanf(str, "%s %s", first, second);

        // cout << first << lcs(first, second, strlen(first), strlen(second)) << "\n";
        cout << lcs(first, second, first.length(), second.length()) << "\n";
	}

    return 0;
}