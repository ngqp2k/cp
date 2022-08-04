#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
// #define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 2000 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;

typedef pair<int, int> II;


int n;
vector<double> l, r;


void solve() {
	cin >> n;
	l.resize(n), r.resize(n);
	vector<int> t(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i] >> l[i] >> r[i];
		if (t[i] >= 3)
			l[i] += 0.25;
		if (t[i] % 2 == 0)
			r[i] -= 0.25;
	}

	int cnt = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j)
			if (max(l[i], l[j]) <= min(r[i], r[j]))
				cnt++;
	}
	cout << cnt;

}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// FO(1);
	solve();
	return 0;
}
