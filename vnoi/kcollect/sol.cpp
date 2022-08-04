#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
const int N = 110;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

vector<int> g[N * N], h[N * N];
vector<int> val, num, low, sumScc, a, root;
vector<int> deleted, visited;
vector< vector<char> > c;
int m, n;


void File() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //freopen("in2", "r", stdin);
  //freopen("ou2", "w", stdout);
}

int getId(int i, int j) {return (i - 1) * n + j;}

bool checkId(int i, int j) { return (1 <= i && i <= m && 1 <= j && j <= n && c[i][j] != '#'); }

int timeDfs = 0, scc = 0;
stack<int> ss;

void dfs(int u) {

  num[u] = low[u] = ++timeDfs;
  ss.push(u);
  for (int v : g[u]) {
    if (deleted[v]) continue;
    if (!num[v]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    }
    else
      low[u] = min(low[u], num[v]);
  }
  //cout << num[u];

  if (low[u] == num[u]) {
    scc++;
    int v;
    do {
      v = ss.top(); ss.pop();
      sumScc[scc] += a[v];
      root[v] = scc;
      deleted[v] = true;
    } while (v != u);
  }

}

int main() {
  File();
  cin >> m >> n;
  c.resize(m + 1, vector<char> (n + 1));
  a.resize(n * m + 1);
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
      cin >> c[i][j];
      int index = getId(i, j);
      a[index] = (0 <= c[i][j] - '0' && c[i][j] - '0' <= 9) ? c[i][j] - '0' : 0;
    }
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
      if (c[i][j] == '#') continue;
      int index = getId(i, j);
      if (checkId(i, j + 1)) g[index].pb(getId(i, j + 1));
      if (checkId(i + 1, j)) g[index].pb(getId(i + 1, j));

      if (c[i][j] == 'W' && checkId(i, j - 1)) g[index].pb(getId(i, j - 1));
      if (c[i][j] == 'N' && checkId(i - 1, j)) g[index].pb(getId(i - 1, j));
    }
  num.resize(m * n + 1, 0);
  low.resize(m * n + 1, 0);
  sumScc.resize(m * n + 1, 0);
  deleted.resize(m * n + 1, false);
  root.resize(m * n + 1, 0);
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j)
      if (c[i][j] != '#' && !num[getId(i, j)])
        dfs(getId(i, j));
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
      int u = getId(i, j);
      for (int v : g[u]) {
        if (root[v] != root[u])
          h[root[u]].pb(root[v]);
      }
    }
  //test();
  vector<int> f(n * m  + 1, 0);
  for (int i = 1; i <= scc; ++i) {
    f[i] = sumScc[i];
    for (int j : h[i])
      f[i] = max(f[i], f[j] + sumScc[i]);
  }
  cout << f[root[1]];
  return 0;
}
