#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int i = 0;
    string res;
    bool ok = true;
    for(i; i < n; ++i) {
        if (s[i] == '3') {
            ok = false;
            res = s.substr(0, i);
            break;
        }
    }
    if (ok) {
        sort(s.begin(), s.end());
        cout << s << "\n";
    }
    sort(res.begin(), res.end());
    string tmp="";
    for (i = i; i < n; ++i) {
        if (s[i] == '2')
            res += '2';
        else
            tmp += s[i];
    }

    cout << res + tmp << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    // freopen("input.inp", "r",stdin);
    int tt = 1; cin >> tt;
    while (tt--) {
        solve();
    }
}

