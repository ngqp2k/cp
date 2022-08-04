#include<bits/stdc++.h>
#define fi first
#define se second
#define push_back
using namespace std;

const int N = 100 + 10; 
const int INF = 200 + 10; 
const int dx[] = { -1, 0, 0, 1};
const int dy[] = { 0, -1, 1, 0};

typedef pair<int, int> II;

int n;
int a[N][N];
int hmax = 0, hmin = INF, ans = 0;

bool BFS(int len) {
	for(int L = 0; L <= hmax - len; ++L) {
		int R = L + len;
		if (a[1][1] < L || a[1][1] > R) continue;
		vector< vector<bool> > vis(n + 1, vector<bool> (n + 1, false));
		queue<II> Q;
		Q.push(II(1, 1));

		vis[1][1] = true;

		while (!Q.empty()) {
			int u = Q.front().fi;
			int v = Q.front().se;
			Q.pop();
			if (u == n && v == n) return true;
			for (int ii = 0; ii < 4; ++ii) {
				int x = u + dx[ii];
				int y = v + dy[ii];

				if (x < 1 || x > n || y < 1 || y > n) continue;
				if (a[x][y] < L || a[x][y] > R) continue;

				if (!vis[x][y]) {
					Q.push(II(x, y));
					vis[x][y] = true;
				}
			}
		}
	}
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			hmax = max(hmax, a[i][j]);
			hmin = min(hmin, a[i][j]);
		}
	int left = 0, right = hmax - hmin;
	while(left <= right) {
		int mid = (left + right) / 2; 
		if (BFS(mid)) {
			ans = mid, right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans;
	return 0;
}
