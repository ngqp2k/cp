#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define TASK "QTREEV"

using namespace std;
const int N = 1e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

void File() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen(TASK".INP", "r", stdin);
  // freopen(TASK".OUT", "w", stdout);
}

int n, trace[N];
ll M;
ll a[N];
double f[N];
vector<int> g[N];

ll tinh(ll x, ll y) {
  if (y == 1) return x;
  ll tmp = tinh(x, y >> 1);
  tmp = (tmp + tmp) % M;
  if (y % 2)
    tmp = (tmp + x) % M;
  return tmp;
}

void dfs(int u, int pre) {
  double tmp = 0;
  bool ok = true;
  for (int v : g[u]) {
    if (v == pre) continue;
    ok = false;
    dfs(v, u);
    if (f[v] > tmp) {
      tmp = p[v];
      trace[u] = v;
    }
  }
  if (ok)
    f[u] = log10(a[u]);
  else
    f[u] = log10(a[u]) + tmp;
}

void solve() {
  cin >> n >> M;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(trace, 0, sizeof(trace));
  dfs(1, -1);
  int s[N], cnt = 0;
  int k = 1;
  while (k != 0) {
    s[++cnt] = k;
    k = trace[k];
  }
  ll res = 1;
  for (int i = cnt; i >= 1; --i)
    res = tinh(a[s[i]], res);
  cout << res;
}

int main() {
  File();
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
