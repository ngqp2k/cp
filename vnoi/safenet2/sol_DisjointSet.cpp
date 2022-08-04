#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 30000 + 25;

int n, m;
vector<int> adj[N];
int active[N], root[N];
bool vis[N];
stack<int> S;

int find(int u) {
	return (root[u] == u)
		? u
		: (root[u] = find(root[u]));
}

void dfs(int u) {
	 vis[u] = true, root[u] = u;
	 S.push(u);

	 for(int v: adj[u]) {
		 if (!vis[v]) {
			 active[u] = v;
			 dfs(v);
		 }
		 else {
			 v = find(active[v]); // tim tap chua active[v]
			 while (S.top() != v) {
				  root[find(S.top())] = v; // tap chua S.pop = v
				  S.pop();
			 }
		 }
	 }
	 if (S.top() == u)
		 S.pop();
}

int main() { 
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		 int u, v; cin >> u >> v;
		 adj[u].pb(v);
		 adj[v].pb(u);
	}

	memset(vis, false, sizeof(vis));
	for(int i = 1; i <= n; ++i)
		if (!vis[i])
			dfs(i);

	for(int i = 1; i <= n; ++i)
		cout << i << ": " << root[i] << "\n";

	return 0;
}
