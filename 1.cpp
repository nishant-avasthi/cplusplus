#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data): data(data),next(nullptr){};
};

void printdd(Node* head){
    while(head!=nullptr){
        cout<<head->data<<endl;
        head=head->next;
    }
}

void getmiddle(Node* head){
    if(head==nullptr)cout<<"null";
    Node* prev,*nextt;
    nextt=head;
    prev=head;
    int n=0;
    while(nextt!=nullptr&&nextt->next!=nullptr){
        nextt=nextt->next->next;
        prev=prev->next;
        n++;
    }

    cout<<prev->data;

}

Node* createnode(vector<int> &val){
    Node* prev=nullptr, *head=nullptr;
    for(auto &a: val){
        Node* newNode = new Node(a);
        if(head==nullptr){
            head=newNode;
            prev=head;
        }else{
            prev->next=newNode;
        }

        prev=newNode;
    }

    return head;

}

int main(){

   vector<int> v={12,21,21,2,3,7,32,2,30,23,3,3,2,3,2};


   Node* p= createnode(v);

   printdd(p);
   getmiddle(p);


   return 0;
     


}