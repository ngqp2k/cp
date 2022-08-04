#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    pair<int, int> a, b, f;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> f.first >> f.second;
    int ans;
    if (a.first == b.first) {
      if (f.first == a.first && ((a.second < f.second && f.second < b.second) 
                              || (b.second < f.second && f.second < a.second)))
        ans = abs(a.second - b.second) + 2;
      else
        ans = abs(a.second - b.second);
      cout << ans << "\n";
      continue;
    }
    if (a.second == b.second) {
      if (f.second == a.second && ((a.first< f.first && f.first < b.first) 
                                || (b.first < f.first && f.first < a.first)))
        ans = abs(a.first - b.first) + 2;
      else
        ans = abs(a.first - b.first);
      cout << ans << "\n";
      continue;
    }
    int x = abs(a.first - b.first) + 1;
    int y = abs(a.second - b.second) + 1;
    ans = x + y - 2;
    cout << ans << "\n";
  }
}
