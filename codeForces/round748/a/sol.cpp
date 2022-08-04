#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == b && b == c)
			cout << 1 << " " << 1 << " " << 1 << "\n";
		else {
			int m = max(a, max(b, c));
			// cout << m - a << " " << m - b << " " << m - c << "\n";
			if (a == m) {
				if (b == m)
					cout << 1 << " " << 1 << " " << m + 1 - c << "\n";
				else if (c == m)
					cout << 1 << " " << m + 1 - b << " " << 1 << "\n";
				else
					cout << 0 << " " << m + 1 - b << " " << m + 1 - c << "\n";
			}
			else if (b == m) {
				if (a == m)
					cout << 1 << " " << 1 << " " << m + 1 - c << "\n";
				else if (c == m)
					cout << m + 1 - a << " " << 1 << " " << 1 << "\n";
				else
					cout << m + 1 - a << " " << 0 << " " << m + 1 - c << "\n";
			}
			else if (c == m) {
				if (a == m)
					cout << 1 << " " << m + 1 - b << " " << 1 << "\n";
				else if (b == m)
					cout << m + 1 - a << " " << 1 << " " << 1 << "\n";
				else
					cout << m + 1 - a << " " << m + 1 - b << " " << 0 << "\n";
			}
		}
	}
}
