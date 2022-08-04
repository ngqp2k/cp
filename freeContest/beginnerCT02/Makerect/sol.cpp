#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	int maxx[2], j = 0;
	for(int i = n - 1; i >= 0; --i) {
		if (a[i] == a[i - 1]) {
			maxx[j] = a[i], j++;
			if (j == 2) {
				cout << maxx[0] * maxx[1];
				return 0;
			}
			i--;
		}
	}
	cout << 0;
}
