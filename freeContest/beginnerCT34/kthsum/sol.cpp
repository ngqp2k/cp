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
    vi new_a, new_b;
    int i = 0, j = 0;
    while (true) {
        if (i == n)
            new_b.push_back(b[j]), j++;
        if (j == n)
            new_a.push_back(a[i]), i++;
        if (a[i] < b[j] && i < n && j < n) {
            new_a.pb(a[i]);
            i++;
        }
        else if (i < n && j < n){
            new_b.pb(b[j]);
            j++;
        }
        if (new_a.size() * new_b.size() > k) {
            break;
        }
        if (new_a.size() == k && new_b.size() == 0) {
            new_a.pop_back();
            new_b.push_back(b[0]);
            break;
        }
         if (new_b.size() == k && new_a.size() == 0) {
            new_b.pop_back();
            new_a.push_back(b[0]);
            break;
        }
    }
    vi ans;
    rep(i, new_a.size()) rep(j, new_b.size())
        ans.pb(new_a[i] + new_b[j]);
    sort(all(ans));
    rep(i, k) cout << ans[i] << " ";
}
