#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        TreeNode* left,*right;
        int val;
        TreeNode(int val):val(val),left(nullptr),right(nullptr){};

};
class Solution {

bool isPossible(TreeNode* root, long long l, long long r){
    if(root == nullptr)  return true;
    if(root->val < r and root->val > l)
        return isPossible(root->left, l, root->val) and 
                                isPossible(root->right, root->val, r);
    else return false;
}

public:
    bool isValidBST(TreeNode* root) {
        long long int min = -1000000000000, max = 1000000000000;
        return isPossible(root, min, max);
    }
};

int main(){
    Solution s;
    TreeNode *node1= new TreeNode(76);
    TreeNode *node2= new TreeNode(3);
    TreeNode *node3= new TreeNode(71);

    node1->left=node2;
    node1->right=node3;
    cout<<(s.isValidBST(node1)?"true":"false");
    return 0;


}