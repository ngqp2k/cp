#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m; cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) cin >> a[i];
  sort(a.rbegin(), a.rend());
  pair<int, int> ans;
  ans.second = -1;
  for (int i = 0; i < n; ++i)
    if (a[i] * (i + 1) >= ans.second)
      ans = make_pair(a[i], a[i] * (i + 1));
  cout << ans.first << " " << ans.second;
}