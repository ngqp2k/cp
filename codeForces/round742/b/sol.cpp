#include <bits/stdc++.h>
using namespace std;

const int MAX = (int)3e5 + 11;
int f[MAX];

void solve() {
	int a, b; cin >> a >> b;
	;
	// a - 1 ^ n = b
	// a = 6 -> 0 1 2 3 4 5
// 5
// 1 1 --> 0 2 3 --> 3
// 2 1 --> 0 1 --> 2
// 2 0 --> 0 1 1 --> 3 
// 1 10000 --> 0 10000 --> 2
// 2 10000 --> 0 1 100001 --> 3
// 5 1
	int tmp = f[a - 1];
	if (tmp == b) {
		cout << a << "\n";
	}
	else {
		if ((tmp ^ a) == b)
			cout << a + 2 << "\n";
		else
			cout << a + 1 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	f[0] = 0;
	for (int i = 1; i < MAX; ++i)
		f[i] = f[i - 1] ^ i;
	int tt; cin >> tt;
	while (tt--) solve();
}
