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
	vector<long long> a(n + 1), b(n + 1), c(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i] >> c[i];

	vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(n + 1, infll)));
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int cnt_b = 0; cnt_b < i; ++cnt_b) {
			for (int cnt_c = 0; cnt_c + cnt_b < i; ++cnt_c) {
				dp[i][cnt_b][cnt_c] = min(dp[i][cnt_b][cnt_c], dp[i - 1][cnt_b][cnt_c] + a[i]);
				dp[i][cnt_b + 1][cnt_c] = min(dp[i][cnt_b + 1][cnt_c], dp[i - 1][cnt_b][cnt_c] + b[i] - cnt_b);
				dp[i][cnt_b][cnt_c + 1] = min(dp[i][cnt_b][cnt_c + 1], dp[i - 1][cnt_b][cnt_c] + c[i] - cnt_c);
			}
		}
	}

	// Subtack n <= 200

	long long ans = infll;
	for (int cnt_b = 0; cnt_b <= n; ++cnt_b) {
		for (int cnt_c = 0; cnt_c + cnt_b <= n; ++cnt_c) {
			ans = min(ans, dp[n][cnt_b][cnt_c]);
		}
	}

	cout << ans << "\n";

	return 0;
}
