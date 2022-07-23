#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

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

    string s; cin >> s;
    int n = s.length();
    vii dp(n, vi(n));
    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;
    for (int step = 1; step < n; ++step) {
        for (int i = 0; i < n - step; ++i) {
            int j = i + step;
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    vector<char> ans(dp[0][n - 1]);
    int i1 = 0, i2 = dp[0][n - 1] - 1;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (i == j) {
            ans[i1] = s[i];
            break;
        }
        if (s[i] == s[j]) {
            ans[i1++] = ans[i2--] = s[i];
            i++, j--;
        }
        else {
            if (dp[i + 1][j] > dp[i][j - 1])
                i++;
            else
                j--;
        }
    }

    for (auto ch: ans)
        cout << ch;
    
    return 0;
}
