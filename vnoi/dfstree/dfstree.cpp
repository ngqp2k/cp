#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define INF 1e9 + 7

using namespace std;

const int mxN = 1e5;

typedef pair<int, int> II;
int n, m;
vector<int> g[mxN];
int num[mxN + 1];
int low[mxN + 1];
int tail[mxN + 1];
int timeDFS = 0;

void buildDFS(int u, int prev) {
	num[u] = low[u] = ++timeDFS;
	for (int v : g[u]) {
		if (v == prev)
			continue;
		if (!num[v]) {
			buildDFS(v, u);
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
	// thoi diem duyen xong dinh u
	tail[u] = timeDFS;
}

void print();

void solve() {
	cin >> n >> m;
	memset(num, 0, sizeof(num));
	for (int i = i; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	buildDFS(1, 1);
	// print
	print();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
void print() {
	// for(int i=1;i<=n;++i){
	//   cout << i << ": ";
	//   for(int j: f[i])
	//     cout << j << ", ";
	//   cout << "\n";
	// }
	// num
	cout << "num[]: ";
	for (int i = 1; i <= n; ++i)
		cout << num[i] << " ";
	cout << "\n";
	// tail
	cout << "tail[]: ";
	for (int i = 1; i <= n; ++i)
		cout << tail[i] << " ";
	cout << "\n";
	// low
	cout << "low[]: ";
	for (int i = 1; i <= n; ++i)
		cout << low[i] << " ";
	cout << "\n";

}
