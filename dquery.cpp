#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked

int n;
int block;
int counter[1111111];
int *arr;
int *ans;
int currentAnswer=0;

struct Query{
    int L, R, I;
};

inline long long int sscan()
{
   long long int n=0;
   int ch=gc();
   while( ch < '0' || ch > '9' )
        ch=gc();
   while(  ch >= '0' && ch <= '9' )
    {
        n = (n<<3)+(n<<1) + ch-'0';
        ch=gc();
    }

   return n;
}

inline void lprint(long int a)
{                                       /**for print long int**/
    int i=0;
    char S[20];
    while(a>0)
    {
        S[i++]=a%10+'0';
    a=a/10;
    }
    --i;
    while(i>=0)
    pc(S[i--]);
    pc('\n');
}


bool compare(Query a, Query b){
    if(!a.L/block != b.L/block){
        return a.L/block < a.L/block;
    }

    return a.R < b.R;
}

void add(int position){
    counter[arr[position]]++;

    if(counter[arr[position]] == 1){
        currentAnswer++;
    }
}

void remove(int position){
    counter[arr[position]]--;

    if(counter[arr[position]] == 0){
        currentAnswer--;
    }
}

int main(){

    int n, q;
    n = sscan();
    // scanf("%d", &n);
    block = sqrt(n);

    arr = (int *)malloc(n*sizeof(int));
    

    for(int i=0;i<n;i++) {
        // scanf("%d", &arr[i]);
        arr[i] = sscan();
    } 

    q = sscan();
    // scanf("%d", &q);

    ans = (int *)malloc(q*sizeof(int));

    Query* queries = new Query[q];
    for(int i=0;i<q;i++){
        Query temp;
        temp.L = sscan();
        temp.R = sscan();
        // scanf("%d %d", &temp.L, &temp.R);
        temp.L--;
        temp.R--;
        temp.I = i;

        queries[i] = temp;
    }

    sort(queries, queries+q, compare);

    int currentL = 0, currentR = 0;
    
    for(int i=0;i<q;i++){
        Query temp = queries[i];

        while(currentL < temp.L){
            remove(currentL);
            currentL++;
        }

        while(currentL > temp.L){
            add(currentL - 1);
            currentL--;
        }

        while(currentR <= temp.R){
            add(currentR);
            currentR++;
        }

        while(currentR > temp.R + 1){
            remove(currentR - 1);
            currentR--;
        }

        ans[temp.I] = currentAnswer;
    }

    for(int i=0;i<q;i++){
        // printf("%d\n", ans[i]);
        lprint(ans[i]);
    }

    return 0;
}