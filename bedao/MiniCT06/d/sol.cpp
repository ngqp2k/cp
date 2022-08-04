#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 11;
bool b[mxN];

void Sieve() {
	memset(b, true, sizeof b);
	b[0] = b[1] = false;
	for (int i = 2; i * i <= (int)1e6; ++i)
		if (b[i])
			for (int j = i + i; j < (int)1e6; j += i)
				b[j] = false;
}

bool check(int n, int x) {
	if (n < 2 || n > x)
		return false;
	if (b[n])
		return true;
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Sieve();
	int n, x; cin >> n >> x;
	vector<int> a(n), f(n, 0);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		
		if (check(a[i], x)) {
			cnt++;
			if (i == 0)
				f[i] = 1;
			else
				f[i] = f[i - 1] + 1;
		}
		else
			if (i == 0)
				f[i] = 0;
			else
				f[i] = f[i - 1];
	}

	int ans = cnt - f[cnt - 1];
	for (int i = cnt; i < n; ++i)
		ans = min(ans, cnt - (f[i] - f[i - cnt]));

	cout << ans;
}

