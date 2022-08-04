#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 1e5 + 10; 
int par[N];

int root(int v) {
	return (par[v] < 0) ? v : (par[v] = root(par[v]));
}

void merge(int u, int v) {
	u = root(u);
	v = root(v);
	if (u == v) return;

	if (par[u] < par[v])
		swap(u, v);

	par[u] += par[v];
	par[v] = u;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	for(int i = 1; i <= 10000; ++i) par[i] = -1;
	int Q; cin >> Q;
	while(Q--){
		int X, Y, Z; cin >> X >> Y >> Z;
		if (Z == 1)
			merge(X, Y);
		else {
			if (root(X) == root(Y));
			cout << (root(X) == root(Y)) ? "1" : "0";
			cout << "\n";
		}
	}
	return 0;
}

