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
const long long INFLL = 1e18 + 7;

typedef pair<int, int> II;

vector<int> f;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// FO(1);
	string s; cin >> s;
	s = s + "#";
	int n = s.length();

	int res = 1;

	for (int i = 0; i < n - 1; ++i)
		if (s[i] == s[i + 1]) {
			int cnt = 0;
			for (int j = i; j < n; ++j) {
				if (s[i] == s[j])
					cnt++;
				else{
					i = j - 1;
					break;
				}
			}
			res = res % MOD * cnt % MOD;
		}
	cout << res;
	return 0;
}
