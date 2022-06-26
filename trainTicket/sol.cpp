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

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    const int inf = 1e9 + 10;

    vector<int> l(4), c(4);
    cin >> l[1] >> l[2] >> l[3] >> c[1] >> c[2] >> c[3];
    int n, s, f; cin >> n >> s >> f;
    vector<int> d(n);
    for (int i = 1; i < n; ++i)
        cin >> d[i];

    vector<int> a(f - s + 1), dp(f - s + 1, inf);
    int id =  0;
    for (int i = s - 1; i < f; ++i)
        a[id++] = d[i];

    dp[0] = 0;
    for (int i = 1; i < a.size(); ++i) {
        for (int j = 1; j <= 3; ++j) {
            int pos = lower_bound(a.begin(), a.end(), a[i] - l[j]) - a.begin();
            dp[i] = min(dp[i], dp[pos] + c[j]);
        }
    }

    if (dp[dp.size() - 1] >= inf)
        cout << "-1\n";
    else
        cout << dp[dp.size() - 1] << "\n";

    // comment

    return 0;
}
