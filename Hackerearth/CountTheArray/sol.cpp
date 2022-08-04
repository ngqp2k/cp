#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int mxN = 1e6 + 11;

bool b[mxN];
int dp[30][mxN], ans[mxN];

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int p, q, n;
  cin >> p;

  memset(b, false, sizeof(b));
  for(int i = 2; i * i <= p; ++i)
    if (!b[i]) {
      for(int j = i + i; j <= p; j += i)
        b[j] = true;
    }

  vector<int> primes;
  for(int i = 2; i <= p; ++i)
    if (!b[i]) primes.push_back(i);

  memset(dp, 0, sizeof(dp));
  for(int v: primes) {
    dp[1][v] = 1;
    if (v * v <= p)
      dp[2][v * v] = 1;
  }

  for (int i = 1; i <= 22; ++i) {
    ans[i] = 0;
    for(int j = 1; j <= p; ++j) {
      ans[i] += dp[i][j];
      for(int v: primes) {
        if (v * v * j > p)
          break;
        dp[i + 2][v * v * j] += dp[i][j];
      }
    }
  }
  for(int i = 1; i <= 22; ++i)
    cout << ans[i] << " ";
}