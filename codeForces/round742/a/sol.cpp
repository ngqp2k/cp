#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == 'L' || s[i] == 'R')
            cout << s[i];
        else if (s[i] == 'U') cout << 'D';
        else if (s[i] == 'D') cout << 'U';
    }
    cout << "\n";
    ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) solve();
}
