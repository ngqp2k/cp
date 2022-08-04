#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int adj[11][11];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	memset(adj, 0, sizeof adj);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		adj[u][v] = adj[v][u] = 1;
	}

	vector<int> v;
	for (int i = 1; i <= n; ++i) v.push_back(i);

	int ans = 0;
	while (true) {
		bool ok = true;
		for (int i = 1; i < n; ++i) if (adj[v[i - 1]][v[i]] == 0) { 
			ok = false; break;
		}
		if (ok) ans++;
		if (!next_permutation(v.begin(), v.end()))
			break;
	}
	cout << ans;
}