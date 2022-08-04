#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define MOD 1000000007
#define INF 100000000000000007
#define int long long
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef map<int, int> mi;

const int mxN = 22;

int n;
int a[mxN];
pii dp[1 << mxN];

pii solve(int mask) {
  if (mask == (1 << n) - 1)
    return {0, 0};
  if (dp[mask] != pii(-1, -1))
    return dp[mask];
  pii ans = {INF, -INF};
  rep(i, n) {
    if (!(mask & (1 << i))) {
      int m = mask | (1 << i);
      for (int j = i + 1; j < n; ++j)
        if (!(m & (1 << j))) {
          auto t = solve(m | (1 << j));
          ans.fi = min(ans.fi, (a[i] ^ a[j]) + t.fi);
          ans.se = max(ans.se, (a[i] ^ a[j]) + t.se);
        }
      break;
    }
  }
  return dp[mask] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, (1 << n)) dp[i].fi = dp[i].se = -1;
  auto ans = solve(0);
  cout << ans.fi << " " << ans.se << "\n";
}