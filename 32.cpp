#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void Sum(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& r, int i)
    {
        
        if(target == 0)
        {
            res.push_back(r);
            return;
        }
        
        while(i <  candidates.size() && target - candidates[i] >= 0){
            r.push_back(candidates[i]);
            Sum(candidates,target - candidates[i],res,r,i);
            ++i;
            r.pop_back();
        }
}

    
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> r;
        vector<vector<int> > res;
        
        Sum(candidates,target,res,r,0);
        
        return res;
    }
};


int main(){
    vector<int> vec ={ 2,3,4,5,6,8,9,11};

    Solution s;
    vector<vector<int>> t =s.combinationSum(vec,11);
    for(auto& a: t){
        for(auto& b:a){
            cout<<b<<" "<<endl;
        }
    }
    return 0;
}

