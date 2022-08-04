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

const int MOD = 1e9+9;
const int K = 1e5+5;
ll s[K];

ll power(ll a, int n) {
    ll tmp = a, ans = 1;
    while (n > 0) {
        if (n&1) ans = ans * tmp % MOD;
        tmp = tmp * tmp % MOD;
        n >>= 1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        ll n, a, b, k;
        cin >> n >> a >> b >> k;
        REP(i, k) cin >> s[i];

        ll A = 0;
        REP(i, k) A = (A + s[i] * power(a, n-i) % MOD * power(b, i) % MOD + MOD) % MOD;

        ll B = 0;
        ll x = power(b * power(a, MOD-2) % MOD, k);
        ll p = (power(x, (n+1)/k) - 1 + MOD) % MOD;
        ll q = power((x-1 + MOD) % MOD, MOD-2);
        B = q > 0 ? p * q % MOD : (n+1)/k;

        cout << A * B % MOD << '\n';
    }
}
