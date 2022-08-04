#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name)                        \
        freopen(name".inp", "r", stdin);  \
        freopen(name".out", "w", stdout);

#define ll long long

const int oo = (int)(1e9 + 7);
const int N = (int)(1e6 + 5);

int32_t main()
{
        fast;
//        file("marec");

        int n;
        map<int, int> m;

        cin >> n;
        for (int i = 1; i <= n; ++i) {
                int t;
                cin >> t;
                ++m[t];
        }

        int ans = 0, cnt = 0;
        for (auto i : m) {
                ans += (i.second >= 4);
                cnt += (i.second >= 2);
        }
        ans += cnt * (cnt - 1) / 2;

        cout << ans << "\n";

        return 0;
}

