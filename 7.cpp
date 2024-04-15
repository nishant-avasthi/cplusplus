#include<bits/stdc++.h>
using namespace std;

auto palin(string ss){
    int i=0, s=ss.size()-1;

    while(i<s){
        if(ss[i]!=ss[s]){
            return "no";
            break;
        }
        i++;
        s--;
    }
     return "yes";
}

int main(){
     string s= "sadad?SADA",t="daddad",p="saddaS";
     cout<<palin(s)<<endl;
     cout<<palin(t)<<endl;
     cout<<palin(p)<<endl;

     return 0;
}