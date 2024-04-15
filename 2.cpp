#include<bits/stdc++.h>
using namespace std;


struct Node{
    Node *left, *right;
    int val;
    Node(int val):val(val){};
};

auto maxdepth(Node*root){
    
    if(root==nullptr)return 0 ;

    return 1+max(maxdepth(root->left),maxdepth(root->right));
}

int main(){
    
    Node* node1= new Node(5);
    Node* node2= new Node(2);
    Node* node3= new Node(3);
    Node* node4= new Node(555);
    Node* node43= new Node(555);
    node1->left=node2;
    node1->right=node3;
    node3->right=node4;
    node4->right=node43;

    cout<<maxdepth(node1);

    return 0;


}