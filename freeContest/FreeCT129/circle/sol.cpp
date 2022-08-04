#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
// #define int long long
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define MOD 1000000007
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
  return a.se < b.se;
}

void sortMap(map<int, int> &a) {
  vector< pair<int, int> > v;
  for(auto &i: a)
    v.pb(i);
  sort(all(v), cmp);
  map<int, int> ans;
  for(auto i: v) {
    ans[i.fi] = i.se;
    cout << i.fi << " " << i.se << "\n";
  }
  a = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  map<int, int> a;
  vector<pair<int, int>> b(n);
  rep(i, n) {
    int u, v; cin >> u >> v;
    a[u] = v;
    b[i].fi = u, b[i].se = v;
  }
  sortMap(a);
  for(auto i: a)
    cout << i.fi << " " << i.se << "\n";
}