#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int mxN = 2000;
string a, b;

void solve(){
	cin >> a;
	cin >> b;
	if (a.length() < b.length())
		swap(a, b);
	vector< vector<int> > dp(2010, vector<int> (2010, 0));
	int n = a.length();
	int m = b.length();
	a = " " + a;
	b = " " + b;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[n][m];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
