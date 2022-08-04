#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define TASK ""

using namespace std;
const int N = 1e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;


void File(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(TASK".INP", "r",stdin);
	// freopen(TASK".OUT", "w",stdout);
}

vector<int> g[N + 1];
int num[N + 1], low[N + 1];
int deleted[N + 1];
int timeDfs = 0, cnt = 0;
stack<int> ss;

void dfs(int u){
	num[u] = low[u] = ++timeDfs;
	ss.push(u);
	for(int v: g[u]){
		if (deleted[v]) continue;
		if (num[v] == 0){
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], num[v]);
	}
	if (low[u] == num[u]){
		cout << "SCC " << ++cnt << ": ";
		int v;
		do{
			v = ss.top();
			cout << v << " ";
			ss.pop();
			deleted[v] = true;
		} while(u != v);
		cout << "\n";
	}

}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int u, v; cin >> u >> v;
		g[u].pb(v);
	}
	memset(num, 0, sizeof(num));
	memset(deleted, false, sizeof(deleted));
	for(int i=1;i<=n;++i)
		if (num[i] == 0)
			dfs(i);
	cout << cnt;
}

int main() {
  File();
  int T = 1;
  // cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}
