#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 5000;

typedef pair<int, long long> II;

vector<II> g[mxN + 1];
int n, m;

class cmp{
	public:
		bool operator()(II a, II b){
			return a.se > b.se;
		}
};

void dijkstra(){
	vector<long long> d(n + 1, INF);
	vector<long long> cnt(n + 1, 0);
	vector<bool> selected(n + 1, false);
	priority_queue<II, vector<II>, cmp> q;
	d[1] = 0, cnt[1] = 1;
	q.push(make_pair(1, d[1]));
	while(!q.empty()){
		int u = q.top().fi;
		q.pop();
		selected[u] = true;

		for(auto v: g[u])
			if (!selected[v.fi])
				if (d[u] + v.se < d[v.fi]){
				  d[v.fi] = d[u] + v.se;
					cnt[v.fi] = cnt[u];
					q.push(make_pair(v.fi, d[v.fi]));
				}
				else if (d[u] + v.se == d[v.fi]){
				  cnt[v.fi] += cnt[u];	
				}
				else
					;
			else;
		}
	cout << d[n] << " " << cnt[n];
}


void solve(){
	cin >> n >> m;
	for(int i=0;i<m;++i){
		int k, u, v, val;
		cin >> k >> u >> v >> val;
		if (k == 1){
			g[u].push_back(make_pair(v, val));
		}
		else if (k == 2){
			g[u].push_back(make_pair(v, val));
			g[v].push_back(make_pair(u, val));
		}
	}
	dijkstra();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
