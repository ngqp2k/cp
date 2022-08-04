#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	string s; cin >> s;

	string a = ".";
	for(char c: s)
		a += c, a += ".";
	int N = a.length(), C = 1, R = 2, ans = 1;
	vector<int> f(N);
	f[0] = 0, f[1] = 1;
	for(int i = 2; i < N; ++i) {
		f[i] = (R > i) ? min(R - i, f[C * 2 - i]) : 0;
		while(i - f[i] - 1 >= 0 && i + f[i] + 1 < N) 
			if (a[i - f[i] - 1] == a[i + f[i] + 1])
				f[i]++;
			else
				break;
		ans = max(ans, f[i]);
		if (i + f[i] > R) {
			C = i;
			R = i + f[i];
		}
	}
	cout << ans;
}