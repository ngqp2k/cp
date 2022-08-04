// Longest common subsequence - LCS
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
// #define int long long
using namespace std;

void solve1(string s1, string s2) {
  /*
    * Quy hoach dong - Dynamic programing -> O(n ^ 2)
    - dp[i][j]: do dai xau con chung lon nhat cua s1[1..i] va s2[1..j]
    - dp[i][0] = 0, dp[0][i] = 0;
    - Neu s[i] == s[j] -> dp[i][j] = dp[i - 1][j - 1] + 1
    - Neu s[i] != s[j] -> dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
  */
  int n = s1.length(), m = s2.length();
  vector< vector<int> > dp(n + 1, vector<int> (m + 1, 0));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) 
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
  }
  cout << dp[n][m];
}

void solve2(string s1, string s2) {
  /*
    * Duyet --> O(N ^ 2)
    - Moi lan tinh dp[i][j] chi can dung 3 o:
      + dp[i - 1][j - 1]
      + dp[i][j - 1], dp[i - 1][j]
    - Dung hai mang a, b --> Ton it bo nho hon
  */
  int n = s1.length(), m = s2.length();
  vector<int> a(m + 1, 0), b(m + 1, 0);
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if (s1[i - 1] == s2[j - 1])
        b[j] = a[j - 1] + 1;
      else
        b[j] = max(b[j - 1], a[j]);
    }
    a = b;
  }
  // result <-- a[m]
  cout << s1.length() - a[m];
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in", "r", stdin);
  // freopen("ou", "w", stdout);
  int n; cin >> n;
  string s; cin >> s;
  string stmp = s;
  reverse(s.begin(), s.end());
  solve2(s, stmp);
}