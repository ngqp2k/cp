#include <bits/stdc++.h>
#define infi 1e9 + 7
#define infll 1e18 + 7
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<long long> vl;
typedef vector<vector<long long>> vll;
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

  int n, m; cin >> n >> m;
  vii a(n, vi(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> a[i][j];
  vii dp(n, vi(m));
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; ++i)
    dp[i][0] = (a[i][0] == 0) ? 1 : 0;
  for (int i = 0; i < m; ++i)
    dp[0][i] = (a[0][i] == 0) ? 1 : 0;
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < m; ++j) {
      if (a[i][j] != 0)
        dp[i][j] = 0;
      else
        dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
      ans1 = max(ans1, dp[i][j]);
    }

  for (int i = 0; i < n; ++i)
    dp[i][0] = (a[i][0] == 1) ? 1 : 0;
  for (int i = 0; i < m; ++i)
    dp[0][i] = (a[0][i] == 1) ? 1 : 0;
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < m; ++j) {
      if (a[i][j] != 1)
        dp[i][j] = 0;
      else
        dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
      ans2 = max(ans2, dp[i][j]);
    }

  cout << max(ans1, ans2) << '\n';

  return 0;
}
