#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;

int n, s[maxn], trace[maxn], dem;
ll m, a[maxn], ans;
double f[maxn];
vector<int> e[maxn];

ll tinh(ll a, ll n)
{
    if (n == 1) return a;
    ll tmp = tinh(a, n >> 1);
    tmp = (tmp + tmp) % m;
    if (n % 2) tmp = (tmp + a) % m;
    return tmp;
}
void dfs(int u, int trc)
{
    double tmp = 0;
    int ok = 0;
    for (int i = 0; i < (int)e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == trc) continue;
        ok = 1;
        dfs(v, u);
        if (f[v] > tmp)
        {
            trace[u] = v;
            tmp = f[v];
        }
    }
    if (!ok) f[u] = log10(a[u]);
    else
    {
        f[u] = log10(a[u]) + tmp;
    }
}
int main()
{
    //freopen("QTREEV.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, -1);
    int k = 1;
    while (k) {
        s[++dem] = k;
        k = trace[k];
    }
    ans = 1;
    for (int i = dem; i >= 1; i--) {
        ans = tinh(a[s[i]], ans);
    }
    cout << ans;
    return 0;
}
