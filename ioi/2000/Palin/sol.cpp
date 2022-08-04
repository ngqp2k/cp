#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
// #define int long long
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<char> ch(n);
  for(int i = 0; i < n; ++i)
    cin >> ch[i];
  vector< vector<int> > dp(n, vector<int> (n));
  for(int step = 1; step < n; ++step) {
    for(int i = 0; i < n - step; ++i) {
      int j = i + step;
      if (ch[i] == ch[j])
        dp[i][j] = dp[i + 1][j - 1];
      else
        dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
    }
  }  
  cout << dp[0][n - 1];
  
}