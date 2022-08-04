#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 1e5 + 10;

void solve() {
	int n; cin >> n;
	int N = n / 3;
	int K = n % 3;
	if (K < 2)
		cout << N + K << " " << N << "\n";
	else
		cout << N << " " << N + 1 << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int tt; cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}
