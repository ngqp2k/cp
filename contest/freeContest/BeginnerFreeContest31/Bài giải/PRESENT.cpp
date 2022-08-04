#include<bits/stdc++.h>

using namespace std;
int main(){
    int Test;
    cin>>Test;
    while (Test--){
        int n,m;
        cin>>m>>n;
        if (m==1) cout<<1<<"\n";
        else cout<<2*(n/3)+(n%3==0 ? 0 :1)<<"\n";
    }
}