#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int MOD = 2111992;
const int mxN = 1e5 + 10;

int dp[mxN], f[mxN];

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in", "r", stdin);
  // freopen("ou", "w", stdout);
  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; ++i) {
    int j = max(i - k - 1, (int)0);
    dp[i] = f[j] + 1;
    f[i] = (f[i - 1] + dp[i]) % MOD;
  }
  cout << f[n] + 1;
}