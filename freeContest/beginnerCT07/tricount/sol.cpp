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
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    int ans = 0;
    a.pb(INF);
    for (int i = 0; i < n - 2; ++i) {
        if (a[i] == 0) continue;
        for (int j = i + 1; j < n - 1; ++j) {
            int pos = lower_bound(all(a), a[i] + a[j]) - a.begin();
            ans += pos - 1 - j;
        }
    }
    cout << ans;
}
