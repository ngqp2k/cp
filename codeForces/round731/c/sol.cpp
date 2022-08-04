#include <bits/stdc++.h>
using namespace std;

void solve() {
  int k, n, m; cin >> k >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < m; ++i)
    cin >> b[i];

  vector<int> ans(n + m);
  int ia = 0, ib = 0, id = 0;
  while (ia < n && ib < m) {
    if (a[ia] < b[ib])
      ans[id++] = a[ia++];
    else
      ans[id++] = b[ib++];
  }
  for (int i = ia; i < n; ++i)
    ans[id++] = a[i];
  for (int i = ib; i < m; ++i)
    ans[id++] = b[i];
  
  // check
  for (int i: ans) {
    if (i == 0)
      k++;
    else if (i > k) {
      cout << -1 << "\n";
      return;
    }
  }

  for (int i: ans)
    cout << i << " ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    solve();
  }
}
