#include<bits/stdc++.h>
using namespace std;

auto search(vector<int> &v,int k){
    int left=0;
    int right=v.size()-1;
     while (left<right)
     {
        /* code */
        int mid= left +(right-left)/2;
        if(v[mid]==k)return mid;
        else if(k>v[mid])left=mid;
        else if(k<v[mid])right=mid;
     }
     

}

int main(){
    vector<int> v={1,2,3,4,5,6,7,8,9};

    // cout<<v[4];



    cout<<search(v,8);

    return 0;
}