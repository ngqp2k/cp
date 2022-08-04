#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 1e5;
int n, m, s, f;
vector< vector<int> > c;

void dfs(int start, int finish){
	stack<int> ss;
	vector<int> b(n + 1, false);
	vector<int> prev(n + 1);

	ss.push(start);
	prev[start] = -1;
	b[start] = true; // da duoc xet

	while(ss.empty() == false){
		int u = ss.top();
		ss.pop();
		for(int v: c[u])
			if (!b[v]){
				ss.push(v);
				b[v] = true;
				prev[v] = u;
			}
	}

	cout << "Path: " << finish;
	int i = prev[finish];
	while(i != -1){
		cout << " <- " << i;
		i = prev[i];
	}
}

void solve(){
	cin >> n >> m >> s >> f;
	c.resize(n + 1);
	for(int i=1;i<=m;++i){
		int u, v;
		cin >> u >> v;
		c[u].push_back(v);
		c[v].push_back(u);
	}

	dfs(s, f);

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

