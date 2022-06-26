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

// Problem: Bo tri phong hop

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    dbg(a);

    sort(a.begin(), a.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
            });
    dbg(a);

    int ans = 0;

    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i] = a[i].second - a[i].first;
        for (int j = 0; j < i; ++j) {
            if (a[j].second <= a[i].first) {
                dp[i] = max(dp[i], dp[j] + a[i].second - a[i].first);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

    

    return 0;
}
