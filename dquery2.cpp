#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define SIZE 1000002
#define MAX 300002
#define MAX2 200002

int block, arr[MAX], counter[SIZE];
int currentAnswer=0;

int ans[MAX2];

struct query{
    int L, R, I;
} queries[MAX2];

bool compare(query a, query b){
    if(a.L/block != b.L/block){
        return a.L/block < b.L/block;
    }

    return a.R < b.R;
}

void add(int position){
    counter[arr[position]]++;

    if(counter[arr[position]]==1){
        currentAnswer++;
    }
}

void remove(int position){
    counter[arr[position]]--;

    if(counter[arr[position]]==0){
        currentAnswer--;
    }
}

int main(){
    optimizar_io

    int n, q;
    cin >> n;

    block = ceil(sqrt(n));

    for(int i=0;i<n;i++) cin >> arr[i];

    cin >> q;

    for(int i=0;i<q;i++){
        cin >> queries[i]. L >> queries[i].R;
        queries[i].L--;
        queries[i].R--;

        queries[i].I = i;
    }

    // cout << "Sorting " << q << endl;
    sort(queries, queries + q, compare);

    // cout << "sorted" << endl;
    int currentL=0, currentR=0;

    for(int i=0;i<q;i++){
        // cout << queries[i].L << " " << queries[i].R << endl;
        // cout << currentL << " " << currentR << endl;
        while(currentL < queries[i].L){
            remove(currentL);
            currentL++;
        }

        while(currentL > queries[i].L){
            add(currentL-1);
            currentL--;
        }

        while(currentR <= queries[i].R){
            add(currentR);
            currentR++;
        }

        while(currentR > queries[i].R + 1){
            remove(currentR-1);
            currentR--;
        }

        // cout << "A";
        ans[queries[i].I] = currentAnswer;
    }

    for(int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }


    return 0;
}