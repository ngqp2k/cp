#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;


const int INF = (int) 1e9 + 7;
const int MOD = 14062008;
const int mxN = 1e5;

int n, k;
bool b[mxN + 1];
long long dp[mxN + 1];

void solve(){
	cin >> n >> k;
	memset(b, 0, sizeof(b));
	for(int i=1;i<=k;++i){
		int x; cin >> x;
		b[x] = true;
	}
	dp[1] = 1;
	dp[2] = b[2] ? 0 : 1;
	for(int i=3;i<=n;++i)
		if (!b[i])
		  dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	cout << dp[n];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
