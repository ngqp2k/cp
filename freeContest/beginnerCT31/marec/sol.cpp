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

vector<int> cnt(1010, 0);
set<int> ss;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int res = 0;

	for (int i = 0; i < n; ++i){
		int x; cin >> x;
		cnt[x]++;
		if (cnt[x] >= 2)
			ss.insert(x);
	}

	if (ss.size() == 1)
		cout << 1;
	else{
		for(auto i: ss)
			if (cnt[i] >= 4)
				res++;
		cout << res + ss.size() * (ss.size() - 1) / 2;
	}
	return 0;
}
