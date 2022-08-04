#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define INF 1e9 + 7
#define MOD 1e9 + 7

using namespace std;

const int mxN = 1e5;

typedef pair<int, int> II;
vector<int> g[mxN + 1];
vector<int> f[mxN + 1];
int n, m;


void buildDFSTree(int start){
	stack<int> s;
	vector<int> selected(n + 1, false);
	
	s.push(start);
	selected[start] = true;

	while(!s.empty()){
		int u = s.top();
		s.pop();
		if (selected[u])
			continue;
		for(auto v: g[u]){
			if (!selected[v]){
				f[u].pb(v);
				selected[v] = true;
				s.push(v);
			}
		}
	}

	for(int i=1;i<=n;++i){
		cout << i << ": ";
		for(int j: g[i])
			cout << j << ", "; 
		cout << "\n";
	}
}


void solve(){
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int u, v; cin >> u >> v;
		g[u].pb(v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
