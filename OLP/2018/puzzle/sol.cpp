#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << "-> " << #x << ": "; _print(x); cerr << "\n";
template<class T> void _print(T x) { cerr << x;}
template<class T> void _print(vector<T> v) {
    cerr << "[ ";
    for (T val: v) cerr << val << " ";
    cerr << "]";
}

typedef pair<int, int> ii;

//ifstream fi("puzzle.inp");
//ofstream fo("puzzle.out");

vector<ii> check2(ii a, ii b) {
    vector<int> v1 = { a.first, a.second };
    vector<int> v2 = { b.first, b.second };
    int total = accumulate(v1.begin(), v1.end(), 0) + accumulate(v2.begin(), v2.end(), 0);
    vector<ii> res;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            if (v1[i] == v2[j])
                res.push_back(make_pair(v1[i], total - v1[i] * 2));
    return res;
}

vector<ii> check3(ii a, ii b, ii c) {
    vector<ii> res, res1, res2, res3;
    vector<ii> v1 = check2(b, c); // a & (b, c)
    for (int i = 0; i < (int)v1.size(); ++i) {
        auto tmp = check2(a, v1[i]);
        res.insert(res.end(), tmp.begin(), tmp.end());
    }
    vector<ii> v2 = check2(a, c); // b & (a, c)
    for (int i = 0; i < (int)v2.size(); ++i) {
        auto tmp = check2(b, v2[i]);
        res.insert(res.end(), tmp.begin(), tmp.end());
    }
    vector<ii> v3 = check2(a, b); // c & (a, b)
    for (int i = 0; i < (int)v3.size(); ++i) {
        auto tmp = check2(c, v3[i]);
        res.insert(res.end(), tmp.begin(), tmp.end());
    }
    return res;
}

void solve() {
    vector<ii> a(4);
    for (int i = 0; i < 4; ++i)
        cin >> a[i].first >> a[i].second;
    for (int mask = 1; mask < (1 << 4) - 1; ++ mask) {
        vector<ii> v1, v2;
        for (int i = 0; i < 4; ++i) {
            if (mask & (1 << i)) {
                v1.push_back(a[i]);
            }
            else {
                v2.push_back(a[i]);
            }
        }
        if (v1.size() == 1) {
            vector<ii> tmp = check3(v2[0], v2[1], v2[2]);
            for (int i = 0; i < (int)tmp.size(); ++i)
                if (check2(v1[0], tmp[i]).size() != 0) {
                    dbg(mask);
                    cout << "YES\n";
                    return;
                }
        }
        else if (v1.size() == 2) {
            vector<ii> tmp1 = check2(v1[0], v1[1]);
            vector<ii> tmp2 = check2(v2[0], v2[1]);
            for (int i = 0; i < (int)tmp1.size(); ++i)
                for (int j = 0; j < (int)tmp2.size(); ++j)
                    if (check2(tmp1[i], tmp2[j]).size()) {
                        dbg(mask);
                        cout << "YES\n";
                        return;
                    }

        }
        else if (v1.size() == 3) {
            vector<ii> tmp = check3(v1[0], v1[1], v1[2]);
            for (int i = 0; i < (int)tmp.size(); ++i)
                if (check2(v2[0], tmp[i]).size()) {
                    dbg(mask);
                    cout << "YES\n";
                    return;
                }
        }
    }
    //dbg(1 << 4);
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.inp", "r", stdin);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
