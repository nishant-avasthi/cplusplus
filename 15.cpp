#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxi = 0;
        while(left<right){
            int area = min(height[left], height[right]) * (right-left);
            maxi = max(maxi, area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxi;
    }
};

int main(){
    Solution so;
    vector<int> heights ={1,8,6,2,5,4,8,3,7};

    cout<<so.maxArea(heights)<<endl;

    return 0;
}