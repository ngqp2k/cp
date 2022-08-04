#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
const int N = 1e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int n, T = 1;
vector<II> g[N];
int par[N], lvl[N], p[N][LOG], dis[N];

void init(){
	for(int i=0;i<N;++i)
		g[i].clear();
	memset(p, -1, sizeof(p));
}

void dfs(int u, int pre){
	for(auto p: g[u]){
		int v = p.fi;
		if (v == pre) continue;
		lvl[v] = lvl[u] + 1;
			par[v] = u;
		dis[v] = dis[u] + p.se;
		dfs(v, u);
	};
}

void calcST(){
	for(int i = 1; i <= n; ++i)
		p[i][0] = par[i];

	for(int j = 1; (1 << j) <= n; ++j)
		for(int i = 1; i <= n; ++i)
			if (p[i][j - 1] != -1)
				p[i][j] = p[p[i][j - 1]][j - 1];
}

int LCA(int u, int v){
	if (lvl[u] < lvl[v])
		swap(u, v);
	for(int j=LOG - 1; j >= 0; --j)
		if (lvl[p[u][j]] >= lvl[v])
			u = p[u][j];
	if (u == v)
		return u;
	for(int j = LOG - 1; j >= 0; --j)
		if (p[u][j] != p[v][j] && p[u][j] != -1) { u = p[u][j], v = p[v][j]; }
	return p[u][0];
}

int find(int u, int t) {
	int i, stp;
	for (stp = 1; 1 << stp <= lvl[u]; stp++); stp--;
	for (i = stp; i >= 0; i--)
		if (lvl[u] - (1 << i) >= t)
			u = p[u][i];
	return u;
}

void solve() {
	init();
	cin >> n;
	for(int i=1;i<n;++i){
		int u, v, val; cin >> u >> v >> val;
		g[u].pb(II(v,val));
		g[v].pb(II(u,val));
	}

	lvl[1] = 0, par[1] = 1, dis[1] = 0;
	dfs(1, -1);
	calcST();

	string chose;
	while(cin >> chose){
		if (chose == "DONE") {
			cout << "\n";
			return;
		}
		int u, v; cin >> u >> v;
		int R = LCA(u, v);
	  if (chose == "DIST"){
			cout << dis[u] + dis[v] - 2 * dis[R] << "\n";
		}
		else {
			int k; cin >> k;
			int ans;
			if (lvl[u] - lvl[R] + 1 >= k)
				ans = find(u, lvl[u] - k + 1);
			else
				ans = find(v, 2 * lvl[R] + k - lvl[u] - 1);
			cout << ans << "\n";
		}
	}
	
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}
