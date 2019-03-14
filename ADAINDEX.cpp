#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 2000


struct node{
    char val;
    int count;

    vector<node*> children;
};

void printTrie(node* root, int level){
    cout << "Level " << level << "\n";
    cout << root->val << "\t" << root->count << "\n";

    for(node* temp: root->children){
        cout << "\n";
        printTrie(temp, level + 1);
        cout << "\n";
    }

    cout << "\n";
}


node* newNode(char a){
    node* temp = new node;
    temp->val = a;
    temp->count = 1;

    return temp;
}

node* insert(node* parent, char val){
    // if(parent->val == val){
    //     parent->count++;
    //     return parent;
    // }

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

node* find(node* parent, char val){
    // if(parent->val == val){
    //     return parent;
    // }

    for(node* temp: parent->children){
        if(temp->val == val){
            return temp;
        }
    }

    return NULL;
}

int findPrefix(node* root, string str){
    int ans = 0;

    node* temp = root;
    for(int i=0;i<str.length();i++){
        temp = find(temp, str[i]);
        if(temp == NULL){
            ans = -1;
            break;
        }
    }

    if(ans==-1){
        return 0;
    } else{
        return temp->count;
    }
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

    node* root = new node;
    root->count = 0;

    while(N--){
        string temp;
        cin >> temp;

        insertString(root, temp);
    }

    // printTrie(root, 0);

    while(Q--){
        string temp;
        cin >> temp;

        cout << findPrefix(root, temp) << "\n";
    }

    return 0;
}
