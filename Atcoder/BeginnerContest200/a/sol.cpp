#include <bits/stdc++.h>
#define int long long

int roundd(double x) {
	return (int)(x + 0.999999999);
}

int32_t main() {
	using namespace std;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	cout << roundd( (double) n / 100 * 1.0) << '\n';
}