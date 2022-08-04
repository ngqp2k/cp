#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  map<int, vector<int>> d;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (d[x].size() < k)
      d[x].pb(i);
  }
  int total = 0;
  for (auto p : d)
    total += p.se.size();
  total -= total % k;
  vector<int> ans(n, 0);
  int color = 0;
  for (auto p : d) {
    for (int v : p.se) {
      ans[v] = ++color;
      color %= k;
      total--;
      if (total == 0) {
        for (int i = 0; i < n; ++i)
          cout << ans[i] << " ";
        cout << "\n";
        return;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("in", "r", stdin);
  freopen("ou", "w", stdout);
  int T; cin >> T;
  while (T--) {
    solve();
  }
}