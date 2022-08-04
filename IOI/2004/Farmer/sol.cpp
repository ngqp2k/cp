#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("test/farmer-2.in", "r", stdin);
  // freopen("ou", "w", stdout);
  int Q, nFields, nStrips; cin >> Q >> nFields >> nStrips;
  vector<int> Strips(nStrips + 1), Fields(nFields + 1);
  for(int i = 1; i <= nFields; ++i) cin >> Fields[i];  
  for(int i = 1; i <= nStrips; ++i) cin >> Strips[i];  
  vector< vector<int> > dp_1(nFields + 1, vector<int> (Q + 1, 0));
  vector< vector<int> > dp_2(nStrips + 1, vector<int> (Q + 1, 0));

  for(int i = 1; i <= nFields; ++i) {
    for(int j = 1; j <= Q; ++j) {
      if (j < Fields[i])
        dp_1[i][j] = dp_1[i - 1][j];
      else {
        dp_1[i][j] = max(dp_1[i - 1][j], 
                         dp_1[i - 1][j - Fields[i]] + Fields[i]);
      }
    }
  }
  for(int i = 1; i <= nStrips; ++i) {
    for(int j = 1; j <= Q; ++j) {
      if (j < Strips[i])
        dp_2[i][j] = dp_2[i - 1][j];
      else {
        dp_2[i][j] = max(dp_2[i - 1][j], 
                         dp_2[i - 1][j - Strips[i]] + Strips[i] - 1);
      }
    }
  }

  int ans = 0;
  for(int i = 0; i <= Q; ++i)
    ans = max(ans, dp_1[nFields][i] + dp_2[nStrips][Q - i]);
  cout << ans;
}