#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 2e5 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// FO(1);
	vector<II> a;
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		a.pb(II(x, i));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < (int) a.size(); ++i) {
		if (i == 0) {
			if (a[i].fi < a[i + 1].fi) {
				cout << a[i].se;
				return 0;
			}
		}
		else if (i == a.size() - 1) {
			if (a[i].fi > a[i - 1].fi) {
				cout << a[i].se;
				exit(0);
			}
		}
		else {
			if (a[i - 1].fi < a[i].fi && a[i].fi < a[i + 1]. fi) {
				cout << a[i].se;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}
