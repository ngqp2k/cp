#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 1e5 + 10; 

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	vector<int> f(n + 1);
	f[0] = 0;
	for(int i = 1; i <= n; ++i) {
		int x; cin >> x;
		f[i] = f[i - 1] + x;
	}
	int ans = 0;
	for(int i = n; i >= k; --i)
		ans = max(ans, f[i] - f[i - k]);
	cout << ans;

	return 0;
}

