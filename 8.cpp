#include<bits/stdc++.h>
using namespace std;

int main(){

    int r=3,c=3;
    

    int ar[8][8]={0};
    int col=1;
    // int i=7,j=7;

    for(int i=7;i>r;i--){
        for(int j=7;j>c;j--){
            ar[i][j]=col;
        }
    }

    for(int a = 0; a < 8; a++)
  {
    for(int b = 0; b < 8; b++)
    {
      cout << ar[a][b] << " ";
    }
    cout << endl;
  }  


    return 0;
}