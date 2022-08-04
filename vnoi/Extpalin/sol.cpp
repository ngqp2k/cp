#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
  string s; cin >> s;
  if (s.length() == 1) {
    cout << s << "\n";
    return;
  }
  string a = ".";
  for(char c: s)
    a += c, a += ".";
  int N = a.length();
  vector<int> L(N);
  L[0] = 0, L[0] = 1;
  int C = 1, R = 2;
  for(int i = 2; i < N; ++i) {
    L[i] = (R > i) ? min(R - i, L[C * 2 - i]) : 0;
    while (0 <= (i - L[i] - 1) && (i + L[i] + 1) < N)
      if (a[i - L[i] - 1] == a[i + L[i] + 1])
        L[i]++;
      else
        break;
    if (i + L[i] > R) {
      R = i + L[i];
      C = i;
      if (R == N - 1) {
        //cout << s.length() - L[C] << "\n";
        string ans = s.substr(0,s.length() - L[C]);
        reverse(ans.begin(), ans.end());
        cout << s << ans << "\n";
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in", "r", stdin);
  // freopen("ou", "w", stdout);
  int T; cin >> T;
  while (T--) {
    solve();
    // return 0;
  }
}