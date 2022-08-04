#include<bits/stdc++.h>
using namespace std;

const int N = 30010;

typedef pair<int, int> II;

vector<int> g[N];
int num[N], low[N], parent[N];
stack<II> ss;
set<int> res[N];

int timeDfs = 0, cnt = 0;

void dfs(int u) {
	int child = 0;
	num[u] = low[u] = ++timeDfs;
	for (int v : g[u]) {
		if (num[v] == -1) {
			child++;
			parent[v] = u;
			ss.push(II(u, v));
			dfs(v);
			low[u] = min(low[u], low[v]);
			// neu u la khop
			if ((num[u] == 1 && child > 1) || (num[u] > 1 && low[v] >= num[u])) {
				while (ss.top().first != u || ss.top().second != v) {
					// cout << ss.top().first << "--" << ss.top().second << " ";
					res[cnt].insert(ss.top().first);
					res[cnt].insert(ss.top().second);
					ss.pop();
				}
				// cout << ss.top().first << "--" << ss.top().second << "\n";
				res[cnt].insert(ss.top().first);
				res[cnt].insert(ss.top().second);
				ss.pop();
				cnt++;
			}
		}
		else if (v != parent[u]) {
			low[u] = min(low[u], num[v]);
			if (num[u] > num[v])
				ss.push(II(u, v));
		}

	}
}

void init(int n) {
	for (int i = 1; i <= n; ++i)
		num[i] = -1;
	for (int i = 1; i <= n; ++i)
		low[i] = -1;
}

int main() {
	// freopen("in1", "r", stdin);
	int n, m; cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	init(n);
	for (int i = 1; i <= n; ++i)
		if (num[i] == -1) {
			dfs(i);
			bool ok = false;
			while (ss.size() > 0) {
				ok = true;
				// cout << ss.top().first << "--" << ss.top().second << " ";
				res[cnt].insert(ss.top().first);
				res[cnt].insert(ss.top().second);
				ss.pop();
			}
			if (ok) {
				cnt++;
				// cout << "\n";
			}
		}
	int ans = 1;
	for(int i=0;i<cnt;++i){
		// cout << res[i].size() << "\n";
		ans = max(ans, (int)res[i].size());
	}
	cout << ans;
	return 0;
}
