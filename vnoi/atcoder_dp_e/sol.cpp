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
    
    int n, m; cin >> n >> m;
    vector<int> w(n), v(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
        sum += v[i];
    }
    const int inf = 1e9 + 7;
    vector<int> dp(sum + 1, inf);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = sum - v[i]; j >= 0; --j)
            dp[j + v[i]] = min(dp[j + v[i]], dp[j] + w[i]);
    int ans = 0;
    for (int i = 0; i <= sum; ++i)
        if (dp[i] <= m)
            ans = max(ans, i);
    cout << ans << '\n';

    return 0;
}
