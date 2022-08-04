#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1e5 + 7;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int n;
vector<II> a;

void solve(){
	a.clear();
	cin >> n;
	for(int i=1;i<=n;++i){
		int x; cin >> x;
		a.pb(II(x, i));
	}
	sort(a.begin(), a.end());
	int cnt = 0;
	for(int i=0;i<a.size();++i)
		for(int j = i + 1; j < a.size(); ++j){
			if (a[i].fi * a[j].fi > 2 * n) break;
			if (a[i].fi * a[j].fi == a[i].se + a[j].se)
				cnt++;
		}
	cout << cnt << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	// FO(1);
	int tt; cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}
