#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair<int, int> II;

const int INF = (int) 1e9 + 7;
const int mxN = 1e5;

vector<II> g[mxN];
set<II> S;
int cl[mxN], kc[mxN];
int n, m, s, f;

void dijkstra(int s){
	memset(kc, 0, sizeof(kc));
	memset(cl, 0, sizeof(cl));
	cl[s] = 1;
	;
}

void solve(){
  cin >> n >> m >> s >> f;
	for(int i=0;i<m;++i){
		int u, v, val;
		cin >> u >> v >> val;
		g[u].push_back(make_pair(v, val));
		g[v].push_back(make_pair(u, val));
	}
	dijkstra(s);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
