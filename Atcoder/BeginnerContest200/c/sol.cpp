#include <bits/stdc++.h>
#define int long long

const int mxN = 2e5 + 10;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N; std::cin >> N;

	std::vector<int> a(N);
	for(int &x: a) std::cin >> x;

	std::vector<int> cnt(300, 0);
	int ans = 0;
	for(int i = N - 1; i >= 0; --i) {
		ans += cnt[a[i] % 200];
		cnt[a[i] % 200]++;
	}
	std::cout << ans;
}
