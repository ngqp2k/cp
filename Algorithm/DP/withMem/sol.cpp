#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 1000 + 10; 
const int MOD = 1e9 + 7;

typedef vector<int> vi;
typedef vector<vi> vii;

int solve(int i, int j, vii &dp, int n, vii g) {
	if (i > n || j > n || g[i][j])
		return 0;
	if (i == n && j == n)
		return 1;
	if (dp[i][j] != -1)
		return dp[i][j];
	int ans = solve(i + 1, j, dp, n, g) % MOD + solve(i, j + 1, dp, n, g) % MOD;
	return dp[i][j] = ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vii g(n + 1, vi(n + 1));
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> g[i][j];
	vii dp(n + 1, vi (n + 1, -1));
	int ans = solve(1, 1, dp, n, g);
	cout << ans % MOD;
	return 0;
}
