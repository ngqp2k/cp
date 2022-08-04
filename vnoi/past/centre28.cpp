#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define INF 1e9 + 7
#define MOD 1e9 + 7

using namespace std;

const int mxN = 30000;

typedef pair<int, int> II;
int n, m;
vector<II> g[mxN + 1];


void solve(){
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int u, v, val; cin >> u >> v >> val;
		g[u].pb(II(v, val));
		g[v].pb(II(u, val));
	}

	vector<bool> selected(n + 1, false);
	vector<int> d(n + 1, INF);
	vector<int> prev(n + 1, 0);
	priority_queue<II, vector<II>, greater<II>> q;

	d[1] = 0;
	q.push(II(d[1], 1));
	prev[1] = -1;
	
	vector<bool> chs(n + 1, false);
	vector<bool> res(n + 1, false);
	vector<int> cnt(n + 1, 0);

	while(!q.empty()){
		int u = q.top().se;
		q.pop();
		selected[u] = true;
		int ans = 0;

		if (u == n){
			chs[1] = true, chs[n] = true;
			//cnt[n] = 1;
			for(auto v: g[u]){
				if (d[v.fi] + v.se == d[u]){
					int i = v.fi;
					while(i != -1){
						cnt[i]++;
						res[i] = true;
						if (!chs[i])
							chs[i] = true;
						else
							break;
						i = prev[i];
						ans++;
					}
				}
			}
			for(int i=1;i<n;++i)
				if (cnt[i] > 1){
					if (i == 1){
						cout << n - 2 << "\n";
						for(int j=2;j<n;++j)
							cout << j << "\n";
					}
					cout << n - 2 - 1 << "\n";
					for(int j=2;j<n;++j)
						if (j != i)
							cout << j << "\n";
					return;
				}
			cout << n - ans - 2<< "\n";
			for(int i=2;i<n;++i)
				if (!res[i])
					cout << i << "\n";
			return;
		}

		for(auto v: g[u]){
			if (!selected[v.fi] && d[v.fi] > d[u] + v.se){
				d[v.fi] = d[u] + v.se;
				prev[v.fi] = u;
				q.push(II(d[v.fi], v.fi));
			}
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
