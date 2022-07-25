#include <bits/stdc++.h>
#define infi 1e9 + 7
#define infll 1e18 + 7
#define all(a) (a).begin(), (a).end()
#define pb push_back
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("in", "r", stdin);

	int n, L; cin >> n >> L;
	vector<int> a(n + 1), f(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i == 1)
			f[i] = a[i];
		else
			f[i] = f[i - 1] + a[i];
	}
	// dp[i] he so phat nho nhat neu chia i tu dau tien vao van ban
	vector<int> dp(n + 1);
	auto sum = [&] (int l, int r) { return f[r] - f[l - 1]; };
	for (int i = 1; i <= n; ++i) {
		dp[i] = 1111;
		for (int j = 0; j < i; ++j) {
			if (sum(j + 1, i) > L)
				continue;
			dp[i] = min(dp[i], max(dp[j], L - sum(j + 1, i)));
		}
	}

	cout << dp[n] << '\n';

	return 0;
}
