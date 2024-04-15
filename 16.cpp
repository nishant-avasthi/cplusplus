#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *left, *right;
    int data;
    Node(int val):data(val),left(nullptr),right(nullptr){};

};

void ksmallest(Node* root, vector<int> &v){

    if(!root)return;

    ksmallest(root->left,v);
    v.push_back(root->data);
    ksmallest(root->right,v);



}


int main(){
    Node* node1= new Node(3);
    Node* node2= new Node(2);
    Node* node3= new Node(5);
    Node* node4= new Node(5565);
    Node* node43= new Node(55665);
    node1->left=node2;
    node1->right=node3;
    node3->right=node4;
    node4->right=node43;
    vector<int> v;
    int k=4;

    ksmallest(node1,v);
    // for(auto &a : v)
    cout<<v[k-1]<<endl;

    return 0;
}