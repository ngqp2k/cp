#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1e5 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	// FO(1);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int ia = n - 1, ib = n - 1, cnt = 0;

	int k = 0;
	while(k < n) {
		if (a[ia] >= b[ib]) {
			ia--;
		}
		else{
			ia--, ib--;
			cnt++;
		}
		k++;
	}
	cout << cnt;

	return 0;
}
