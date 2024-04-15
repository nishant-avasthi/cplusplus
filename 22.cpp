#include<bits/stdc++.h>
using namespace std;


 class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stak;

        for(string & a: tokens){
            if(a=="/"||a=="*"||a=="+"||a=="-"){
                int aa=stak.top();
                stak.pop();
                int bb=stak.top();
                stak.pop();
                int temp;
                if(a=="/")temp=bb/aa;
                if(a=="*")temp=bb*aa;
                if(a=="+")temp=bb+aa;
                if(a=="-")temp=bb-aa;

                stak.push(temp);
            }
            else{
                stak.push(stoi(a));
            }
        }

        return stak.top();
        
    }
};

int main(){
    vector<string> tokens = {"2","133","+","3","*"};
    Solution su;
     cout<<su.evalRPN(tokens)<<endl;

     return 0;
}