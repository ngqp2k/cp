#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, maxi = 0, mini = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int x; cin >> x;
		maxi = max(maxi, x), mini = min(mini, x);
	}
	cout << 2 * maxi + (-mini) * 2;
}