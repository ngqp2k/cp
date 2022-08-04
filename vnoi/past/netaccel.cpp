#include<bits/stdc++.h>
#define fi first
#define se second
//#define INF 1e12
#define MOD 1e9 + 7

using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 1000;

typedef pair<int, int> II;
typedef pair<int , double> ID;
vector<ID> g[mxN + 1];
int n, m, k;

void calc(){
	vector< vector<bool> > chs(n + 1, vector<bool> (k + 1, true));
	vector< vector<double> > d(n + 1, vector<double> (k + 1, INF));
	priority_queue< pair<double, II> , vector< pair<double, II> >, greater< pair<double, II> > > q;

	for(int i=0;i<=k;++i)
		d[1][i] = 0.0;
	q.push(make_pair(d[1][0], II(1, 0)));

  while(!q.empty()){
		int u = q.top().se.fi;
		int cntD = q.top().se.se;
		q.pop();
		if (!chs[u][cntD])
			continue;
		if (u == n && cntD == k){
			cout << d[n][cntD];
			return;
		}
		chs[u][cntD] = false;

		for(int i=0;i<(int)g[u].size();++i){
			int v = g[u][i].fi; 
			double tmp = g[u][i].se * 2; 
			for(int j=cntD;j<=k;++j){
				tmp = tmp * 1.0 / 2;
				if (chs[v][j] && d[v][j] > d[u][cntD] + tmp){
				  d[v][j] = d[u][cntD] + tmp;
					q.push(make_pair(d[v][j], II(v, j)));
				}
			}
		}
	}	
}

void solve(){
  cin >> n >> m >> k;
	for(int i=1;i<=m;++i){
		int u, v, val; cin >> u >> v >> val;
		g[v].push_back(II(u, val));
		g[u].push_back(II(v, val));
	}
	calc();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout << setprecision(2) << fixed;
	solve();
	return 0;
}
