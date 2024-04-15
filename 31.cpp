#include<bits/stdc++.h>
using namespace std;

// There is an integer array nums sorted in ascending order (with distinct values). 
// Given the array nums after the possible rotation and an integer target 
// return the index of target if it is in nums , or -1 is not in nums 
// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,mid;

        while(left<right){
            mid=left+ (right-left)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid-1]==target)return mid-1;
            if(nums[mid+1]==target)return mid+1;
            if(nums[left]<target&&nums[mid]>target){
                right=mid-1;
            }
            if(nums[mid]>target&&nums[mid]<target){
                left=
            }
        }
        
    }
};

int main(){
    vector<int> vec ={ 8,9,11,2,3,4,5,6};

    Solution s;
    int t =s.search(vec,11);

    cout<<t;
    return 0;
}