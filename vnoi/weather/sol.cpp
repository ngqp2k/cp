#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
const int N = 2e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

vector< vector<int> > g;
vector<int> low, num, tail, depth;
vector<II> bridges;
int n, m;



void File() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// 	freopen("in2", "r", stdin);
// 	freopen("ou2", "w", stdout);
}

int timeDfs = 0;
vector<int> trace, f;

void dfs(int u, int pre) {
	num[u] = low[u] = ++timeDfs;
	for (int v : g[u]) {
		if (v == pre) continue;
		if (!num[v]) {
			depth[v] = depth[u] + 1;
			dfs(v, u);
			f[u] += f[v];
			if (low[v] > num[u]){
				bridges.pb(II(u, v));
			}
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
}

int main() {
	File();
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	low.resize(n + 1, 0);
	num.resize(n + 1, 0);
	depth.resize(n + 1, 0);
	trace.resize(n + 1, 0);
	f.resize(n + 1, 1);
	depth[1] = 1;
	for (int i = 1; i <= n; ++i)
		if (!num[i])
			dfs(i, i);
	int ans = 0;
	for(auto pp: bridges){
		int v = pp.se;
		ans += (f[v] * (n - f[v]));
	}
	cout << ans;
	return 0;
}