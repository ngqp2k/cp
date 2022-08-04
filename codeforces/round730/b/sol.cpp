#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    sum += x;
  }
  if (sum % n == 0) {
    cout << 0 << "\n";
    return;
  }
  int m = sum % n;
  long long ans = (long long) m * (n - m);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    solve();
  }
}