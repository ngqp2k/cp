#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define INF 1e9 + 7
#define MOD 1e9 + 7

using namespace std;

const int mxN = 1e2;
const int mxM = 1e4;

typedef pair<int, int> II;

int n, m;
int g[mxN + 1][mxN + 1];
int a[mxM + 1];

void solve(){
	cin >> n >> m;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			g[i][j] = i == j ? 0 : INF;

	for(int i=1;i<=m;++i)
		cin >> a[i];

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin >> g[i][j];

	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

	ll res = 0;

  int index = 1;
	for(int i=1;i<=m;++i){
		res += g[index][a[i]];
		index = a[i];
	}
	cout << res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
