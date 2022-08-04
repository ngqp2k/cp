#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define MOD 1000000007
#define INF 1000000007
#define int long long

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef map<int, int> mi;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in1", "r", stdin);
    int n, k; cin >> n >> k;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    sort(all(a));
    sort(all(b));
    rep(i, (int)a.size())
    {
        if (a[i] == b[i]) continue;
        if (a[i] > b[i])
            swap(a, b);
        break;
    }
    vi ans;
    rep(i, n) rep(j, n) ans.pb(a[i] + b[j]);
    sort(all(ans));
    rep(i, k)
        cout << ans[i] << " ";
}
