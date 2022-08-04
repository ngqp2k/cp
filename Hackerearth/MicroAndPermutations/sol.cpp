#include <iostream>
#include <string.h>
using namespace std;

int N, M;
int adj[11][11], dp[11][1 << 11];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	memset(adj, 0, sizeof adj);
	memset(dp, 0, sizeof dp);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u][v] = 1; adj[v][u] = 1;
	}
	for (int i = 0; i < N; ++i) dp[i][1 << i] = 1;
	for (int i = 0; i < (1 << N); ++i)
		for (int j = 0; j < N; ++j)
			if (i & (1 << j))
				for (int k = 0; k < N; ++k)
					if ((i & (1 << k)) != 0 && (k != j) && (adj[k][j]) && (dp[k][i ^ (1 << j)] > 0)) {
						dp[j][i] += dp[k][i ^ (1 << j)];
						// break;
					}
	int ans = 0;
	for (int i = 0; i < N; ++i)
		if (dp[i][(1 << N) - 1] > 0)
			ans += dp[i][(1 << N) - 1];
	cout << ans;
}