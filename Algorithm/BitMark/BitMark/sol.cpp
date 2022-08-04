#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int INF = 1e9;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector< vector<int> > adj(n, vector<int>(n));
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cin >> adj[i][j];
  vector<int> dp((1 << n), INF);
  dp[0] = 0;
  for(int mark = 0; mark < (1 << n); ++mark) {
    int cntBit = 0, tmp = mark;
    while (tmp) {
      cntBit++; tmp &= tmp - 1;
    }
    for(int j = 0; j < n; ++j) {
      if (mark & (1 << j) == 0) {
        dp[mark | (1 << j)] = min(dp[mark | (1 << j)], dp[mark] + adj[cntBit][j]);
      }
    }
  }
  cout << dp[(1 << n) - 1];
}