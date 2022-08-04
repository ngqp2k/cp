#include <iostream>
using namespace std;

#define int64 long long

const int64 md = 1e9 + 7;
string s;

int main(){
    cin >> s;
    int64 res = 1;
    int64 cnt = 1;
    for (int i = 1; i < s.size(); i++){
        if (s[i] != s[i - 1]){
            res = (res * cnt) % md;
            cnt = 1;
        }else cnt++;
    }
    cout << (res * cnt) % md;
    return 0;
}
