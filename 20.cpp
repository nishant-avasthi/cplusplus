#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *left,*right;
    int val;
    Node(int val): val(val),left(nullptr),right(nullptr){}

};
class  Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;

        if(!root)return v;

        queue<Node*> que;

        que.push(root);
        while(!que.empty()){
            int s=que.size();
            vector<int> res;
            while(s>0){
                int data= que.front()->val;

                res.push_back(data);
                if(que.front()->left!=nullptr)que.push(que.front()->left);
                if(que.front()->right!=nullptr)que.push(que.front()->right);

                que.pop();
                s--;
            }
            v.push_back(res);
        }

        return v;
        
    }
};

int main(){
    Solution Solution;

     Node* node1= new Node(5);
    Node* node2= new Node(2);
    Node* node3= new Node(3);
    Node* node4= new Node(555);
    Node* node43= new Node(5587685);
    node1->left=node2;
    node1->right=node3;
    node3->right=node4;
    node4->right=node43;
    vector<vector<int>> p=Solution.levelOrder(node1);
    for(auto& a: p){
        for(auto& b: a){
            cout<<b<<" ";
        }
        cout<<endl;
    }

    return 0;


}