#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define INF 1e9 + 7
#define MOD 1e9 + 7

using namespace std;

const int mxN = 10;
const int mxM = 2222;

typedef pair<int, int> II;
int n, m;
vector<II> g[mxM * mxN + 10];

void print(){
	for(int i=1;i<=n*m;++i){
		cout << i << ": ";
		for(auto v: g[i]){
			cout << v.fi << " " << v.se << ", ";
		}
		cout << "\n";
	}
}

void solve(){
		cin >> m >> n;
		int s = n * m + 1; // start

		for(int i=1;i<=n;++i){ // chu thich se in nghieng
			int x; cin >> x;
			g[s].pb(II(i, x));
			g[i].pb(II(s, x));
		}
		for(int i=1;i<n;++i){
			int x; cin >> x;
			g[i].pb(II(i + 1, x));
			g[i + 1].pb(II(i, x));
		}

		int cnt = n;

		for(int i=2;i<=m;++i){
			for(int j=1;j<=n;++j){
			  int x; cin >> x;
				g[cnt + j].pb(II(cnt + j - n, x));
				g[cnt + j - n].pb(II(cnt + j, x));
			}

		  for(int j=1;j<n;++j){
				int x; cin >> x;
				g[cnt + j].pb(II(cnt + j + 1, x));
				g[cnt + j + 1].pb(II(cnt + j, x));
			}
			cnt += n;
		}
		// dijkstra
		vector<bool> selected(n * m + 10, false);
		vector<int> d(n * m + 10, INF);
		priority_queue<II, vector<II>, greater<II>> q;
		d[n * m + 1] = 0;
		q.push(II(0, n * m + 1));
		while(!q.empty()){
			int u = q.top().se;
			q.pop();
			selected[u] = true;
			if (u == (n * m)){
				cout << d[u];
				return;
			}
			for(auto v: g[u])
				if (!selected[v.fi] && d[v.fi] > d[u] + v.se){
				  d[v.fi] = d[u] + v.se;
					q.push(II(d[v.fi], v.fi));
				}
		}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
