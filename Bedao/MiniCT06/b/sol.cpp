#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n, k;
	cin >> m >> n >> k;
	vector<int> a(m);
	for (int i = 0; i < m; ++i) cin >> a[i];
	sort(a.rbegin(), a.rend());
	for (int i = 0; i < m - n + 1; ++i) {
		if (a[i] - a[i + n - 1] <= k) {
			long long res = 0;
			// cout << i << " " << i + n - 1 << "\n";
			for (int j = i; j <= i + n - 1; ++j)
				res += a[j];
			cout << res;
			return 0;
		}
	}
	cout << -2;
}

