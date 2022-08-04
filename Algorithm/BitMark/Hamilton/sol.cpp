#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	vector< vector<int> > adj;
	int N, M; cin >> N >> M;
	adj.resize(N, vector<int>(N, 0));
	for (int i = 0; i < M; ++i) {
		int u, v; cin >> u >> v;
		adj[u][v] = adj[v][u] = 1;
	}
	vector< vector<int> > dp(N, vector<int>(1 << N, 0));

	// init
	for (int i = 0; i < N; ++i) { dp[i][1 << i] = 1; }

	for (int i = 0; i < (1 << N); ++i) {
		for (int j = 0; j < N; ++j)
			if (i & (1 << j)) {
				for (int k = 0; k < N; ++k)
					if (i & (1 << k) && (k != j) && (adj[k][j] == 1) && dp[k][i ^ (1 << j)] == true) {
						dp[j][i] = true;
					}
			}
	}
	for (int i = 0; i < N; ++i)
		if (dp[i][(1 << N) - 1]) {
			cout << "YES\n";
			return 0;
		}
	cout << "NO\n";
	return 0;
}
