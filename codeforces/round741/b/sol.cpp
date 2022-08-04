#include <bits/stdc++.h>
using namespace std;

bool prime[1000];

void solve() {
	int k; cin >> k;
	string s; cin >> s;
	for (char c: s)
		if (c == '1' || c == '4' || c == '6' || c == '8' || c == '9') {
			cout << "1\n";
			cout << c << "\n";
			return;
		}
	for (int i = 0; i < k - 1; ++i)
		for (int j = i + 1; j < k; ++j) {
			int a = s[i] - '0';
			int b = s[j] - '0';
			if (!prime[a * 10 + b]) {
				cout << "2\n";
				cout << a * 10 + b << "\n";
				return;
			}
		}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= 1000; ++i)
		if (prime[i])
			for (int j = i + i; j <= 1000; j += i)
				prime[j] = false;
  int tt; cin >> tt;
  while (tt--) solve();
}
