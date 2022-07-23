#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int mxn = 30000 + 11;
    int n; cin >> n;
    vector<pair<int, int>> a(n + 1);
    vector<vector<int>> p(mxn);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        p[a[i].second].push_back(i);
    }

    vector<int> dp(mxn);
    dp[0] = 0;
    for (int i = 1; i <= 30000; ++i) {
        dp[i] = dp[i - 1];
        for (int j: p[i]) {
            dp[i] = max(dp[i], dp[i - a[j].second + a[j].first] + a[j].second - a[j].first);
        }
    }
    cout << dp[30000] << '\n';

    return 0;
}