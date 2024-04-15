#include<bits/stdc++.h>
using namespace std;


  struct Node {
      int val;
      Node *next;
      Node(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(Node *head) {
        Node *prev, *fast;
        prev=head;
        fast=head;
        while(prev!=nullptr && fast!=nullptr && fast->next!=nullptr){
            
            prev=prev->next;
            fast=fast->next->next;if(fast==prev)return true;
        }
        
        return false;
    }
};


int main(){
     Solution s;
      Node* node1= new Node(5);
    Node* node2= new Node(2);
    Node* node3= new Node(3);
    Node* node4= new Node(555);
    Node* node5= new Node(5525);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=nullptr;

     if(s.hasCycle(node1))cout<<"true";
    else cout<<"false";
     
}