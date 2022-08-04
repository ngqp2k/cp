#include<bits/stdc++.h>

#define int long long
#define pb push_back

using namespace std;

const int N = 1e5 + 10;

vector<int> g[N], road, final;
int d[N], vis[N], parent[N];

int last, cnt;

int n, k;

void dfs(int u) {
	for (int v : g[u]) {
		d[v] = d[u] + 1;
		parent[v] = u;
		if (d[v] > d[last] && d[v] <= k)
			last = v;
		dfs(v);
	}
}

void dfs_2(int u) {
	final.pb(u);
	for (int v : g[u]) {
		if (vis[v] == 1) continue;
		cnt++;
		if (road.size() + cnt <= k) {
			dfs_2(v);
			final.pb(u);
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> k;

		for (int i = 1; i <= n; ++i) g[i].clear();
			for (int i = 1; i <= n; ++i) vis[i] = 0;
		road.clear();
		final.clear();

		for (int i = 2; i <= n; ++i) {
			int x; cin >> x;
			g[x].pb(i);
		}

		d[1] = 1, last = 1, parent[1] = 0;
		dfs(1);

		while (last != 0) {
			road.pb(last);
			vis[last] = 1;
			last = parent[last];
		}

		reverse(road.begin(), road.end());

		cnt = 0;
		for (int u : road)
			dfs_2(u);

		cout << final.size() - 1 << "\n";
		for (int i : final)
			cout << i << " ";
		cout << "\n";
	}
}