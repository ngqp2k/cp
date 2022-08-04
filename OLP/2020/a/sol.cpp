#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long l, r; cin >> l >> r;
	auto f = [&] (long long n) {
		long long res = 0;
		while (n > 0)
			n = n >> 1, res += n;
		return res;
	};
	long long ans = f(r) - f(l - 1);
	cout << ans;
}

