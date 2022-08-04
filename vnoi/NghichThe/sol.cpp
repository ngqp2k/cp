#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define int long long
using namespace std;

const int mxN = 1e5 + 10;

struct BIT {
  int n;
  vector<int> f;
  BIT (int n): n(n), f(n + 1, 0) {}
  void set(int i) {
    for (; i >= 1; i -= i & (-i))
      f[i]++;
  }
  int get(int i) {
    int result = 0;
    for (; i <= n; i += i & (-i)) 
      result += f[i];
    return result;
  }
};

void compress(vector<int> &a) {
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    for (int &x: a) x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(auto &x: a) cin >> x;
  compress(a);
  BIT f(mxN);
  int res = 0;
  vector<int> t(mxN, 0);
  for(int i = 0; i < n; ++i) {
    // res += f.get(a[i] + 1);
    int tmp = f.get(a[i] + 1);
    f.set(a[i]);
    t[i + 1] = tmp;
  }
  // for(int i = 1; i <= n; ++i)
    // cout << t[i] << " ";
  while (q--) {
    int u, v; cin >> u >> v;
    cout << t[v] - t[v] << "\n";
  }
  return 0;
}