#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 20020;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

vector<int> g[N];
int num[N], low[N], f[N], scc[N], totalScc[N], parent[N];
bool vis[N], joint[N];
int n, m;
int part = 0, timeDfs = 0, cntNode, res = 0;

void dfs1(int u) {
	if (vis[u]) return;
	vis[u] = true, scc[u] = part, cntNode++;
	for (int v : g[u])
		dfs1(v);
}

void dfs2(int u, int pre) {
	num[u] = low[u] = ++timeDfs;
	int child = 0;
	for (int v : g[u]) {
		if (v == pre) continue;
		if (num[v] == 0) {
			child++;
			parent[v] = u;
			dfs2(v, u);
			f[u] += f[v];
			if (u == pre) {
				if (child > 1)
					joint[u] = true;
			}
			else if (low[v] >= num[u]) {
				joint[u] = true;
			}
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// FO(1);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	for (int i = 1; i <= n; ++i)
		if (!vis[i]) {
			part++, cntNode = 0;
			dfs1(i);
			totalScc[part] = cntNode;
		}

	for (int i = 1; i <= n; ++i) f[i] = 1;
	for (int i = 1; i <= n; ++i)
		if (num[i] == 0) {
			parent[i] = i;
			dfs2(i, i);
		}

	for (int i = 1; i <= n; ++i)
		if (joint[i]) {
			vector<int> c;
			int sum = 0;
			for (int j : g[i]) {
				if (low[j] >= num[i] && parent[j] == i) {
					c.pb(f[j]);
					sum += f[j];
				}
			}
			c.pb(totalScc[scc[i]] - sum - 1);
			for (int i = 0; i < c.size() - 1; ++i)
				for (int j = i + 1; j < c.size(); ++j){
					res += c[i] * c[j];
				}
		}

	double ans = double(res) / n * 1.0;
	cout << ans;
	return 0;
}
