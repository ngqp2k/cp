#include <bits/stdc++.h>
#define infi 1e9 + 7
#define infll 1e18 + 7
#define all(a) (a).begin(), (a).end()
#define pb push_back
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int g[111][111], vis[111][111];
int n, m;

void dfs(int u, int v) {
	for (int i = 0; i < 8; ++i) {
		int x = u + dx[i];
		int y = v + dy[i];
		if (x < 0 || x >= n || y < 0 || y >= m || !g[x][y] || vis[x][y])
			continue;
		vis[x][y] = true;
		dfs(x, y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			char ch; cin >> ch;
			if (ch == 'W')
				g[i][j] = 1;
			else
				g[i][j] = 0;
		}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!vis[i][j] && g[i][j]) {
				dfs(i, j);
				ans++;
			}
	cout << ans << '\n';

	return 0;
}