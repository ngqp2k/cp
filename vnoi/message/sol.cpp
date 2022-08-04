#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 888;

vector<int> adj[mxN];
int low[mxN], num[mxN], root[mxN];
bool del[mxN];
int timeDfs = 0, scc = 0;

stack<int> S;

void DFS(int u) {
  num[u] = low[u] = ++timeDfs;
  S.push(u);

  for (int v : adj[u]) {
    if (del[v]) continue;
    if (num[v])
      low[u] = min(low[u], num[v]);
    else {
      DFS(v);
      low[u] = min(low[u], low[v]);
    }
  }

  if (low[u] == num[u]) {
    scc++;
    int v;
    do {
      v = S.top(); S.pop();
      del[v] = true;
      root[v] = scc;
    } while (v != u);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("in", "r", stdin);
  freopen("ou", "w", stdout);
  int N, M; cin >> N >> M;
  for (int i = 1; i <= M; ++i) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
  }
  memset(del, false, sizeof del);
  for (int i = 1; i <= N; ++i)
    if (!num[i])
      DFS(i);

  vector<int> deg(scc + 1, 0);
  bool tt[mxN][mxN];
  memset(tt, false, sizeof tt);
  for (int i = 1; i <= N; ++i) {
    for(int j: adj[i]) {
      int x = root[i];
      int y = root[j];
      if (x != y && !tt[x][y]) {
        tt[x][y] = true;
        deg[y]++;
      }
    }
  }
  int cnt = 0;
  for (int i = 1 ; i <= scc; ++i)
    if (deg[i] == 0) {
      cnt++;
    }
  cout << cnt;
}