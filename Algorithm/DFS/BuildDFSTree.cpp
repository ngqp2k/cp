#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << "-> " << #x << ": "; _print(x); cerr << "\n";
template<class T> void _print(T x) { cerr << x;}
template<class T> void _print(vector<T> v) {
    cerr << "[ ";
    for (T val: v) cerr << val << " ";
    cerr << "]";
}
template<class T> void _print(vector<vector<T>> v) {
    cerr << "[\n";
    cerr << "\n]";
}

const int mxN = 1e5 + 11;
vector< vector<int> > adj;
int n, m;

class UndirectedDFS {
    public:
    vector< vector<int> > adj;
    vector<int> num, low, tail, parent;
    int V, E; // Verticals
    int timeDfs = 0;
    UndirectedDFS(vector< vector<int> > g) {
        V = g.size();
        dbg(V);
        num.resize(V, 0);
        low.resize(V);
        parent.resize(V);
        // tail.resize(V);
        for (int i = 0; i < V; ++i) {
            if (!num[i]) {
                parent[i] = i;
                DFS(i, g);
            }
        }
    }

    int step = 0;

    void DFS(int u, vector< vector<int> > g) {
        timeDfs++;
        num[u] = low[u] = timeDfs;
        for (int i = 0; i < (int) g[u].size(); ++i) {
            int v = g[u][i];
            if (!num[v]) {
                parent[v] = u;
                DFS(v, g);
                low[u] = min(low[u], low[v]);
            }
            else if (v != parent[u])
                low[u] = min(low[u], num[v]);
        }
    }


    void PrintInfo() {
        // cout << "Xuat ma tran ke\n";
        // for (int i = 0; i < (int) adj.size(); ++i) {
        //     for (int j = 0; j < (int) adj[i].size(); ++j)
        //         cout << adj[i][j] + 1 << " ";
        //     cout << "\n";
        // }
        dbg(num);
        dbg(low);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.inp", "r", stdin);
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    UndirectedDFS dfs(adj);
    dfs.PrintInfo();
    return 0;
}
