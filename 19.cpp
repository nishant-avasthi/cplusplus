#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums,vector<vector<int>>& ans ) {
        // int i?
    int n= nums.size();

    sort(nums.begin(), nums.end());


    for(int i = 0; i < n; i++) {
        if(i >0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;

        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if(sum > 0) {
                k--;

            }
            else if(sum < 0) {
                j++;

            }
            else{
                vector<int> temp = {nums[i] , nums[j] , nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && nums[j] == nums[j - 1]) j++;
                while(j < k && nums[k] == nums[k + 1]) k--;

            }
        }

    }

    return ans;
        
    }
};

int main(){
    vector<int> v={2,0,-1,22,-23,1};

    Solution Solution;
    vector<vector<int> >res;
    Solution.threeSum(v,res);

    for(auto& a: res){
        for(auto& b: a){
            cout<<b<<" ";
        }
        cout<<endl;
    }

    return 0;

}

for (int i = 0; i < count; i++)
{
    /* code */
    while(u<19)
    {
        
    }
}
