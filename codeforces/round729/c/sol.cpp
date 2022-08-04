#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 110;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;

typedef pair<int, int> II;

int n;

int lcm(int a, int b){
	return (a * b) / __gcd(a, b);
}

void solve() {
	cin >> n;
	if (n == 1){
		cout << 2 << "\n";
		return;
	}
	if (n == 2){
		cout << 5 << "\n";
		return;
	}
	int res = n * 2, i = 2, minNum = 2;
	while(minNum <= n){
		res += n / minNum;
		i++; 
		minNum = lcm(minNum, i);		
	}
	cout << res % MOD << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// FO(1);
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
