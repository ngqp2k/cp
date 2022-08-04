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
int low[mxN], num[mxN];
vector<int> joi;
vector<II> bri;
int timeD= 0;

void dfs(int u, int pre){
	int child = 0; // so luong nhanh trong cay goc u
	num[u] = low[u] = ++timeD;
	for(int v: g[u]){
		if (v == pre) continue;
		if (num[v] == 0){
			child++;
			dfs(v, u);
			// tinh xong low[v]
			// da co num[u], num[v], low[v];
			low[u] = min(low[u], low[v]);
			if (low[v] == num[v]){
				bri.pb(II(u, v));
			}
			if (u == pre)
				if (child > 1)
					joi.pb(u);
				else;
			else
			  if (low[v] >= num[u])
				  joi.pb(u);
		}
		else{
			low[u] = min(low[u], num[v]);
		}
	}

}

void print();

void solve(){
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	memset(num, 0, sizeof(num));
	for(int i=1;i<=n;++i)
		if (num[i] == 0)
			dfs(i, i);
	print();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
void print(){
	cout << "Brigde:\n";
	for(auto p: bri)
		cout << p.fi << " " << p.se << "\n";

	cout << "Joint:\n";
	for(int v: joi)
		cout << v << "\n";
}
