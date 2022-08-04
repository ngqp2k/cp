#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 1e5;
int n, m, k;
int f[101][101];
bool sel[101];
int d[101];

void init(){
	for(int i=1;i<=n;++i){
		d[i] = INF;
		sel[i] = false;
	}
}

void dijkstra(int code, int start, int finish){
	init();
	d[start] = 0;
	vector<int> prev(n + 1, 0);

	while(1){
		int u = 0, dMin = INF;
		for(int i=1;i<=n;++i){ // tim dinh u chua xet co d[u] nho nhat
			if (!sel[i] && d[i] < dMin){
				u = i;
				dMin = d[i];
			}
		}

		if (u == finish){
			if (code == 0)
				cout << d[finish] << "\n";
			else{
				int cnt = 0;
				int i = finish;
				vector<int> res;
				while(i != 0){
					cnt++;
					res.push_back(i);
					i = prev[i];
				}
				cout << cnt << " ";
				for(int i=res.size() - 1;i>=0;i--)
					cout << res[i] << " ";
				cout << "\n";
			}
			return;
		}

		sel[u] = true; // dinh u da duoc xet
		for(int i=1;i<=n;++i)
			if (f[u][i] != INF && !sel[i] && d[u] + f[u][i] < d[i]){
				d[i] = d[u] + f[u][i];
				prev[i] = u;
			}
	}
}

void solve(){
	cin >> n >> m >> k;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if (i == j)
				f[i][j] = 0;
			else
				f[i][j] = INF;
	
	for(int i=1;i<=m;++i){
		int u, v, c;
		cin >> u >> v >> c;
		f[u][v] = c;
		f[v][u] = c;
	}

	for(int i=1;i<=k;++i){
		int code, u, v;
		cin >> code >> u >> v;
		dijkstra(code, u, v);
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	;
	return 0;
}
