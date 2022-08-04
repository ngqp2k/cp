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

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	// FO(1);
	ull a, b, c, d; cin >> a >> b >> c >> d;
	//127364987 1237401234 12341 1237388895
	ull nmax = max(a, max(b, c));
	ull nmin = min(a, min(b, c));
	cout << ((nmax - nmin <= d)  ? "Yes" : "No");
	return 0;
}
