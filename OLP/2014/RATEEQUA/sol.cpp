#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	long long n, k;
	cin >> n >> k;
	long long res = 1;
	while (k > 0) {
		if (k % 2) {
			res = (res * n) % MOD;
		}
		n = n * n % MOD;
		k /= 2;
		cout << res << "\n";
	}
	return 0;
}
