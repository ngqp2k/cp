#include<bits/stdc++.h>
using namespace std;
bool check(string st){
    return st[0]=='0';
}
bool checksum(string st,int x){
    int sum=0;
    for (int i=0;i<st.length();++i){
        int a=st[i]-'0';
        sum+=a;
    }
    return sum!=x;
}
bool cmp(string A,string B){
    if (A.length()<B.length()) return true;
    if (A.length()>B.length()) return false;
    for (int i=0;i<A.length();++i){
        if (A[i]>B[i]) return false;
        else if (A[i]<B[i]) return true;
    }
    return true;
}
void wrong(){
    puts("0.0");
    fputs("translate:wrong",stderr);
    exit(0);
}
int main(int argc,char** argv){
    ifstream inp(argv[1]);
    ifstream ans(argv[2]);
    ifstream c_ans(argv[3]);
    int n;
    inp>>n;
    vector<int> b(n+1);
    for (int i=1;i<=n;++i){
        inp>>b[i];
    }
    string a_n;
    for (int i=1;i<=n;++i){
        ans>>a_n;
    }
    vector<string> a(n+1);
    for (int i=1;i<=n;++i){
        c_ans>>a[i];
        if (check(a[i])){ //check so O o dau
            wrong();
        }
        if (checksum(a[i],b[i])){// check tong chu so
            wrong();
        }
    }
    if (!cmp(a[n],a_n)){//check gia tri thu N
        wrong();
    }
    for (int i=2;i<=n;++i){// check tang nghiem ngat
        if (cmp(a[i],a[i-1])){
            wrong();
        }
    }
    puts("1.0");
    fputs("translate:success",stderr);
    return 0;
}