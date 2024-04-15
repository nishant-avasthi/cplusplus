#include<bits/stdc++.h>
using  namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& permutations, int start) {
        if (start == nums.size()) {
            permutations.push_back(nums);
        } else {
            for (int i = start; i < nums.size(); ++i) {
                swap(nums[start], nums[i]);
                backtrack(nums, permutations, start + 1);
                swap(nums[start], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        backtrack(nums, permutations, 0);
        return permutations;
    }
};

int main(){
    vector<int> vec={1,2,3,4};

    Solution ss;
    vector<vector<int>> v=ss.permute(vec);

    for(auto& a: v){
        for(auto& b: a){
            cout<<b;
        }cout<<endl;
    }

}