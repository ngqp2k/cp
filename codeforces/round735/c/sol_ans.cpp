#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    ++m;
    int ans = 0;
    for (int k = 30; k >= 0 and n < m; k--) {
      cout << "k = " << k << "\n";
      cout << "(n >> k & 1) = " << (n >> k & 1) << "\n";
      cout << "(m >> k & 1) = " << (m >> k & 1) << "\n";
      if ((n >> k & 1) == (m >> k & 1)) continue;
      if (m >> k & 1) {
        ans |= 1 << k, n |= 1 << k;
        cout << "ans = " << ans << ", " << "n = " << n << "\n";
      }
    }
    cout << ans << '\n';
  }
  return 0;
}