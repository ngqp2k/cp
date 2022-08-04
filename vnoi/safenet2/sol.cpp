#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 30010;
vector<int> g[N];
int n, m, num[N], low[N];

stack<pair<int, int>> ss;

int timeDfs = 0, ans = 0;

void dfs(int u, int pre){
	num[u] = low[u] = ++timeDfs;
	for(int v: g[u]){
		if (v == pre)
			continue;
		if (num[v] == 0){
			ss.push(make_pair(u, v));
			dfs(v, u);
			if (low[v] >= num[u]){
				int cnt = 0;
				while(ss.top() != make_pair(u, v)){
					cnt++;
					ss.pop();
				}
				ss.pop();
				ans = max(ans, cnt + 2);
			}
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	while(m--){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i)
		if (num[i] == 0)
			dfs(i, i);
	cout << max(ans, 1);
}