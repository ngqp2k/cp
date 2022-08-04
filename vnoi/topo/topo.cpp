#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int N = 1e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;


void File() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w",stdout);
}

int n, m;
vector<int> g[N + 1], deg, l;
vector<bool> visited;

void dfs(int u) {
    if (visited[u])
        return;
    visited[u] = true;
    for (int v: g[u]) 
        dfs(v);
    // l.pb(u);
	cout << u << "\n";
}

void solve() {
    cin >> n >> m;
    deg.resize(n + 1, 0);
	visited.resize(n + 1, false);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        deg[v]++;
    }
	for(int i = 1; i <= n; ++i)
		if (deg[i] == 0)
			dfs(i);
}

int main() {
    File();
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
