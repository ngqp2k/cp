#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int INF = (int) 1e9 + 7;
typedef pair<int, int> II;

int n, m, s, f;
vector< vector<II> > c;

class cmp {
public:
	bool operator() (II a, II b) {
		return a.se > b.se;
	}
};

void dijkstra(int start, int finish) {
	vector<int> d(n + 1, INF), prev(n + 1);
	priority_queue<II, vector<II>, cmp > Q;

	d[start] = 0;
	Q.push(II(start, d[start]));
	prev[start] = -1;

	while (!Q.empty()) {
		int u = Q.top().fi;
		Q.pop();
		if (u == finish) {
			cout << d[finish] << "\n";
			vector<int> path;
			int i = finish;
			while (i != -1) {
				path.push_back(i);
				i = prev[i];
			}
			reverse(path.begin(), path.end());
			for (int i : path)
				if (i != finish)
					cout << i << " --> ";
				else
					cout << i;
			return;
		}
		for (auto v : c[u]) {
			if (d[u] + v.se < d[v.fi]) {
				d[v.fi] = d[u] + v.se;
				prev[v.fi] = u;
				Q.push(II(v.fi, d[v.fi]));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	//freopen("in", "r", stdin);
	//freopen("ou", "w", stdout);
	cin >> n >> m >> s >> f;
	c.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		int u, v, val; cin >> u >> v >> val;
		c[u].push_back(II(v, val)), c[v].push_back(II(u, val));
	}
	dijkstra(s, f);
}
