#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int len = s.size();
//         if (len == 0)
//             return "";
//         int right = 0;
//         int left = 0;
//         int mid = 0;
//         int maxLen = 0;
//         int maxPos = 0;

//         while(mid <= len){
//             left = mid;
//             right = mid;
            
//             while(right+1 < len && s[right] == s[right+1]){
//                 right += 1;
//             }

//             mid = right+1;

//             while(left-1 >= 0 && right+1 < len && s[left-1] == s[right+1]){
//                 left--;
//                 right++;
//             }

//             if(maxLen < right-left+1){
//                 maxLen = right-left+1;
//                 maxPos = left;
//             }
//         }
//         return s.substr(maxPos, maxLen);
//     }
// };
// int main(){
//     string s="abbada";
//     Solution ss;
//     cout<<ss.longestPalindrome(s);

// return 0;
// }'


        bool isPalindrome(const string& s,int left, int right){
            while(left<right){
                if(s[left]!=s[right])return false;
                left++;
                right--;
            }
            return true;
        }

        void solve(const string& s, int left,int right, int& ans, string& palin,vector<vector<int>>& dp){

            if(left>right)return ;
            if(dp[left][right]!=-1){
                ans=max(ans, dp[left][right]);
                return;
            } 

            if(isPalindrome(s,left,right)){
                
                dp[left][right]=right-left+1;
                ans=max(ans,right-left+1);
                
                if(right-left+1>palin.size())
                palin= s.substr(left,right-left+1);

            }else{

                solve(s,left+1,right-1,ans,palin,dp);
                solve(s,left+1,right,ans,palin,dp);
                solve(s,left,right-1,ans,palin,dp);
                
                
            }

            return ;


}



    int main(){
    string s="abbba";
    int left=0, right=s.size()-1;
    int ans=1;
    string palin="";
    vector<vector<int>> dp(right+1,vector<int>(right+1,-1));

    solve(s,left,right,ans,palin,dp);
     
     cout<<palin<<"  "<<ans<<endl;

     return 0;
}