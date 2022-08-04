#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a;
    int N = n;
    while (N > 0) {
        a.push_back(N % 10);
        N /= 10;
    }
    n = a.size();
    sort(a.begin(), a.end());
    vector<int> v1, v2;
    bool ok = false;
    int id = 0;
    while (id < n){
        ok = !ok;
        if (ok)
            v1.push_back(a[id++]);
        else
            v2.push_back(a[id++]);
    }
    int s1 = 0, s2 = 0;
    for(int i = 0; i < v1.size(); ++i)
        s1 = s1 * 10 + v1[i];
    for(int i = 0; i < v2.size(); ++i)
        s2 = s2 * 10 + v2[i];
    cout << s1 + s2 << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt = 1; cin >> tt;
    while (tt--) {
        solve();
    }
}
