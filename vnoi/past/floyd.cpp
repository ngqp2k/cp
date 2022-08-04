#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 1e5;
int n, m, k;
int g[101][101];
int arr[4];

void init(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if (i == j)
				g[i][j] = 0;
		  else
				g[i][j] = INF;
}

void floyd(){
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			  for(int j=1;j<=n;++j)
					if (i != j)
					  g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	int res = INF;
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			if (j != i)
			  for(int k=0;k<4;++k)
					if (k != j && k != i)
				    for(int l=0;l<4;++l)
					    if (l != k && l != j && l != i){
								//cout << i << j << k << l << "\n";
								for(int u=1;u<=n;++u)
									for(int v=1;v<=n;++v)
									{
										res = min(res, g[arr[i]][u] + g[arr[j]][u] + g[u][v] + g[arr[k]][v] + g[arr[l]][v]);
									}
							}
	cout << res;
}

void solve(){
	cin >> n;
	for(int i=0;i<4;++i)
		cin >> arr[i];
	init();
	int u, v, c;
	while(cin >> u >> v >> c){
		g[u][v] = c;
		g[v][u] = c;
	}
	floyd();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
