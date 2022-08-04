#include <iostream>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s; cin >> s;
  int n = s.size();
  string cur = "";
  for (int i = 0; i < n; ++i) {
    cur += s[i];
    if (n % cur.size() != 0) continue;
    string compare = cur;
    for (int j = 1; j < (int)(n / cur.size()); ++j) compare += cur;
    if (compare == s) {
      cout << (n / cur.size()) << cur;
      return 0;
    }
  }
}