#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

void solve() {
  int N, M; cin >> N >> M;
  vector< vector<int> > dp(N, vector<int>((1 << N), 0));
  vector< vector<int> > adj(N, vector<int>(N));
  for (int i = 0; i < M; ++i) {
    int u, v; cin >> u >> v;
    u--, v--;
    adj[u][v] = adj[v][u] = 1;
  }
  for (int i = 0; i < N; ++i) { dp[i][1 << i] = 1; }

  for (int i = 0; i < (1 << N); ++i)
    for (int j = 0; j < N; ++j)
      if (i & (1 << j))
        for (int k = 0; k < N; ++k)
          if ((i & (1 << k)) != 0 & (adj[k][j]) && (k != j) && (dp[k][i ^ (1 << j)] == 1))
            dp[j][i] = 1;
          
  for (int i = 0; i < N; ++i)
    if (dp[i][(1 << N) - 1] == 1) {
      cout << "Yes\n";
      return;
    }
  cout << "No\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in", "r", stdin);
  // freopen("ou", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    solve();
  }
}