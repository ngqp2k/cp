#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << "-> " << #x << ": "; _print(x); cerr << "\n";
template<class T> void _print(T x) { cerr << x;}
template<class T> void _print(vector<T> v) {
    cerr << "[ ";
    for (T val: v) cerr << val << " ";
    cerr << "]";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l; cin >> l;
    string s; cin >> s;
    s = s + '#';

    auto split = [&] (char c) {
        vector<int> res;
        int n = (int) c;
        int i = 0;
        while ((1 << i) <= n) {
            res.push_back((n & (1 << i)) > 0);
            i++;
        }
        reverse(res.begin(), res.end());
        return res;
    };

    vector<vector<int>> a;
    int minn = (int) 1e9;

    vector<int> tmp;
    for (int i = 0; i <= l; ++i) {
        if (s[i] == '#') {
            a.push_back(tmp);
            minn = min(minn, (int) tmp.size());
            tmp.clear();
        }
        else {
            auto v = split(s[i]);
            tmp.insert(tmp.end(), v.begin(), v.end());
        }
    }

    double res;
    int cnt0 = 0, cnt1 = 0;

    for (int i = 0; i < (int) a.size(); ++i) {
        for (int j = 0; j < minn; ++j)
            if (a[i][j] == 1)
                cnt1++;
            else
                cnt0++;
    }
    res = cnt1 * 1.0 / cnt0;
    cout << a.size() << " " << minn << "\n";
    cout << setprecision(9) << fixed << res;
    return 0;
}
