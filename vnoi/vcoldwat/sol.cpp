#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
// #define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1e5 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int n, c;
vector<int> g[N];
int num[N], low[N];

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	
	cin >> n >> c;
	for(int i = 1; i <= c; ++i){
		int e, b1, b2; cin >> e >> b1 >> b2;
		g[e].pb(b1);
		g[e].pb(b2);
	}

	vector<int> f(n + 1, 0);
	f[1] = 1;

	//BFS
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		for(int v: g[u]){
			f[v] = f[u] + 1;
			Q.push(v);
		}
	}

	for(int i = 1; i <= n; ++i)
		cout << f[i] << "\n";

	return 0;
}
