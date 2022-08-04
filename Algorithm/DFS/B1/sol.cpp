#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const int mxN = 1e4 + 10;

int n, m;
vector<int> adj[mxN];
int low[mxN], num[mxN];
bool isCut[mxN];
int cntCut = 0, cntBridge = 0, timeDfs = 0;
int root, child;

void dfs(int u, int pre) {
	low[u] = num[u] = ++timeDfs;
	for (int v: adj[u]) {
		if (v == pre) continue;
		if (!num[v]) {
			if (u == root)
				child++;
			dfs(v, u);
			if (low[v] >= num[u]) isCut[u] = true;
			if (low[v] > num[u]) cntBridge++;
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(isCut, false, sizeof isCut);

	for (int i = 0; i < n; ++i)
		if (!num[i]) {
			root = i, child = 0;
			dfs(i, i);
			isCut[i] = (child > 1);
		}
	for (int i = 0; i < n; ++i)
		if (isCut[i])
			cntCut++;

	printf("%d %d", cntCut, cntBridge);
	return 0;
}
