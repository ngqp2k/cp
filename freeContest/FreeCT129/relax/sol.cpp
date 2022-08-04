#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n), f(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i == 0)
			f[i] = a[i];
		else f[i] = f[i - 1] ^ a[i];
	}
	vector< vector<int> > cnt(2, vector<int>((1 << 20) + 11, 0));
	cnt[1][0] = 1;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += cnt[i % 2][f[i]];
		cnt[i % 2][f[i]]++;
	}
	cout << ans;
	return 0;
}

