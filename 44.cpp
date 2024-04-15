#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> dp(n ,1);

        for(int i=1;i<m;++i){
            // vector<int> curr(m,0);
            dp[0]=1;
            for(int j=1;j<n;++j){
                // if(i==0&&j==0) curr[j]=1;
                
                // else{
                //     int up=0,left=0;
                //     if(i>0){
                //          up=prev[j];
                //     }
                //     if(j>0){
                //         left=curr[j-1];
                //     }

                //     curr[j]=up+left;
                // }
                dp[j]+=dp[j-1];

            }
            // prev=curr;
        }

        return dp[n-1];
        
    }
};

int main(){
     Solution s;
     cout<<s.uniquePaths(5,4);

     return 0;
}