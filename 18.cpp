#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int lt=0;
        int maxval=0;
        unordered_set<char> ss;

         for(int rt=0;rt<s.size();rt++){
                if(ss.count(s[rt])==0){
                    ss.insert(s[rt]);
                    maxval=max(maxval,rt-lt+1);

                    
                }else{
                    while(ss.count(s[rt])){
                        ss.erase(s[lt]);
                        lt++;
                    }

                    ss.insert(s[rt]);


                }



         }

         return maxval;
        
    }
};

int main(){

    Solution solution;
     string s="abcabdahjghgtreopfgr";

     cout<<solution.lengthOfLongestSubstring(s)<<endl;

     return 0;
}