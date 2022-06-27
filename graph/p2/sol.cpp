#include <bits/stdc++.h>

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

// Problems: BFS use vector (dynamic array)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int s, f; cin >> s >> f;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    vector<int> prev(n + 1);

    vis[s] = true;
    queue<int> q;
    q.push(s);
    prev[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == f) {
            int v = f;
            vector<int> ans;
            while (v != -1) {
                ans.push_back(v);
                v = prev[v];
            }
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); ++i) {
                if (i == 0)
                    cout << ans[i];
                else
                    cout << " -> " << ans[i];
            }
            cout << "\n";
        }

        for (int v: g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                prev[v] = u;
                q.push(v);
            }
        }
    }

    return 0;
}
