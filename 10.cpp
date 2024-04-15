 #include<bits/stdc++.h>
 using namespace std;

 
 struct Node {
 int val;
      Node *left;
     Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
     Node(int x) : val(x), left(nullptr), right(nullptr) {}
     Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int height(Node* root){
        if(root==nullptr)return 0;
         
         return 1+max(height(root->left),height(root->right));
}


    bool isBalanced(Node* root) {
        if(root==nullptr)return true;
        int n= height(root->left);
        int  m=height(root->right);
        if(abs(n-m)>1)return false;
         
         return isBalanced(root->left)&&isBalanced(root->right);
        

        
    }
};

int main(){
     Node* node1= new Node(5);
    Node* node2= new Node(2);
    Node* node3= new Node(3);
    Node* node4= new Node(555);
    Node* node5= new Node(5525);
    node1->left=node2;
    node1->right=node3;
    node3->right=node4;
    node4->right=node5;
    Solution s;

    if(s.isBalanced(node1))cout<<"true";
    else cout<<"false";

    return 0;
    
}