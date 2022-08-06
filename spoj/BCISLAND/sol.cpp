#include <bits/stdc++.h>
#define infi 1e9 + 7
#define infll 1e18 + 7
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
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

const int mxn = 100 + 11;
bool sea[mxn][mxn];
int n, m, g[mxn][mxn];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};

int solve() {
	set<int> ss;
	memset(g, 0, sizeof g);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> g[i][j];
			if (g[i][j])
				ss.insert(g[i][j]);
		}

	int T;

	auto dfs1 = [&](int i, int j) {
		sea[i][j] = true;
		stack<pair<int ,int>> st;
		st.push(make_pair(i, j));
		while (!st.empty()) {
			int u = st.top().fi;
			int v = st.top().se;
			st.pop();
			for (int i = 0; i < 4; ++i) {
				int x = u + dx[i];
				int y = v + dy[i];
				if (x < 0 || x > n + 1 || y < 0 || y > m + 1)
					continue;
				if (sea[x][y] || g[x][y] > T)
					continue;
				sea[x][y] = true;
				st.push(make_pair(x, y));
			}
		}
	};

	auto dfs2 = [&](int i, int j) {
		sea[i][j] = true;
		stack<pair<int ,int>> st;
		st.push(make_pair(i, j));
		while (!st.empty()) {
			int u = st.top().fi;
			int v = st.top().se;
			st.pop();
			for (int i = 0; i < 4; ++i) {
				int x = u + dx[i];
				int y = v + dy[i];
				if (x < 0 || x > n + 1|| y < 0 || y > m + 1)
					continue;
				if (sea[x][y])
					continue;
				sea[x][y] = true;
				st.push(make_pair(x, y));
			}
		}
	};

	for (auto it = ss.begin(); it != ss.end(); ++it) {
		T = *it;
		memset(sea, 0, sizeof sea);
		dfs1(0, 0);
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (!sea[i][j]) {
					dfs2(i, j);
					cnt++;
					if (cnt > 1)
						return T;
				}
			}
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; 1; i++) {
		cin >> n >> m;
		if (!n || !m)
			break;
		int ans = solve();
		if (ans)
			cout << "Case " << i << ": Island splits when ocean rises " << ans << " feet.\n";
		else
			cout << "Case " << i << ": Island never splits.\n";
	}

	return 0;
}