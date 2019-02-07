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

int main(){

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int u, v;
        cin >> u >> v;

        node* temp = newNode(v);
        tree[u].child.push_back(temp);
    }

    cout << getDiameter(&tree[0]);

    return 0;
}


