#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);

        int area=0;

        for(int i=0;i<heights.size();++i){
            while(!s.empty()&& heights[i]<heights[s.top()]){
                int h=heights[s.top()];
                s.pop();
                int w= (s.empty())?i:i-s.top()-1;
                area=max(area,h*w);
            }
            s.push(i);
        }
        return area;
    }
};

int main(){
    vector<int> height={1,2,1};

    Solution s;

    cout<<s.largestRectangleArea(height)<<endl;

    return 0;

}