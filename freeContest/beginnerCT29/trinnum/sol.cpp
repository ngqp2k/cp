#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1e6 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int n, M;
int a[N], f[N], cm[N], cs[N];

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// FO(1);
	memset(f, 0, sizeof f);
	memset(cm, 0, sizeof cm);
	memset(cs, 0, sizeof cs);
	cin >> n >> M;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[a[i] % M]++;
	}
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < M; ++j)
				cm[(i % M * j % M) % M] += f[i] * f[j];

	int res = 0;

	for (int i = 0; i < M; ++i)
		for (int j = 0; j < M; ++j)
			if ((i % M * j % M) % M == 0)
				res += cm[i] * f[j];
	cout << res;
	return 0;
}
