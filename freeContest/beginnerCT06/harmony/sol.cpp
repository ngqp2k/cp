#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[1111];

void solve() {
	int n; cin >> n;
	int mid = (n % 2 == 0) ? n / 2 : n / 2 + 1;
	int left = 1, right = 0;
	int maxx = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i == 1) continue;
		right = i;
		if (abs(a[i - 1] - a[i]) == 1) {
				maxx = max(maxx, right - left + 1);
		}
		else {
			left = i;
		}
	}
	if (maxx > mid) cout << "Yes\n";
	else cout << "No\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
}

