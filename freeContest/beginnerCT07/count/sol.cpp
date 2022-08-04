#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define MOD 1000000007
#define INF 1000000007
#define int long long

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef map<int, int> mi;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1; 
  // cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vi a(n), f(n);
    rep(i, n) {
      cin >> a[i];
      if (i == 0)
        f[i] = a[i];
      else
        f[i] = f[i - 1] + a[i];
    }
    if (f[n - 1] % 3 != 0) {
      cout << 0 << "\n";
      continue;
    }
    int step = f[n - 1] / 3;
    vi cnt(n, 0);
    rep(i, n) {
      if (i == 0)
        cnt[i] = (f[i] == step * 2);
      else
        cnt[i] = cnt[i - 1] + (f[i] == step * 2);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
      if (f[i] == step)
        ans += cnt[n - 2] - cnt[i];
    cout << ans;
  }
}       