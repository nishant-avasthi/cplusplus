 #include<bits/stdc++.h>
 using namespace std;
 int main(){
    string s="saad sd";
    string t ="sd saad";
    
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    if(s==t)cout<<"true";
    else cout<<"false"
;

return 0;}