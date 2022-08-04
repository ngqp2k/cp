#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 1000 + 10; 
const int INF = 1e9 + 10; 

int g[mxN][mxN], dp[mxN][mxN];
int n;

int solve(int i, int j) {
	if (i == n && j == n) return 0;
	if (i > n || j > n) return INF;
	if (dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = min(solve(i + 1, j) + g[i + 1][j], solve(i, j + 1) + g[i][j + 1]);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> g[i][j];
		}
	}
	memset(dp, -1, sizeof dp);
	cout << solve(1, 1);

	return 0;
}

