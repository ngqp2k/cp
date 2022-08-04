#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define INF 1e9 + 7

using namespace std;

const int mxN = 1e4;

typedef pair<int, int> II;
int n, m;
vector<int> g[mxN + 10];
int num[mxN + 10], low[mxN + 10];
int cntBright = 0, timeDFS = 0;
bool joint[mxN + 10];


void dfs(int u, int pre){
	int child = 0; 
	num[u] = low[u] = ++timeDFS;
	for(int v: g[u]){
		if (v == pre)
			continue;
		if (!num[v]){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] == num[v])
				cntBright++;
			child++;
			if (u == pre){
				if (child > 1)
					joint[u] = true;
			}
			else{ 
				if (low[v] >= num[u])
					joint[u] = true;
			}
		}
		else
			low[u] = min(low[u], num[v]);
	}
}

void solve(){
	cin >> n >> m;
	memset(num, 0, sizeof(num));
	memset(joint, false, sizeof(joint));
	for(int i=1;i<=m;++i){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	for(int i=1;i<=n;++i)
		if (num[i] == 0)
			dfs(i, i); // i la goc mot nhanh
	
	int ans = 0;
	for(int i=1;i<=n;++i)
		if (joint[i])
			ans++;
	cout << ans << " " << cntBright;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
