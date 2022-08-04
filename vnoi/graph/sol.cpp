#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 10000 + 10; 

int n, m;
int num[N], low[N];
vector<int> adj[N];
bool ifCut[N];

int cntBridges = 0, cntCut = 0;

int child = 0, timeDfs = 0;

void DFS(int u, int pre) {
	num[u] = low[u] = ++timeDfs;

	for(int v: adj[u]) {
		if (v == pre) continue;
		if (!num[v]) {
			if (u == pre) child++;
			DFS(v, u);

			if (low[v] >= num[u]) {
				ifCut[u] = true;
			}

			if (low[v] > num[u])
				cntBridges++;

			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(ifCut, false, sizeof ifCut);

	for(int i = 1; i <= n; ++i)
		if (!num[i]) {
			child = 0;
			DFS(i, i);
			ifCut[i] = child > 1;
		}

	for(int i = 1; i <= n; ++i) if (ifCut[i])
		cntCut++;

	cout << cntCut << " " << cntBridges;

	return 0;
}

