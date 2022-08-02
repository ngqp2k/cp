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

	int n; cin >> n;
	vector<int> a(n + 1);
	vector<long long> f(n + 1);
	f[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
	for (int i = 1; i < n; ++i)
		dp[i][i + 1] = a[i] + a[i + 1];
	for (int step = 2; step < n; ++step) {
		for (int i = 1; i <= (n - step); ++i) {
			int j = i + step;
			dp[i][j] = infll;
			for (int k = i; k < j; ++k)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + f[j] - f[i - 1]);
		}
	}
	cout << dp[1][n] << '\n';
	

	return 0;
}
