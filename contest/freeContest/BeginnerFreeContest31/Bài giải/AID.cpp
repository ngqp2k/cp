#include <bits/stdc++.h>

#define ll long long
#define x first
#define y second
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for(int i=a, _n=b; i<=_n; ++i)
#define FORD(i, a, b) for(int i=a, _n=b; i>=_n; --i)
#define REP(i, _n) for(int i=0; i<_n; ++i)
using namespace std;

const int N = 1005;
int n, k, par[N], vis[N], d[N], s;
vector<int> ke[N], ans, road;

void dfs(int u) {
    if (d[u] > d[s] && d[u] <= k) s = u;
    for(int v: ke[u]) {
        d[v] = d[u] + 1;
        dfs(v);
    }
}
void dfs2(int u) {
    ans.pb(u);
    for(int v: ke[u]) if (!vis[v] && k > 0) {
        k -= 1; dfs2(v); ans.pb(u);
    }
}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        cin >> n >> k;
        FOR(i, 2, n) {
            cin >> par[i];
            ke[par[i]].pb(i);
        }

        d[1] = 1; s = 1; dfs(1);
        k -= d[s];
        for(int u=s; u!=0; u=par[u]) {
            road.pb(u);
            vis[u] = 1;
        }
        reverse(all(road));

        REP(i, sz(road)) dfs2(road[i]);

        cout << ans.size() -1 << '\n';
        for(int u: ans) cout << u <<' ';
        cout << '\n';

        ans.clear();
        road.clear();
        FOR(i, 1, n) {
            vis[i] = 0;
            par[i] = 0;
            ke[i].clear();
        }
    }
}
