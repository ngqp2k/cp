#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 2e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;

typedef pair<int, int> II;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	FO(1);
	int a, b, c; cin >> a >> b >> c;

	cout << max(a + b, max(b + c, c + a));
	return 0;
}
