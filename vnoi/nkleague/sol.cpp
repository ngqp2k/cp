#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mk make_pair

using namespace std;

const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;

const int N = 1007;
const int LOG = 20;

typedef pair<int, int> II;
vector<int> g[N + 1];
vector<int> visited, check, tt;
int n;

void dfs(int u){
	if (visited[u]) return;
	visited[u] = true;
	for(int v: g[u]) {
		dfs(v);
	}
	tt.pb(u);
}

void solve() {
	char ch;
	cin >> n;
	visited.resize(n + 1, false);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			cin >> ch;
			int x = ch - '0';
			if (x == 1)
				g[i].pb(j);
		}
	for(int i = 1; i <= n; ++i)
		if (!visited[i])
			dfs(i);
	for(int i = tt.size() - 1; i >= 0; --i){
		cout << tt[i] << " ";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
