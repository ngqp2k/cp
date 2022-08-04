#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
const int N = 100;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

vector<int> g[N + 1];
vector<int> num, low, par;
vector<bool> joint;
int n;

void File() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("in1", "r", stdin);
	// freopen("ou1", "w", stdout);
}

void reset() {
	for (int i = 1; i <= N; ++i)
		g[i].clear();
}

int timeDfs = 0, child = 0;
void dfs(int u, int pre) {
	num[u] = low[u] = ++timeDfs;
	for (int v : g[u]) {
		if (v == pre) continue;
		if (num[v] == 0) {
			if (u == pre) child++;
			par[v] = u;
			dfs(v, u);
			if (low[v] >= num[u]) {
				joint[u] = true;
			}
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
}

void solve() {
	reset();
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int x; cin >> x;
			if (x == 1)
				g[i].pb(j);
		}
	num.resize(n + 1); fill(num.begin(), num.end(), 0);
	low.resize(n + 1); fill(low.begin(), low.end(), 0);
	par.resize(n + 1); fill(par.begin(), par.end(), 0);
	joint.resize(n + 1); fill(joint.begin(), joint.end(), false);
	timeDfs = 0;
	for (int i = 1; i <= n; ++i) {
		if (num[i] == 0) {
			child = 0; par[i] = i;
			dfs(i, i);
			joint[i] = child > 1;
		}
	}
	II ans(0, 0);
	for (int i = 1; i <= n; ++i)
		if (joint[i]){
			int tmp = 0;
			for(int j: g[i])
				if (par[j] == i){
					tmp++;
				}
			if (tmp > ans.se)
				ans = II(i, tmp);
		}
	cout << ans.fi << "\n";
}

int main() {
	File();
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
