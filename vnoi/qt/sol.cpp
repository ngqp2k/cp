#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
// #define int long long
// #define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1e3 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int g[N][N], f[N][N];
int n, m, p, q, s, t;

int dx[4] = { 1, 1, -1 ,-1 };
int dy[4] = { 1, -1, 1 ,-1 };

queue<II> Q;


int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	// FO(1);
	cin >> n >> m >> p >> q >> s >> t;

	if(p == s && q == t){
		cout << 0;
		return 0;
	}

	for(int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		g[u][v] = -1;
	}

	for(int i = 0; i <= n + 1; ++i) {
		g[0][i] = -1;
		g[n + 1][i] = -1;
		g[i][0] = -1;
		g[i][n + 1] = -1;
	}

	// BFS
	memset(f, 0x3f, sizeof f);
	f[s][t] = 0;
	// g[s][t] = -1;
	Q.push(II(s, t));

	while (!Q.empty()) {
		int u = Q.front().fi;
		int v = Q.front().se;
		Q.pop();

		for (int i = 0; i < 4; ++i)
			if (g[u + dx[i]][v + dy[i]] != -1) {
				int x = u, y = v;
				while (g[x + dx[i]][y + dy[i]] != -1) {
					x += dx[i], y += dy[i];
					// f[x][y] = f[u][v] + 1;
					if (f[x][y] > f[u][v] + 1) {
						f[x][y] = f[u][v] + 1;
						Q.push(II(x, y));
					}
				}
			}
	}

	// for(int i = 0; i <= n + 1; ++i) {
	//     for(int j = 0; j <= n + 1; ++j)
	//         if (f[i][j] > INF)
	//             cout << '*' << " ";
	//         else
	//             cout << f[i][j] << " ";
	//     cout << "\n";
	// }
	
	cout << (f[p][q] > INF ? -1 : f[p][q]);



	return 0;
}
