#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n);
  for(int &i: a) cin >> i;
  int ans = 0, mem = 0;
  for(int i = 0; i < n; ++i) {
    ans += (a[i] + mem) / 2;
    mem = (a[i] + mem) % 2;
  }
  cout << ans;
}