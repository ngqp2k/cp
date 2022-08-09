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

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int ,int>> b) {
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<pair<int, pair<int ,int>>> d;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            d.push_back(make_pair(a[i][j], make_pair(i, j)));
        }

    sort(d.begin(), d.end(), cmp);
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));

    const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

    auto dfs = [&](int i, int j) {
        vis[i][j] = true;
        stack<pair<int ,int>> st;
        st.push(make_pair(i, j));
        while (!st.empty()) {
            int u = st.top().first;
            int v = st.top().second;
            st.pop();
            for (int k = 0; k < 8; ++k) {
                int x = u + dx[k];
                int y = v + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if (vis[x][y] || a[x][y] > a[u][v])
                    continue;
                vis[x][y] = true;
                st.push(make_pair(x, y));
            }
        }
    };

    int ans = 0;
    for (int i = 0; i < (int)d.size(); ++i) {
        if (!vis[d[i].second.first][d[i].second.second]) {
            dfs(d[i].second.first, d[i].second.second);
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}

