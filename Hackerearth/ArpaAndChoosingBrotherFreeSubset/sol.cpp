#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int mxN = 1e5 + 11, mxK = 111;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k; cin >> n >> k;
  vector<int> cnt(n + 10, 0);
  cnt[0] = 1;
  for (int i = 0; i < n - 1; ++i) {
    int x; cin >> x;
    cnt[x]++;
  }

  vector<int> a;
  a.push_back(0);
  for (int i : cnt) if (i) a.push_back(i);

  n = a.size();

  vector< vector<int> > dp(n + 1, vector<int>(k + 1, 0));

  dp[0][0] = 1;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j <= k; ++j) {
      if (j <= i) {
        dp[i][j] = ((long long)a[i] * dp[i - 1][j - 1] % MOD) % MOD + dp[i - 1][j] % MOD;
      }
    }
  }

  cout << dp[n - 1][k] % MOD;
}