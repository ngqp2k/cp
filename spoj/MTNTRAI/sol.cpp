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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch; cin >> ch;
			if (ch == '#')
				g[i][j] = -1;
			else if (ch == '.')
				g[i][j] = 0;
			else if (ch == 'c')
				g[i][j] = 1;
			else
				g[i][j] = 2;
		}
	}

	vector<vector<bool>> vis(n, vector<bool>(m));
	int ansF = 0, ansC = 0;
	const int dx[] = {0, 0, -1, 1};
	const int dy[] = {1, -1, 0, 0};

	auto dfs = [&](int i, int j) {
		int cntF = 0, cntC = 0;
		if (g[i][j] == 1) cntC++;
		if (g[i][j] == 2) cntF++;
		vis[i][j] = true;
		stack<pair<int, int>> st;
		st.push(make_pair(i, j));
		while (!st.empty()) {
			int u = st.top().fi;
			int v = st.top().se;
			st.pop();
			for (int i = 0; i < 4; ++i) {
				int x = u + dx[i];
				int y = v + dy[i];
				if (x < 0 || x >= n || y < 0 || y >= m)
					continue;
				if (g[x][y] == -1 || vis[x][y])
					continue;
				if (g[x][y] == 1) cntC++;
				if (g[x][y] == 2) cntF++;
				vis[x][y] = true;
				st.push(make_pair(x, y));
			}
		}
		if (cntC > cntF)
			ansC += cntC;
		else
			ansF += cntF;
	};
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j] && g[i][j] != -1) {
				dfs(i, j);
			}
		}
	}

	cout << ansF << " " << ansC << "\n";

	return 0;
}
