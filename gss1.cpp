#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 50002

int arr[MAX];

struct node{
    int max, sum, leftMax, rightMax;
    bool isNull;
} st[4*MAX];

int getMid(int a, int b){
    return a + (b-a)/2;
}

node getNullNode(){
    node temp;
    temp.isNull = true;
    return temp;
}


node combineNodes(node a, node b){
    if(a.isNull && b.isNull){
        return getNullNode();
    }
    if(a.isNull) return b;
    if(b.isNull) return a;

    node temp;

    temp.leftMax = max(a.leftMax, a.sum + b.leftMax);
    temp.rightMax = max(b.rightMax, b.sum + a.rightMax);
    temp.sum = a.sum + b.sum;
    temp.max = max( 
        max(temp.leftMax, temp.rightMax),  
        max( 
            max(a.max, b.max), 
            a.rightMax + b.leftMax
        ) 
    );
    temp.isNull = false;

    return temp;

}


node buildST(int* arr, int startIndex, int endIndex, int stIndex){
    if(startIndex == endIndex){
        node temp;
        temp.leftMax = arr[startIndex];
        temp.rightMax = arr[startIndex];
        temp.max = arr[startIndex];
        temp.sum = arr[startIndex];

        temp.isNull = false;

        st[stIndex] = temp;

        return temp;
    }

    int midIndex = getMid(startIndex, endIndex);

    st[stIndex] = combineNodes(
        buildST(arr, startIndex, midIndex, 2*stIndex + 1),
        buildST(arr, midIndex + 1, endIndex, 2*stIndex + 2)
    );

    return st[stIndex];
}

node queryUtil(int segStart, int segEnd, int queryStart, int queryEnd, int stIndex){

    if(segStart >= queryStart && segEnd <= queryEnd){
        return st[stIndex];
    }

    if(segEnd < queryStart || segStart > queryEnd){
        return getNullNode();
    }

    int segMidIndex = getMid(segStart, segEnd);

    return combineNodes(
        queryUtil(segStart, segMidIndex, queryStart, queryEnd, 2*stIndex+1),
        queryUtil(segMidIndex + 1, segEnd, queryStart, queryEnd, 2*stIndex+2)
    );

}

node queryST(int n, int queryStart, int queryEnd){
    if(queryStart < 0 || queryEnd > n-1 || queryStart > queryEnd){
        return getNullNode();
    }

    return queryUtil(0, n-1, queryStart, queryEnd, 0);

}

int main(){
    optimizar_io

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int m;
    cin >> m;

    buildST(arr, 0, n-1, 0);

    // for(int i=0;i<4*n;i++){
    //     if(st[i].isNull) {
    //         cout << "NULL" << "\t";
    //     } else{
    //         cout << st[i].max << "\t";
    //     }
        
    // }


    while(m-- > 0){
        int L, R;
        cin >> L >> R;
        L--;
        R--;

        node ans = queryST(n, L, R);

        cout << ans.max << "\n";
    }
}