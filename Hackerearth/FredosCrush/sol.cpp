#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

void solve() {
  int n, m; cin >> n >> m;
  // cout << "- " << n << " " << m << "\n";
  vector<vector<int>> adj(n, vector<int>(n, 0));
  vector<vector<int>> dp(n, vector<int>((1 << n), 0));
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    u--, v--;
    adj[u][v] = adj[v][u] = 1;
  }
  vector<int> sum(n), ans(n);
  for (int i = 0; i < n; ++i) {
    dp[i][1 << i] = 1;
    sum[i] = i + 1, ans[i] = 0;
  }
  for (int mark = 0; mark < (1 << n); ++mark) {
    int cnt = 0, s = 0, tmp = mark;
    while (tmp) {
      s += log2(tmp & -tmp) + 1;
      tmp &= tmp - 1;
      cnt++;
    }
    for (int i = 0; i < n; ++i) {
      if (mark & (1 << i)) {
        for(int j = 0; j < n; ++j)
          if (j != i && (mark & (1 << j)) && adj[j][i] && dp[j][mark ^ (1 << i)]) {
            dp[i][mark] = 1;
            ans[i] = max(ans[i], cnt - 1);
            if (ans[i] == cnt - 1)
              sum[i] = max(sum[i], s);
            break;
          }
      }
    }
  }
  int mx = sum[0], mn = sum[0];
  for (int i = 1; i < n; ++i) {
    mx = max(mx, sum[i]);
    mn = min(mn, sum[i]);
  }
  int tmp = mx * mn / gcd(mx, mn);
  cout << tmp / mn << " " << tmp / mx << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    solve();
  }
}