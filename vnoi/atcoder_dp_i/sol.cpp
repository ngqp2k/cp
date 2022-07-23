#include <bits/stdc++.h>
#define infi 1e9 + 7
#define infll 1e18 + 7
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<long long> vl;
typedef vector<vector<long long>> vll;
typedef pair<int, int> ii;

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
	vector<double> a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		dp[i][0] = dp[i - 1][0] * (1 - a[i]);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = dp[i - 1][j - 1] * a[i] + dp[i - 1][j] * (1 - a[i]);
		}
	}
	double ans = 0;
	for (int i = (n / 2) + 1; i <= n; ++i)
		ans += dp[n][i];
	cout << setprecision(9) << fixed << ans << '\n';

	return 0;
}
