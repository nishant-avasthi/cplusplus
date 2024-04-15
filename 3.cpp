#include <bits/stdc++.h>
using namespace std;
int main(){
    string p="1101";
    string q= "1";

    string res;
    int a= p.length()-1;
    int b= q.length()-1;
    int carry=0;
    while(a>=0||b>=0||carry){
        int sum=carry;

        if(a>=0)sum=sum+p[a--]-'0';
        if(b>=0)sum=sum+q[b--]-'0';

        res.push_back(sum%2+'0');
        carry=sum/2;
    }   
    // cout<<a;

    reverse(res.begin(),res.end());
    cout<<res;



    return 0;
}