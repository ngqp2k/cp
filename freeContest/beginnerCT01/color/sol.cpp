#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int MOD = 1000000000 + 7;

int powQuick(int x, int n) {
	if (n == 1)
		return x;
	if (n == 0)
		return 1;
	int tmp = powQuick(x, n / 2);
	if (n % 2 == 0)
		return ((tmp % MOD) * (tmp % MOD)) % MOD;
	else
		return (((tmp % MOD) * (tmp % MOD)) % MOD * (x % MOD)) % MOD;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, K; cin >> N >> K;

	N = N - K + 1;
	int t = 1, tt = 1;
	for (int i = N; i >= N - K + 1; --i)
		t = ((t % MOD) * (i % MOD)) % MOD;
	for (int i = 1; i <= K; ++i)
		tt = (tt % MOD) * (i % MOD) % MOD;

	int res = (t * powQuick(tt, MOD - 2)) % MOD;
	cout << res;
	return 0;
}

