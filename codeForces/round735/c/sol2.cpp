#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		// 2 ^ 30 > 1e9
		// tim k nho nhat sao cho k ^ n >= m + 1;
		m++;
		int ans = 0;
		for(int k = 30; k >= 0 && n < m; --k) {
			if ((n >> k & 1) == (m >> k & 1))
				continue;
			if (m >> k & 1) {
				ans += (1 << k);
				n = n | ans;
			}

		}
		cout << ans << "\n";
	}
}