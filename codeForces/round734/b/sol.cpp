#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 1e5 + 10;

void solve() {
	string s; cin >> s;
	if (s.length() == 1) {
		cout << 0 << "\n";
		return;
	}
	vector<int> cnt(100, 0);
	for(int i = 0; i < s.length(); ++i)
		cnt[s[i] - 97]++;
	int k = 0, sum = 0;
	for(int i = 0; i < 100; ++i) {
		if (cnt[i] > 2){
			sum += cnt[i];
			k++;
		}
	}
	cout << k + (s.length() - sum) / 2 << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int tt; cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}

