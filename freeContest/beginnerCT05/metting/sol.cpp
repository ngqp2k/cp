#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 10;

char ch;

void solve() {
	string s; cin >> s;
	for (char c: s)
		if (c == ch)
			return;
	cout << s << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	cin >> ch;
	for (int i = 0; i < n; ++i) {
		solve();
	}
	return 0;
}

