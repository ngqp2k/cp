#include <bits/stdc++.h>
using namespace std;

const long long INFLL = (long long) 1e18 + 7;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<long long> f(n + 1, 0);
	map<int, vector<int>> mm;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
		mm[a[i]].push_back(i);
	}
	long long ans = -INFLL;
	// cout << "size: " << mm.size() << "\n";
	for (auto t: mm) {
		vector<long long> v;
		for (int i = 0; i < (int)mm[t.first].size(); ++i) {
			// cout << mm[t.first][i] << " ";
			if (i > 0) {
				if (i == 1)
					v.push_back(f[mm[t.first][i]] - f[mm[t.first][i - 1] - 1]);
				else
					v.push_back(f[mm[t.first][i]] - f[mm[t.first][i - 1]]);
			}
		}
		// cout << "\n";
		// for (auto i: v) cout << i << " ";
		// cout << "\n";
		long long sum = 0, maxSum = -INFLL;
		for (int i = 0; i < (int)v.size(); ++i) {
			sum += v[i];
			if (v[i] > sum) {
				sum = v[i];
			}
			maxSum = max(maxSum, sum);
			ans = max(ans, maxSum);
		}
	// cout << maxSum << "\n";
	}
	cout << ans << "\n";
	return 0;
}
