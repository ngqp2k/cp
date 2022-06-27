#include <bits/stdc++.h>
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

// Problem: BFS use array

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int s, f; cin >> s >> f;
    vector<vector<int>> g(n + 1, vector<int> (n + 1, 0));
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    vector<bool> vis(n + 1, false);
    vector<int> prev(n + 1);

    queue<int> q;
    q.push(s);
    vis[s] = true;
    prev[s] = -1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == f) {
            vector<int> ans;
            int v = f;
            while (v != -1) {
                ans.pb(v);
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
            return 0;
        }

        for (int v = 1; v <= n; ++v) {
            if (!vis[v] && g[u][v]) {
                q.push(v);
                vis[v] = true;
                prev[v] = u;
            }
        }
    }

    return 0;
}
