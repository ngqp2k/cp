#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define MOD 1000000007
using namespace std;

const int mxN = 1111;
const int INF = 1e9 +7;
int dp[mxN][mxN], v[mxN][mxN];

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k; cin >> k >> n;
	if (k > n) {
		cout << -1;
		return 0;
	}
	rep(i, k) rep(j, n) cin >> v[i + 1][j + 1];

	rep(i, k + 1) dp[i][0] = -INF;
	rep(i, n + 1) dp[0][i] = 0;

	dp[0][0] = 0;
	for (int i = 1; i <= k; ++i) {
		dp[i][i - 1] = -INF;
		for (int j = i; j <= n; ++j) {
			if (i == j) dp[i][j] = dp[i - 1][j - 1] + v[i][j];
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + v[i][j]);
		}
	}

	cout << dp[k][n] << "\n";
	vector< pair<int, int> > ans;
	int i = k, j = n;
	while (i != 0 && j != 0) {
		while (dp[i][j] == dp[i][j - 1])
			j--;
		// /cout << i << " " << j << "\n";
		ans.pb(make_pair(i, j));
		i--, j--;
	}
	reverse(all(ans));
	for(auto i: ans)
		cout << i.fi << " " <<  i.se << "\n";
	return 0;
}