#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<int> d(n);
  for (int &i: d) cin >> i;
  sort(d.begin(), d.end());
  int ans = 1e9 + 7;
  for (int i = 1; i < n; ++i)
    ans = min(ans, abs(d[i] - d[i - 1]));
  cout << ans;
}