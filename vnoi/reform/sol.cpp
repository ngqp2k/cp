#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 2e5 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int n, m;
vector<int> g[N], scc[N];
int num[N], low[N], totalScc[N], root[N], f[N];

bool vis[N];

vector<II> bridges;

int timeDfs = 0, part = 0;

void dfs1(int u){
	if (vis[u]) return;
	vis[u] = true, root[u] = part;
	totalScc[part]++;
	for(int v: g[u])
		dfs1(v);
}

void dfs2(int u, int pre){
	low[u] = num[u] = ++timeDfs;
	for(int v: g[u]){
		if (v == pre)
			continue;
		if (num[v] == 0){
			dfs2(v, u);
			f[u] += f[v];
			if (low[v] > num[u]){
				// u - v is bridges
				bridges.pb(II(u, v));
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
	for(int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	memset(vis, false, sizeof vis);
	for(int i = 1; i <= n; ++i)
		if (!vis[i]){
			part++;
			dfs1(i);
		}


	if (part > 2)
		cout << 0;
	else
		for(int i = 1; i <= n; ++i) f[i] = 1;
		for(int i = 1; i <= n; ++i) 
			if (num[i] == 0)
				dfs2(i, i);

		if (part == 1){
			int ans = 0;
			for(auto t: bridges){
				ans += f[t.se] * (n - f[t.se]) - 1;
			}
			ans += (n * (n - 1) / 2 - m) * (m - bridges.size());
			cout << ans;
		}
		else if (part == 2){
			cout << (m - bridges.size()) * totalScc[1] * totalScc[2] << "\n";
		}
	return 0;
}
