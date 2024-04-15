#include<bits/stdc++.h>
using namespace std;

// "Given a binary search tree (BST), find the lowest common ancestor (LCA) 

// node of two given nodes in the BST.
// According to the definition of LCA on Wikipedia: “The lowest common 
// ancestor is defined between two nodes p and q as the lowest node in T
// that has both p and q as descendants (where we allow a node to be a
// descendant of itself).”"
 struct Node{
    Node *left,*right;
    int val;
    Node(int val):val(val),left(nullptr),right(nullptr){}
 };
 

class Solution {
public:
    Node* lowestCommonAncestor(Node* root, int p, int q) {
        // TreeNode *res;
        int pval=p;
        int qval=q;

        if(!root)return nullptr;
        // if(root->val==pval||root->val ==qval)return root;

        if(root->val>pval && root->val> qval)return lowestCommonAncestor(root->left,p,q);
        else if(root->val<pval && root->val <qval)return lowestCommonAncestor(root->right,p,q);
        else return root;
        
    }
};



int main(){
    Node* node1= new Node(2);
    Node* node2= new Node(1);
    Node* node3= new Node(3);
    Node* node4= new Node(4); 
    Node* node5= new Node(5);
    Node* node6= new Node(6); 
    Node* node7= new Node(7);
    Node* node8= new Node(8);
    node1->left=node2;
    node1->right=node3;
    node3->right=node4;
    node4->right=node5;
    node5->right=node6;
    node6->right=node7;
    node7->right=node8;

    Solution s ;
    int ss=s.lowestCommonAncestor(node1,7,8)->val;

    cout<<ss;



    return 0;
}