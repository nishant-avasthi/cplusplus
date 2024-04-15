#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// clas


class Solution {
public:
    void dfs(Node* node, unordered_map<Node*,Node*> & m){
        // vector<Node*> vec;
        
        Node* newNode= new Node(node->val);

        m[node]=newNode;
        for(int i=0;i<node->neighbors.size();i++){
            Node* temp= node->neighbors[i];
            if(m.find(temp)==m.end()){
                m[temp]=new Node(temp->val);dfs(temp,m);
            }
            m[node]->neighbors.push_back(m[temp]);
            
        }

        

    }
    Node* cloneGraph(Node* node) {

        Node* root = new Node();
        unordered_map<Node*,Node*> m;

        if(root==NULL)return NULL;
        if(root->neighbors.size()==0){
            root->val=node->val;
            return root;
        } 

        
         dfs(node,m);

         return m[node];

        
        
    }
};