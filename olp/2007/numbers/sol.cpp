#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
//#define fi first
//#define se second
//#define int long long
using namespace std;

const int N = 1e4 + 10;

int n, m, t;
vector<int> adj[N];
vector<int> g[N];
int num[N], low[N], root[N], nScc = 0, timeDfs = 0;

bool del[N];
stack<int> S;

void dfs(int u) {
  num[u] = low[u] = ++timeDfs;
  S.push(u);
  for (int v : adj[u]) {
    if (del[v]) continue;
    if (!num[v]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    }
    else
      low[u] = min(low[u], num[v]);
  }
  if (low[u] == num[u]) {
    nScc++;
    int v;
    do {
      v = S.top();
      S.pop();
      root[v] = nScc;
      del[v] = true;
    } while (v != u);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m >> t;
  for (int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }

  memset(del, false, sizeof(del));

  for (int i = 1; i <= n; ++i)
    if (!num[i])
      dfs(i);
  vector<int> deg(n + 1, 0);
  for (int i = 1; i <= n; ++i)
    for (int j : adj[i]) {
      int rootI = root[i];
      int rootJ = root[j];
      if (rootI != rootJ) {
        g[rootI].push_back(rootJ);
        deg[rootI]++;
      }
    }
  int cnt = 0;
  for (int i = 1; i <= nScc; ++i)
    if (deg[i] == 0 && i != root[t]) {
      cnt++;
    }
  cout << cnt;
  return 0;
}