#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 2e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int n;

void solve() {
	cin >> n;
	if (n % 2 == 0) {
		for (int i = 1; i <= n; i += 2)
			cout << i + 1 << " " << i << " ";
		cout << "\n";
	}
	else {
		for (int i = 1; i <= n - 3; i += 2)
			cout << i + 1 << " " << i << " ";
		cout << n << " " << n - 2 << " " << n - 1 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// FO(1);
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
