#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e6 + 11; 
int b[mxN];
bool s[mxN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	memset(b, 0, sizeof b);
	memset(s, false, sizeof s);

	int tt = a[0];

	for (int i = 1; i < n; ++i) tt = __gcd(tt, a[i]);
	for (int i = 0; i < n; ++i) b[a[i] / tt]++;

	int ans = 0;
	for (int i = 2; i < mxN; ++i)
		if (!s[i]) {
			int tmp = 0;
			for (int j = i; j < mxN; j += i)
				s[j] = true, tmp += b[j];
			ans = max(ans, tmp);
		}
	cout << (ans ? n - ans : -1);
}

using namespace std;

const int mxN = 5e6 + 11; 
int b[mxN];
bool s[mxN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	memset(b, 0, sizeof b);
	memset(s, false, sizeof s);

	int tt = a[0];

	for (int i = 1; i < n; ++i) tt = __gcd(tt, a[i]);
	for (int i = 0; i < n; ++i) b[a[i] / tt]++;

	int ans = 0;
	for (int i = 2; i < mxN; ++i)
		if (!s[i]) {
			int tmp = 0;
			for (int j = i; j < mxN; j += i)
				s[j] = true, tmp += b[j];
			ans = max(ans, tmp);
		}
	cout << (ans ? n - ans : -1);
}

