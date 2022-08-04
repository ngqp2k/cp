#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
// #define int long long
// #define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1000 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;
typedef pair<int, II> III;

int n, m;
int a[N][N], f[N][N];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

priority_queue<III, vector<III>, greater<III>> Q;

void Dijkstra(){
	// for(int i = 0; i <= n + 1; ++i){
	//     for(int j = 0; j <= m + 1; ++j)
	//         cout << a[i][j] << "  ";
	//     cout << "\n";
	// }
	// return;
	f[1][1] = 0;
	Q.push(III(1, II(1, 1)));

	while (!Q.empty()) {
		int u = Q.top().se.fi;
		int v = Q.top().se.se;
		Q.pop();

		if (u == n && v == m)
			break;

		for(int i = 0; i < 4; ++i)
			if (a[u + dx[i]][v + dy[i]] != -1) {
				int step;
				if (f[u][v] % 2 == 0)
					if (a[u][v] == 0)
						step = 2;
					else
						step = 1;
				else
					if (a[u][v] == 0)
						step = 1;
					else	
						step = 2;
				if (f[u + dx[i]][v + dy[i]] > f[u][v] + step) {
					f[u + dx[i]][v + dy[i]] = f[u][v] + step;
					Q.push(III(f[u][v] + step, II(u + dx[i], v + dy[i])));
				}
			}
	}

	if (f[n][m] % 2 == 0)
		if (a[n][m] == 0)
			cout << f[n][m] + 1;
		else
			cout << f[n][m];
	else
		if (a[n][m] == 0)
			cout << f[n][m];
		else
			cout << f[n][m] + 1;
}

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	cin >> n >> m;
}

	for(int i = 1; i <= n; ++i){
		a[i][0] = -1;
		a[i][m + 1] = -1;
	}

	memset(f, 0x3f, sizeof f);

	Dijkstra();

	return 0;
}
