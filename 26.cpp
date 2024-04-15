#include<bits/stdc++.h>
using namespace std;

void printfunn(vector<int> a){

    for(int i=0;i<a.size();++i)
    cout<<a[i]<<" ";


}

void multiply(vector<int> a){
    int temp=1;
    for(int i=0;i<=a.size();++i){
        
        temp=a[i];

    }
    for(int i=a.size()-1;i>=0;i--){
        a[i]=temp*a[i];
        temp=a[i];

    }
    printfunn(a);

}


int main(){
    // vector<int> v = {22,2,32,23,2,23};
    vector<int> p = {1,2,4,2,0,5};

    // multiply(v);
    multiply(p);

    return 0;
}