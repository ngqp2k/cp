#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int INF = 1e18 + 7;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n + 1), f(n + 1);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i > 1)
			f[i] = f[i - 1] + a[i];
		else
			f[i] = a[i];
	}
	int ans = INF;
	for(int i = 1; i <= n; ++i) {
		ans = min(ans, abs(f[i]  - (f[n] - f[i])));
	}
	cout << ans;
}
