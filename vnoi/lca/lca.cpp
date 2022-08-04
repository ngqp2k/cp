// LCA
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define TASK "lca"

using namespace std;
const int N = 1100;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;

void File()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(TASK".INP", "r", stdin);
	freopen(TASK".OUT", "w", stdout);
}

int n;
vector<int> g[N];
int depth[N], p[N][LOG + 1], t[N], H = 0;;

void init() {
	for (int i = 1; i < N; ++i)
		g[i].clear();
	memset(depth, 0, sizeof(depth));
	memset(p, 0, sizeof(p));
	memset(t, 0, sizeof(t));
	H = 0;
}

void dfs(int u) {
	for (int v : g[u]) {
		depth[v] = depth[u] + 1;
		H = max(H, depth[v]);
		t[v] = u;
		dfs(v);
	}
}

void initPT() {
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			p[i][j] = -1;
	for (int i = 1; i <= n; ++i)
		p[i][0] = t[i];
	for (int j = 1; (1 << j) <= H; ++j)
		for (int i = 1; i <= n; ++i)
			p[i][j] = p[p[i][j - 1]][j - 1];
}


int lca(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	// get same depth
	int k = depth[u] - depth[v];
	for (int j = LOG; j >= 0; --j) {
		if ((1 << j) <= k && depth[p[u][j]] >= depth[v])
			u = p[u][j];
	}
	if (u == v)
		return u;
	// depth[u] = depth[v]
	for (int j = LOG; j >= 0; --j) {
		if (p[u][j] != p[v][j] && p[u][j] != -1 && p[v][j] != -1) {
			u = p[u][j];
			v = p[v][j];
		}
	}
	return p[u][0];
}

void print();

void solve() {
	init();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int m; cin >> m;
		for (int j = 0; j < m; ++j) {
			int x; cin >> x;
			g[i + 1].pb(x);
		}
	}
	depth[1] = 0, t[1] = 1;
	dfs(1);
	initPT();
	// print();
	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		cout << lca(u, v) << "\n";
	}
}
int main()
{
	File();
	int T = 1, cnt = 1;
	cin >> T;
	while (T--) {
		cout << "Case " << cnt++ << ":\n";
		solve();
	}
	return 0;
}