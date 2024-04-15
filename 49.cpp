#include<bits/stdc++.h>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        vector<pair<int,ListNode*>>v;
        for(int i = 0; i<lists.size(); i++)
        {
            ListNode* temp = lists[i];
            while(temp)
            {
                v.push_back({temp->val,temp});
                temp = temp->next;
            }
        }

        if(v.empty())
        {
            return NULL;
        }

        sort(v.begin(),v.end());
        for(int i = 0; i<v.size()-1; i++)
        {
            v[i].second->next = v[i+1].second;
        }
        v[v.size()-1].second->next = NULL;

        return v[0].second;
    }
};