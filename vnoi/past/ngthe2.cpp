#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

struct BIT {
  int n;
  vector<int> d;
  BIT(int n = 0): n(n), d(n + 1) {}
  void add(int i, int x = 1) {
    for (i++; i <= n; i += i & -i) {
      d[i] += x;
    }
  }
  int sum(int i) {
    int x = 0;
    for (i++; i; i -= i & -i) {
      x += d[i];
    }
    return x;
  }
  int sum(int l, int r) {
    return sum(r - 1) - sum(l - 1);
  }
  void print() {
    for(int i = 0; i <= n; ++i)
      cout << d[i] << ' ';
    cout << '\n';
  }
};

void compress(vector<int> &a);

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in", "r", stdin);
  // freopen("ou", "w", stdout);

  int ans = 0;

  int n; cin >> n;
  vector<int> a(n);
  for(int &x: a) cin >> x;
  compress(a);

  BIT f(n);

  for(int i = n - 1; i >= 0; --i) {
    ans += f.sum(a[i] - 2);
    f.add(a[i] - 1, 1);
  }
  cout << ans;
}

void compress(vector<int> &a) {
  set<int> ss(a.begin(), a.end());
  vector<int> temp(ss.begin(), ss.end());
  for(int i = 0; i < (int) a.size(); ++i) {
    a[i] = (lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin()) + 1;
  }
}