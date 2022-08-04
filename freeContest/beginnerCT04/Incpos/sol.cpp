#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q; cin >> n >> q;
  vector<int> a(n + 1), f(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    f[i] = a[i] - a[i + 1];
    if (f[i] > 0) ans++;
  }
  while (q--) {
    int l, r, x; cin >> l >> r >> x;
    //
    if (l > 1) {
      int tmp = f[l - 1];
      f[l - 1] -= x;
      if (tmp > 0 && f[l - 1] <= 0) {
        ans--;
      }
      else if (tmp <= 0 && f[l - 1] > 0)
        ans++;
    }
    if (r < n) {
      int tmp = f[r];
      f[r] += x;
      if (tmp > 0 && f[r] <= 0)
        ans--;
      else if (tmp <= 0 && f[r] > 0)
        ans++;
    }
    cout << ans << "\n";
  }
}