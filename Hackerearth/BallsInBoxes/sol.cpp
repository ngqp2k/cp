#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define MOD 1000000007
#define INF 100000000000000007
#define int long long
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef map<int, int> mi;

const int mxN = 1e4 + 11;
int n;
int val[mxN], cost[mxN];
int dp[mxN][1024];
bool vis[mxN][1024];
int sz;

int solve(int i, int mask) {
  if (i == n) {
    if (__builtin_popcount(mask) == sz) return 0;
    else return INF;
  }
  if (dp[i][mask] != -1) return dp[i][mask];
  return dp[i][mask] = min(solve(i + 1, mask), solve(i + 1, mask | val[i]) + cost[i]);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  set<int> distinctBalls;
  memset(dp, -1, sizeof dp);
  rep(i, n) {
    cin >> cost[i];
    string s; cin >> s;
    val[i] = 0;
    reverse(all(s));
    rep(j, 10)
      if (s[j] == '1')
        distinctBalls.insert(j), val[i] |= (1 << j);
  }
  sz = distinctBalls.size();
  cout << solve(0, 0);
}