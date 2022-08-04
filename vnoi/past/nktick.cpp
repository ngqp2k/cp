#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 60000;

int n;
int t[mxN + 1], r[mxN + 1];

// 5
// 2 5 7  8  4
// 4 9 10 10
// j
// -> 18: 

void solve(){
	int n; cin >> n;
	for(int i=1;i<=n;++i)
		cin >> t[i];
	for(int i=1;i<n;++i)
		cin >> r[i];
	long long dp[mxN + 1];
	memset(dp, 0, sizeof(dp));
	dp[1] = t[1];
	for(int i=2;i<=n;++i)
		dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i - 1]);
	cout << dp[n];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
