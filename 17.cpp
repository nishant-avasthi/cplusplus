#include<bits/stdc++.h>
using namespace std;


class kClose {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k,vector<vector<int>> &ans) {
       
       vector<pair<int, vector<int>>> v; 
        for(int i = 0; i < points.size(); i++){
            int s = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            v.push_back({s, {points[i][0],points[i][1]}});
        }
        sort(v.begin(), v.end());
        int j = 0;
        while(k-- > 0 ){
            ans.push_back(v[j++].second);
        }

       return ans; 
    }
};

int main (){

    vector<vector<int>> res,v={{1,2},{3,23},{3,4},{8,8},{34,6},{33,44}};
    kClose kclose;


    res=kclose.kClosest(v,1,res);

    for(auto & a:res){
        for(auto & b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }

    return 0;


}
