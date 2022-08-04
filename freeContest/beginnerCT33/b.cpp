#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const double PI = 3.14159265359;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    double l, d, x, alpha; cin >> l >> d >> x >> alpha;
    if (alpha == 90) {
      cout << 0 << "\n";
      continue;
    }
    if (alpha == 0 || alpha == 180) {
      cout << 1 << "\n";
      continue;
    }
    if (alpha > 90) {
      x = d - x;
      alpha = (180 - alpha);
    }
    alpha = 90 - alpha;
    double bc = d / (tan(alpha * PI / 180));
    double ac = x / (tan(alpha * PI / 180));
    if (l < ac) {
      cout << 0 << "\n";
      continue;
    }
    l -= ac;
    int res = l / bc; 
    cout << res + 1 << "\n";
  }
}