#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1e5 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// FO(1);
	int tt; cin >> tt;
	while (tt--) {
		int m, n; cin >> m >> n;
		if (m == 1){
			cout << 1 << "\n";
			continue;
		}

		int res = 0;
		int time = n / 3;
		res = 2 * time;
		n -= 3 * time;
		if (n != 0)
			res++;

		cout << res << "\n";
	}
	return 0;
}
