#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 1e5;
int n, m;
vector< vector<int> > c;
vector<bool> selected;
int cnt = 0;

void bfs(int start){
	queue<int> q;
	q.push(start);

	selected[start] = true;

	while(q.empty() == false){
		int u = q.front();
		q.pop();
		for(int v: c[u])
			if (!selected[v]){
			  q.push(v);
				selected[v] = true;
			}
	}
}

void solve(){
	cin >> n >> m;
	c.resize(n + 1);
	selected.resize(n + 1, false);
	for(int i=1;i<=m;++i){
		int u, v;
		cin >> u >> v;
		c[u].push_back(v);
		c[v].push_back(u);
	}

	for(int i=1;i<=n;++i)
		if (selected[i] == false){
			bfs(i);
			cnt++;
		}
	cout << m - n + cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
