#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool isBadVersion(int k){
    return false;//or true;
}
    int firstBadVersion(int n) {
        if(n==1)return 1;
        int low = 0;
        int high = n;
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isBadVersion(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
        
        
    }
};