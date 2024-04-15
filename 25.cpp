#include<bits/stdc++.h>
using namespace std;


class Solution {
public:    
    int findLowestCoins(vector<int> &coins, int cur, int amount) {
        if (cur >= coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX - 1;   
        
        int res = -1;
        if (coins[cur] > amount) {
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            res = doNotTakeCoin;
        }
        else {
            int takeCoin = 1 + findLowestCoins(coins, cur + 0, amount - coins[cur]);
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            res = min(takeCoin, doNotTakeCoin);
        }
        return res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int res = findLowestCoins(coins, 0, amount);
        return  (res == INT_MAX-1) ? -1 : res; 
    }
};

int main(){
    vector<int> v={1,2,3,4,5,6,7,9};
    int amount = 615;

    Solution s;
    int n=s.findLowestCoins(v,0,amount);
    cout<<n<<endl;

    return 0;
}