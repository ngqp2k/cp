#include <bits/stdc++.h>
 
using namespace std;

const int mxN = (int) 1e4 + 11;

int n, m;
vector<int> g[mxN];
int num[mxN], low[mxN], tail[mxN], parent[mxN];
bool isCut[mxN];
vector<pair<int, int>> bridges;
int timeDfs = 0, root, child;

void dfs(int u) {
    num[u] = low[u] = ++timeDfs;
    for (int v: g[u]) {
        if (v == parent[u])
            continue;
        if (!num[v]) {
            parent[v] = u;
            if (u == root)
                child++;
            dfs(v);
            if (low[v] == num[v]) {
                bridges.push_back(make_pair(u, v));
            }
            if (low[v] >= num[u] && u != root) {
                isCut[u] = true;
            }
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], num[v]);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(num, false, sizeof(num));
    memset(isCut, false, sizeof(isCut));

    for (int i = 1; i <= n; ++i) {
        if (!num[i]) {
            root = i, child = 0;
            parent[i] = i;
            dfs(i);
            isCut[i] = child > 1;
        }
    }

    int res1 = bridges.size();
    int res2 = 0;

    // cout << "Bridges: ";
    // for (auto p: bridges)
    //     cout << "(" << p.first << ", " << p.second << "), ";
    
    // cout << "\nCut: ";
    for (int i = 1; i <= n; ++i)
        if (isCut[i])
            // cout << i << ", ";
            res2++;
    
    cout << res2 << " " << res1;
    
    return 0;
}