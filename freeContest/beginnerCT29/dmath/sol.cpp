#include<bits/stdc++.h>
using namespace std;
const int maxN = 4 + 5;
int q;
int a, b, c, n;
int x[maxN];
int y[maxN];
int ans;
void track(int i, int cur_a, int cur_b) {
	if ((cur_a + cur_b) % c == 0) ans = 1;
	if (i == n + 1 || ans == 1) return;

	int tmp_a = cur_a;
	for (int j = 0; j <= y[i]; j++) {
		if (j > 0) tmp_a = 1ll * tmp_a * x[i] % c;
		int tmp_b = cur_b;
		for (int k = 0; k + j <= y[i]; k++) {
			if (k > 0) tmp_b = 1ll * tmp_b * x[i] % c;
			track(i + 1, tmp_a, tmp_b);
			if (ans == 1) return;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--) {
		cin >> a >> b >> c >> n;
		for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
		ans = 0;
		track(1, a % c, b % c);
		cout << (ans ? "YES" : "NO") << '\n';
	}
}