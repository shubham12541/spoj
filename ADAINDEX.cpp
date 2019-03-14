#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 2000


struct node{
    char val;
    int count;

    vector<node*> children;
};


node* newNode(char a){
    node* temp;
    temp->val = a;
    temp->count = 1;

    return temp;
}

node* insert(node* parent, int val){
    if(parent->val == val){
        parent->count++;
        return parent;
    }

    for(node* temp: parent->children){
        if(temp->val == val){
            temp->count++;
            return temp;
        }
    }

    node* temp = newNode(val);
    parent->children.push_back(temp);
    return temp;
}

int findPrefix(node* parent, string str){
    
}

void insertString(node* root, string str){
    node* temp = root;
    for(int i=0;i<str.length();i++){
        temp = insert(temp, str[i]);
    }
}


int main(){
    optimizar_io

    int N, Q;
    cin >> N >> Q;

    node* root;
    root->val = NULL;
    root->count = 0;

    for(int i=0;i<N;i++){
        string temp;
        cin >> temp;
    }

    return 0;
}
