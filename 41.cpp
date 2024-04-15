#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>v;
    void solve(int i, vector<int>& nums, vector<int>&subset){
        if(i == nums.size()){
            v.push_back(subset);
            return;
        } 
        // !take
        solve(i+1, nums, subset);
        // take
        subset.push_back(nums[i]);
        solve(i+1, nums, subset);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        solve(0, nums, subset);
        return v;
    }
};

int main(){
    Solution s;
    vector<int> vec={1,2,3,4};
    vector<vector<int>> res =s.subsets(vec);
    for(auto& aa: res){
        for(auto& bb: aa){
            cout<<bb<<",";
        }cout<<" ";
    }
    
    return 0;
}