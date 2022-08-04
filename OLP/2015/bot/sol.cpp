#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 11;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	long long ans = -INF;
	long long sum = -INF;
	int left = -1, right = -1;
	int tmp_left = -1;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (sum < a[i]) {
			sum = a[i];
			tmp_left = i;
		}
		if (sum > ans) {
			ans = sum;
			left = tmp_left;
			right = i;
		}
	}
	cout << left + 1 << " " << right + 1 << " " << ans;
	return 0;
}
