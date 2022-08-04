#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 111;
const int INF = 1e9;

int n, m;
int a[mxN], dp[11111][mxN];

int solve(int m, int k, int cnt) {
	cout << m << " " << k << " " << cnt << "\n";
	if (m == 0) return cnt;
	if (m < 0 || k > n) return INF;
	if (dp[m][k] != -1) return dp[m][k];
	int ans = min(solve(m - a[k], k, cnt + 1), solve(m, k + 1, cnt));
	return dp[m][k] = ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(dp, -1, sizeof dp);
	int ans = solve(m, 1, 0);
	if (ans == INF)
		cout << "-1";
	else
		cout << ans;
}
