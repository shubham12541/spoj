#include <bits/stdc++.h>
using namespace std;

#define MAX 100005

struct node{
    int key;
    vector<node *> child; 
} tree[MAX];


node* newNode(int value){
    node* temp = new node;
    temp->key = value;

    return temp;
}

int depthOfTree(node* root){
    if(!root){
        return 0;
    }

    int maxDepth = 0;

    for(int i=0;i<root->child.size(); i++){
        maxDepth = max( maxDepth, depthOfTree(root->child[i]) );
    }   

    return maxDepth + 1;
}

int getDiameter(node *root){
    if(!root) return 0;

    int max1=0, max2=0;
    for(int i=0;i<root->child.size();i++){
        node* temp = root->child[i];

        int depth = depthOfTree(temp);

        if(depth > max1){
            max1 = depth;
            max2 = max1;
        } else if(depth > max2){
            max2 = depth;
        }
    }

    int maxDia= 0;
    for(int i=0;i<root->child.size();i++){
        node* temp = root->child[i];

        int diameter = getDiameter(temp);
        if(diameter > maxDia){
            maxDia = diameter;
        }
    }

    return max( 1 + max1 + max2, maxDia );
}

void printGraph(int n){
    for(int i=1;i<=n;i++){
        cout << tree[i].key << "\t-\t";
        node* temp = &tree[i];

        // for(int i=0;i<temp->child.size();i++){
        //     cout << temp->key << "\t";
        // }

        for(node* temp: (&tree[i])->child){
            cout << temp->key << "\t";
        }

        cout << "\n";
    }

    cout << "\n";
}

int main(){

    int n;
    cin >> n;

    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;

        node* temp = newNode(v);
        tree[u].key = u;
        tree[u].child.push_back(temp);
    }

    printGraph(n);

    cout << getDiameter(&tree[1]);

    return 0;
}


