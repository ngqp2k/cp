#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

const int mxN = 3333;
int n, a[mxN], t[4];

bool binaryFind(int left, int right, int x) {
	while (left <= right) {
		int m = (left + right) / 2;
		if (a[m] == x)
			return true;
		else if (a[m] > x) right = m - 1;
		else left = m + 1;
	}
	return false;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n >= 3) {
		for (int i = 1; i <= n - 2; ++i) {
			for (int j = i + 1; j <= n - 1; ++j) {
				t[1] = a[i], t[2] = a[j];
				t[3] = a[j] + a[j] - a[i];
				if (t[2] > t[1] && binaryFind(j + 1, n, t[3])) {
					cout << "YES " << t[1] << " " << t[2] << " " << t[3];
					return 0;
				}
			}
		}
	}
	cout << "NO";
}