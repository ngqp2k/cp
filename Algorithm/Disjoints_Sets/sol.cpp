#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 7;

typedef pair<int, int> II;

int par[N];

int n;

int root(int v) {
	return par[v] < 0
		? v
		: (par[v] = root(par[v]));
}

void merge(int x, int y) {
	if ((x = root(x)) == (y = root(y))) return;
	if (par[y] < par[x])
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	cin >> n;
	n = 10;
	for(int i = 1; i <= n; ++i)
		par[i] = -1;
	int Q; cin >> Q;
	while(Q--){
		int chose; cin >> chose;
		if (chose == 1) {
			int u, v; cin >> u >> v;
			merge(u, v); // hop u va u
		}
		else {
			int r; cin >> r;
			cout << root(r) << "\n";
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << i << ": " << par[i] << "\n";
	return 0;
}
