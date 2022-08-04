#include<bits/stdc++.h>
#define fi first
#define se second
// #define int long long
using namespace std;

const int N = 1e5 + 10; 

int n, m;
vector<int> adj[N];
int num[N], low[N], cnt = 0;
bool del[N];

stack<int> S;

int timeDfs = 0;

void DFS(int u){
	num[u] = low[u] = ++timeDfs;
	S.push(u);

	for(int v: adj[u]) {
		if (del[v]) continue;

		if (num[v])
			low[u] = min(low[u], num[v]);
		else {
			DFS(v);
			low[u] = min(low[u], low[v]);
		}
	}

	if (low[u] == num[u]) {
		cnt++;
		while(S.top() != u) {
			S.pop();
			del[S.top()] = true;
		}
		del[S.top()] = true;
		S.pop();
	}

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n >> m;

	while(m--){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	memset(del, false, sizeof(del));

	for(int i = 1; i <= n; ++i)
		if (!num[i])
			DFS(i);

	cout << cnt;

	return 0;
}

