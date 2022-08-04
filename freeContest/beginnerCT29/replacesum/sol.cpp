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

int n, k;
multiset<long long> ms;
int res = 0;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// FO(1);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		ms.insert(x);
	}
	while(ms.size() > 1){
		int cnt = 0, sum = 0, minMS = *ms.begin(), maxMS;
		while(cnt < k && !ms.empty()){
			sum += *ms.begin(), cnt++;
			maxMS = *ms.begin();
			ms.erase(ms.begin());
		}
		ms.insert(sum);
		res += (maxMS - minMS);
	}
	cout << *ms.begin() << "\n" << res;
	return 0;
}
