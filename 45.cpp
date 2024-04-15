#include<bits/stdc++.h>
using namespace std;

// "The median is the middle value in an ordered integer list. If the size of the list is even,
//  there is no middle value, and the median is the mean of the two middle values. For example, 
// for arr = [2,3,4] , the median is 3 For example, for arr = [2,3] , the median is (2 + 3) / 2 = 2.5
// Write a program to multiply two matrixes (general matrix, can be square or rectangular)
// Write a program to find if there is any repetition of number in an array of integer. 
// Write a program to reverse a single linked-list. "
class Solution{
    public:
        double solve1(vector<int>& vec){
            sort(vec.begin(),vec.end());
            int c=vec.size()/2;
            if((vec.size())%2==0){
                cout<<"hgfh";
                return (vec[c]+vec[c-1])/2;
            }else return vec[c+1];
        }

};
class a{
    public:
        int soll(vector<int>& vec){
            set<int> s;
            int i=0;
             
             for(auto& a: vec){
                i++;
                s.insert(a);
                if(s.size()!=i)return a;
             }

             return -1;

        }
};
class TreeNode{
    public:
        TreeNode* next;
        int val;
        TreeNode(int val):val(val),next(nullptr){};

};

class b{
    public:
        TreeNode* reverseList(TreeNode* head){
        if(head == NULL || head->next == NULL) return head;
        TreeNode* prev = NULL;
        TreeNode* h2 = reverseList(head->next);
        head->next->next = head;
        head->next=prev;
        return h2;
  

        }
};

int main(){
    vector<int> vec={1,2,62,3,4,3,34};

    Solution s;
    double k=s.solve1(vec);
    cout<<k;
     
     TreeNode *root= new TreeNode(7);
     TreeNode *node1= new TreeNode(76);
    TreeNode *node2= new TreeNode(3);
    TreeNode *node3= new TreeNode(71);

    a aa;
    cout<<aa.soll(vec);
    // cout?

    b bb;
    cout<<bb.reverseList(root);

    return 0;


}