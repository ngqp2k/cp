#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 2000 + 10; 

vector<int> adj[N], g[N], scc[N];
int n, m;

int num[N], low[N], nComp = 0, timeDfs = 0, root[N];
bool del[N];

stack<int> S;

void dfs(int u) {
	num[u] = low[u] = ++timeDfs;
	S.push(u);

	for(int v: adj[u]) {
		if (del[v]) continue;
		if (!num[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
	if (low[u] == num[u]) {
		nComp++;
		int v;
		do {
			v = S.top(); S.pop();
			scc[nComp].push_back(v);
			del[v] = true;
			root[v] = nComp;
		} while (v != u);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	memset(del, false, sizeof(del));
	for(int i = 1; i <= n; ++i)
		if (!num[i])
			dfs(i);
	// init new graph
	vector<int> degIn(nComp + 1, 0), degOut(nComp + 1, 0);
	for(int i = 1; i <= n; ++i)
		for(int j: adj[i]) {
			if (root[i] != root[j]) {
				g[root[i]].push_back(root[j]);
				degIn[root[j]]++;
				degOut[root[i]]++;
			}
		}
	if (count(degIn.begin() + 1, degIn.end(), 0) > 1) {
		cout << "NO";
	}
	else {
		int u, v;
		for(int i = 1; i <= nComp; ++i) {
			if (degIn[i] == 0) u = i;
			if (degOut[i] == 0) v = i;
		}
		cout << "YES\n";
		cout << scc[v][0] << " " << scc[u][0];
	}
	return 0;
}
