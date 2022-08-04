#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int mxN = 222;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input.inp", "r", stdin);
  //freopen("output.out", "w", stdout);
  int row, col, xStart, yStart, xFinish, yFinish;
  int a[mxN][mxN];
  cin >> row >> col >> xStart >> yStart >> xFinish >> yFinish;
  for (int i = 1; i <= row; ++i)
    for (int j = 1; j <= col; ++j)
      cin >> a[i][j];

  const int dx[] = { -1, 0, 0, 1 };
  const int dy[] = { 0, 1, -1, 0 };

  typedef pair<int, int> II;
  typedef pair<int, II> III;
  priority_queue<III, vector<III>, greater<III>> Q;
  Q.push(III(0, II(xStart, yStart)));

  int d[mxN][mxN];
  memset(d, 0x3f, sizeof d);
  d[xStart][yStart] = 0;

  while (!Q.empty()) {
    int u = Q.top().se.fi;
    int v = Q.top().se.se;
    Q.pop();
    // cout << d[u][v] << " " << u << " " << v << "\n";
    if (u == xFinish && v == yFinish) {
      cout << d[u][v];
      return 0;
    }
    for (int i = 0; i < 4; ++i) {
      int x = u + dx[i];
      int y = v + dy[i];
      if (x < 1 || x > row || y < 1 || y > col) continue;
      int cost = max(a[x][y] - a[u][v], 0);
      if (d[u][v] + cost < d[x][y]) {
        d[x][y] = d[u][v] + cost;
        Q.push(III(d[x][y], II(x, y)));
      }
    }
  }
}