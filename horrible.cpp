#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 450000
#define ll long long int

ll arr[MAX];
ll st[MAX], lazy[MAX];

void reset(){
    for(int i=0;i<MAX;i++){
        arr[i] = 0;
        st[i]=0;
        lazy[i]=0;
    }
    // memset(arr, 0, sizeof(arr));
    // memset(st, 0, sizeof(st));
}

int getMid(int a, int b){
    return a + (b-a)/2;
}

int buildST(int *arr, int startIndex, int endIndex, int stIndex){
    
    if(startIndex == endIndex){
        st[stIndex] = arr[startIndex];
        return arr[startIndex];
    }

    int midIndex = getMid(startIndex, endIndex);

    st[stIndex] = buildST(arr, startIndex, midIndex, 2*stIndex + 1) + 
        buildST(arr, midIndex + 1, endIndex, 2*stIndex + 2);

    return st[stIndex];
}

int queryUtil(int queryStart, int queryEnd, int stStart, int stEnd, int stIndex){
    if(stStart >= queryStart && stEnd <= queryEnd){
        return st[stIndex];
    }

    if(stEnd < queryStart || stStart > queryEnd){
        return 0;
    }

    int mid = getMid(stStart, stEnd);

    return queryUtil(queryStart, queryEnd, stStart, mid, 2*stIndex+1) + 
        queryUtil(queryStart, queryEnd, mid+1, stEnd, 2*stIndex + 2);

}

int queryST(int queryStart, int queryEnd, int n){
    if(queryStart > queryEnd || queryStart < 0 || queryEnd > n-1){
        return 0;
    }

    return queryUtil(queryStart, queryEnd, 0, n-1, 0);
}

void updateSingleValUtil(int stStart, int stEnd, int updateIndex, int diff, int stIndex){
    if(updateIndex < stStart || updateIndex > stEnd){
        return;
    }

    st[stIndex] += diff;

    if(stStart != stEnd){
        int mid = getMid(stStart, stEnd);
        updateSingleValUtil(stStart, mid, updateIndex, diff, 2*stIndex + 1);
        updateSingleValUtil(mid+1, stEnd, updateIndex, diff, 2*stIndex+2);
    }

}

void updateSingleVal(int arr[], int index, int newValue, int n){
    if(index < 0 || index > n-1){
        return;
    }

    int diff = newValue - arr[index];

    updateSingleValUtil(0, n-1, index, diff, 0);


}

void updateRangeUtil(int stStart, int stEnd, int updateStart, int updateEnd, int diff, int stIndex){

    if(stStart > updateEnd || stEnd < updateStart){
        return;
    }

    if(stStart == stEnd){
        st[stIndex] += diff;
        return;
    }

    int midUpdateIndex = getMid(stStart, stEnd);
    updateRangeUtil(stStart, midUpdateIndex, updateStart, updateEnd, diff, 2*stIndex + 1);
    updateRangeUtil(midUpdateIndex+1, stEnd, updateStart, updateEnd, diff, 2*stIndex + 2);

    st[stIndex] = st[2*stIndex+1] + st[2*stIndex+2];
}

void updateRange(int arr[], int updateStart, int updateEnd, int newValue, int n){
    if(updateEnd < updateStart || updateStart < 0 || updateEnd > n-1 ){
        return;
    }

    int diff = newValue - arr[updateStart];
    
    updateRangeUtil(0, n-1, updateStart, updateEnd, diff, 0);
}

void printST(int n){
    cout << "\n";
    cout << "ST: " << "\n";
    for(int i=0;i<4*n;i++){
        cout << st[i] << "(" << i << ")" << "\t";
    }

    cout << "\n" << "LAZY: " << "\n";
    for(int i=0;i<4*n;i++){
        cout << lazy[i] << "(" << i << ")" << "\t";
    }

    cout << "\n";
}


void lazyUpdateUtil(ll stStart, ll stEnd, ll updateStart, ll updateEnd, ll diff, ll stIndex){
    if(lazy[stIndex] != 0){
        st[stIndex] += (stEnd-stStart+1)*lazy[stIndex];

        if(stStart != stEnd){
            lazy[2*stIndex + 1] += lazy[stIndex];
            lazy[2*stIndex + 2] += lazy[stIndex];
        }

        lazy[stIndex] = 0;
    }

    // if(stStart == stEnd){
    //     st[stIndex] += diff;
    //     return;
    // }

    if(stStart > updateEnd || stEnd < updateStart){
        return;
    }

    if(stStart >= updateStart && stEnd <= updateEnd){
        st[stIndex] += (stEnd-stStart+1)*diff;

        if(stStart != stEnd){
            lazy[2*stIndex + 1] += diff;
            lazy[2*stIndex + 2] += diff;
        }
        return;
    }

    ll mid = getMid(stStart, stEnd);

    lazyUpdateUtil(stStart, mid, updateStart, updateEnd, diff, 2*stIndex + 1);
    lazyUpdateUtil(mid+1, stEnd, updateStart, updateEnd, diff, 2*stIndex + 2);

    st[stIndex] = st[2*stIndex + 1] + st[2*stIndex + 2];
}

ll lazyQueryUtil(ll stStart, ll stEnd, ll queryStart, ll queryEnd, ll stIndex){
    if(lazy[stIndex] != 0){
        st[stIndex] += (stEnd-stStart+1)*lazy[stIndex];

        if(stStart != stEnd){
            lazy[2*stIndex + 1] += lazy[stIndex];
            lazy[2*stIndex + 2] += lazy[stIndex];
        }

        lazy[stIndex] = 0;
    }

    if(stStart > queryEnd || stEnd < queryStart){
        return 0;
    }

    if(stStart >= queryStart && stEnd <= queryEnd){
        return st[stIndex];
    }

    ll mid = getMid(stStart, stEnd);

    return lazyQueryUtil(stStart, mid, queryStart, queryEnd, 2*stIndex + 1) + 
        lazyQueryUtil(mid+1, stEnd, queryStart, queryEnd, 2*stIndex + 2);
}

void updateLazy(ll arr[], ll updateStart, ll updateEnd, ll newValue, ll n){
    if(updateEnd < updateStart || updateStart < 0 || updateEnd > n-1 ){
        return;
    }

    ll diff = newValue - arr[updateStart];
    
    lazyUpdateUtil(0, n-1, updateStart, updateEnd, diff, 0);
}

ll queryLazy(ll queryStart, ll queryEnd, ll n){
    if(queryStart > queryEnd || queryStart < 0 || queryEnd > n-1){
        return 0;
    }

    return lazyQueryUtil(0, n-1, queryStart, queryEnd, 0);
}


int main(){

    optimizar_io

    ll t;
    cin >> t;

    while(t--){
        ll n, q;
        cin >> n >> q;

        // buildST(arr, 0, n-1, 0);

        while(q--){
            ll type;
            cin >> type;

            if(type == 0){
                // int p, q, v;
                int p, q;
                ll v;
                cin >> p >> q >> v;

                p--;
                q--;

                // for(int i=p;i<=q;i++){
                //     updateSingleVal(arr, i, v, n);
                // }

                
                // updateRange(arr, p, q, v, n);
                updateLazy(arr, p, q, v, n);

                // printST(n);

            } else if(type == 1){
                int p, q;
                cin >> p >> q;
                p--;
                q--;

                // int ans = queryST(p, q, n);

                ll ans = queryLazy(p, q,n);

                cout << ans << "\n";
            } else{
                // printST(n);
            }
        }

        reset();
    }

    return 0;
}