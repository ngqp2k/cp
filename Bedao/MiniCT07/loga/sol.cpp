#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << "-> " << #x << ": "; _print(x); cerr << "\n";
template<class T> void _print(T x) { cerr << x;}
template<class T> void _print(vector<T> v) {
    cerr << "[ ";
    for (T val: v) cerr << val << " ";
    cerr << "]";
}

vector<int> arrPri;

bool checkPN(int n) {
    if (n == 0 || n == 1)
        return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

pair<vector<int>, vector<int>> calc(int n) {
    pair<vector<int>, vector<int>> res;
    auto N = n;
    // 24 = 2 ^ 3 * 3
    map<int, int> mm;
    int i = 2;
    while (N > 1) {
        if (checkPN(N)) {
            mm[N]++;
            break;
        }
        if (N % i == 0) {
            N /= i;
            mm[i]++;
        }
        else
            i++;
    }
    for (auto p: mm) {
        // cout << p.first << " " << p.second << "\n";
        res.first.push_back(p.second);
        res.second.push_back(p.first);
    }
    // dbg("DONE");
    return res;
}

void solve() {
    int a, x;
    long long b;
    cin >> a >> b >> x;
    if (b < a) {
        cout << "-1\n";
        return;
    }
    long long tmp = a;
    int i;
    for (i = 1; tmp < b; ++i)
        tmp = tmp * a;
    // dbg(tmp);
    if (tmp != b) {
        cout << "-1\n";
        return;
    }
    // dbg(x); dbg(i);
    int res = x * i;
    // cout << res << "\n";
    auto ans = calc(res);
    for (int i = 0; i < (int) ans.first.size(); ++i)
        cout << ans.first[i] << " ";
    cout << "\n";
    for (int i = 0; i < (int) ans.second.size(); ++i)
        cout << ans.second[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    // auto res = calc(24);
    return 0;
}
