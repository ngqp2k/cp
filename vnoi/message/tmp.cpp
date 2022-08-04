#include<bits/stdc++.h>
using namespace std;

const int N = 100;

int n, m;
vector<int> g[N];
int num[N], low[N];
bool vis[N], del[N];

int timeDfs = 0;

stack<int> S;

void dfs(int u){
    num[u] = low[u] = ++timeDfs;
    s.push(u);
    for(int v: g[u])
        if (!del[v]){
            if (num[v] == 0){
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else
                low[u] = min(low[u], num[v]);
        }
    if (low[u] == num[u]){
        ;
    }
}

int main(){
    cin >> n >> m;
    while(m--){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; ++i)
        if (num[i] == 0){
            dfs(i, i);
        }
}