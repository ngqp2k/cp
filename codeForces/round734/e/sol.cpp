#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, m, kh; cin >> n >> m >> kh;
		int kv = n * m / 2 - kh;
		if (n % 2 == 1) {
			if (m % 2 == 1) {
				cout << "no\n";
				continue;
			}
			kh -= m / 2;
			if (kh < 0) {
				cout << "no\n";
				continue;
			}
		}
		else if (m % 2 == 1) {
			kv -= n / 2;
			if (kv < 0) {
				cout << "no\n";
				continue;
			}
		}
		if (kv & 1 || kh & 1) {
			cout << "no\n";
			continue;
		}
		cout << "yes\n";
	}

	return 0;
}

