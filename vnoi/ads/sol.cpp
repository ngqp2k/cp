#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 2000 + 10; 

vector<int> adj[N];

int n, m;
int num[N], low[N];

int timeDfs = 0, cnt = 0;

void DFS(int u, int pre){
	num[u] = ++timeDfs;

	for(int v: adj[u]) {
		if (v == pre) continue;
		if (!num[v]) {
			DFS(v, u);
		}
		else{
			cnt++;
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n >> m;
	while(m--){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i)
		if (!num[i])
			DFS(i, i);

	cout << cnt / 2;
	return 0;
}

