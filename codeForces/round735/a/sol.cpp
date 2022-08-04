#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> a(N + 2, 0);
    int ans = 1;
    for(int i = 1; i <= N; ++i) {
      cin >> a[i];
      if (i > 1) {
        ans = max(ans, a[i] * a[i -1]);
      }
    }
    cout << ans << "\n";
  }
}