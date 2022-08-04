#include<bits/stdc++.h>
#define fi first
#define se second
// #define int long long
using namespace std;

const int mxN = 700 + 10; 
const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

typedef pair<int, int> II;

int H[mxN][mxN];
bool vis[mxN][mxN];
int n, m;

int ans = 0;

void BFS(int i, int j) {
	queue<II> Q;
	Q.push(II(i, j));
	bool ok = true;
	vis[i][j] = true;

	while (!Q.empty()) {
		int u = Q.front().fi;
		int v = Q.front().se;
		Q.pop();

		for(int ii = 0; ii < 8; ++ii) {
			int x = u + dx[ii];
			int y = v + dy[ii];
			if (x < 1 || x > n || y < 1 || y > m) continue;

			if (H[x][y] > H[i][j]) ok = false;

			if (!vis[x][y] && H[x][y] == H[i][j]) {
				Q.push(II(x, y)); vis[x][y] = true;
			}
		}
	}
	if (ok) {
   	   ans++;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> H[i][j];
	memset(vis, false, sizeof(vis));
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if (!vis[i][j])
				BFS(i, j);
	cout << ans;
	return 0;
}
