#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    auto maxx(TreeNode* root, int &d){
        if(root==nullptr)return 0;
        int left=maxx(root->left,d);
        int rt = maxx(root->right,d);

        d=max(d,left+rt);

        return 1+max(left,rt);     

    }
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;

        int d=0;
        maxx(root,d);
        cout<<d;
        return 0;      
    }
};