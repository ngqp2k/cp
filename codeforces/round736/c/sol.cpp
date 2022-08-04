#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M; cin >> N >> M;
	vector<int> cntStronger(N + 1, 0);
	int cntKilled = 0;
	for (int i = 0; i < M; ++i) {
		int u, v; cin >> u >> v;
		cntStronger[min(u, v)]++;
		if (cntStronger[min(u, v)] == 1)
			cntKilled++;
	}
	int q; cin >> q;
	while (q--) {
		int c; cin >> c;
		if (c == 3)
			cout << N - cntKilled << "\n";
		else {
			int u, v; cin >> u >> v;
			if (c == 1) {
				cntStronger[min(u, v)]++;
				if (cntStronger[min(u, v)] == 1)
					cntKilled++;
			}
			else {
				cntStronger[min(u, v)]--;
				if (cntStronger[min(u, v)] == 0)
					cntKilled--;
			}
		}
	}
	return 0;
}
