#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define MOD 1000000007
#define INF 1000000007
//#define int long long

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef map<int, int> mi;

const int mxN = 1e6 + 11;

vi primes;
bool b[mxN];
int a[mxN];

void Sie() {
	memset(b, false, sizeof b);
	b[0] = b[1] = true;
	for (int i = 2; i * i <= mxN; ++i)
		if (!b[i])
			for (int j = i + i; j <= mxN; j += i)
				b[j] = true;

	for (int i = 2; i <= mxN; ++i)
		if (!b[i]) primes.pb(i);
}

int F(int n) {
	if (n < 2)
		return 0;
	int ans = 1, i = 0;
	while (n > 1) {
		if (!b[n]) {
			ans *= n;
			break;
		}
		if (n % primes[i] == 0)
			ans *= primes[i];
		while (n % primes[i] == 0)
			n /= primes[i];
		i++;
	}
	return ans;
}

int cnt[mxN];

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Sie();
	memset(cnt, 0, sizeof cnt);
	int l, r; cin >> l >> r;
	set<int> ss;
	for (int i = l; i <= r; ++i) {
		cnt[F(i)]++;
	}

	cnt[0] = 0, cnt[1] = 0;
	int ans = 0;
	for (int i = 2; i <= r; ++i) {
		if (cnt[i] > 1)
			ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << ans;
}
