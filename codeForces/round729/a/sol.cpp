#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 110;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;

typedef pair<int, int> II;

int n;

void solve(){
	cin >> n;
	int cnt = 0;
	for(int i=1;i<=2*n;++i){
		int x; cin >> x;
		if (x % 2 == 1)
			cnt++;
	}
	if (cnt == n)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	FO(1);
	int tt; cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}
