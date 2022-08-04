#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 110;
const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

char g[mxN][mxN];
bool vis[mxN][mxN];
int depth[mxN][mxN];


int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  typedef pair<int, int> II;
  II st, en;

  int R, C; cin >> R >> C;
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      cin >> g[i][j];
      if (g[i][j] == 'B') st = II(i, j);
      if (g[i][j] == 'C') en = II(i, j);
    }
  }

  memset(vis, false, sizeof(vis));

  
  queue<II> Q;
  Q.push(st);
  vis[st.fi][st.se] = true;
  depth[st.fi][st.se] = 0;
  while (!Q.empty()) {
    int u = Q.front().fi;
    int v = Q.front().se;
    Q.pop();

    if (u == en.fi && v == en.se) {
      cout << depth[u][v];
      return 0;
    }

    for(int i = 0; i < 4; ++i) {
      int x = u + dx[i];
      int y = v + dy[i];
      if (x < 1 || x > R || y < 1 || y > C) continue;
      if (g[x][y] == '*') continue;
      if (vis[x][y] == true) continue;
      vis[x][y] = true;
      Q.push(II(x, y));
      depth[x][y] = depth[u][v] + 1;
    }
  }

}