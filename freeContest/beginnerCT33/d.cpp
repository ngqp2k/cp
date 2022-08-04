#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m; cin >> n >> m;
  int f[2][1111];
  for (int i = 1; i <= n; ++i) {
    f[0][i] = 0, f[1][i] = 0;
    for (int j = 1; j <= m; ++j) {
      int x; cin >> x;
      if (x > 0)
        f[0][i] += x;
      else if (x < 0)
        f[1][i] += (-x);
    }
  }
  int ans = 0;
  if (n > 1){
  for (int i = 1; i < n; ++i)
    for (int j = i + 1; j <= n; ++j)
      ans = max(ans, max(f[0][i], f[1][i]) + max(f[0][j], f[1][j]));
  }
  else {
    ans = max(f[0][1], f[1][1]);    
  }
  cout << ans;
}