#include<bits/stdc++.h>
using namespace std;

// Given a binary tree, find the lowest common ancestor (LCA)
//  of two given nodes in the tree



 struct TreeNode {
    int val;
    TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TreeNode *res;
        if(root==nullptr||root==p||root==q)return root;

        TreeNode* right=lowestCommonAncestor(root->left,p,q);
        TreeNode* left=lowestCommonAncestor(root->right,p,q);

        return !left? right: !right? left:root;
        
    }
};