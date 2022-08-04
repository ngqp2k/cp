#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1e5 + 1;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

ll f[N][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// FO(1);
	int n; cin >> n;
	f[1][0] = f[1][1] = f[1][2] = 1;

	for (int i = 2; i <= n; ++i) {
		f[i][0] = (f[i - 1][0] % MOD + f[i - 1][1] % MOD + f[i - 1][2] % MOD);
		f[i][2] = (f[i - 1][0] % MOD + f[i - 1][1] % MOD + f[i - 1][2] % MOD);
		f[i][1] = (f[i - 1][0] % MOD + f[i - 1][2] % MOD);
	}

	cout << (f[n][0] % MOD + f[n][1] % MOD + f[n][2] % MOD) % MOD;
	return 0;
}
