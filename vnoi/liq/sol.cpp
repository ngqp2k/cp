#include <bits/stdc++.h>
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

const int mxn = 1e3 + 11;
int n;
int a[mxn], dp[mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];

		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			dp[i] = 1;
			for (int j = 1; j < i; ++j)
				if (a[j] < a[i])
					dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
		}

		cout << ans << "\n";

    return 0;
}
