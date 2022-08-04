#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a) for (int i = 0; i < (a); ++i)
#define DEBUG(x) { cerr << #x << '=' << x << endl; }
#define Arr(a, l, r) { cerr << #a << " = {"; FOR(_, l, r) cerr << ' ' << a[_]; cerr << "}\n"; }
#define N 3030
#define pp pair<int, int>
#define endl '\n'
#define IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define taskname ""
#define bit(S, i) (((S) >> (i)) & 1)
using namespace std;
const long long MOD = 1e9 + 7;
long long dp[N][N];
void Add(long long &a, long long b) { a += b; if (a >= MOD) a -= MOD; }

void Solve() {
  int m, n;
  cin >> m >> n;
  FOR(i, 0, m) dp[i][0] = 1;
  FOR(i, 0, n) dp[0][i] = 1;
  FOR(i, 1, m) FOR(j, 1, n) {
    // Khong co hoc sinh nao o hang i
    cout << i << ", " << j << ": ";
    dp[i][j] = dp[i - 1][j];
    cout << dp[i][j] << ", ";
    // Chi dat mot hoc sinh o hang i
    dp[i][j] += dp[i - 1][j - 1] * 4 * j;
    cout << dp[i][j] << ", ";
    // Dat mot hoc sinh vao hang i va mot hoc sinh khac vao cung mot cot
    if (i > 1) {
      dp[i][j] += dp[i - 2][j - 1] * (i - 1) * j;
      cout << dp[i][j] << ", ";
    }
    // Dat hai hoc sinh o hang i
    if (j > 1) {
      dp[i][j] += dp[i - 1][j - 2] * ((j - 1) * j / 2);
      cout << dp[i][j] << ", ";
    }
    cout << "\n";
  }

  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= n; ++j)
      cout << dp[i][j] << " ";
    cout << "\n";
  }

  cout << (dp[m][n] - 1 + MOD) % MOD;
}
int main() {
  IO;
  Solve();
}
