#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

long long quickPower(long long n, long long x) {
	if (x == 1)
		return n;
	long long res = quickPower(n, x / 2);
	if (x % 2 == 0)
		return (res % MOD * res % MOD);
	else
		return ((res % MOD * res % MOD) % MOD * n % MOD) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	long long N, L;
	cin >> N >> L;
	// result = ((L ^ 2) % MOD * ((4 ^ n - 1) % MOD . 3 ^ (MOD - 2) + MOD) % MOD) % MOD
	// A = (L ^ 2) % MOD
	// B = (4 ^ n - 1) % MOD = ((4 ^ n) % MOD - 1 + MOD) % MOD
	// C = 3 ^ (MOD - 2)
	// result = (A * (B * C + MOD) % MOD) % MOD
	long long A = (long long)(L % MOD * L % MOD) % MOD;
	long long B = (quickPower(4, ++N) - 1 + MOD) % MOD;
	long long C = quickPower(3, MOD - 2);
	long long res = (A * ((B * C) % MOD + MOD) % MOD) % MOD;
	// cout << A << " " << B << " " << C << "\n";
	cout << res;
	return 0;
}
