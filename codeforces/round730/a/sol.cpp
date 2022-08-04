#include <bits/stdc++.h>
using namespace std;

/*
*/
long long mod(long long a, long long b) {
  long long c = a % b;
  return (c < 0) ? c + b : c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;

  while (tt--) {
    long long a, b; cin >> a >> b;
    if (a - b == 0) {
      cout << "0 0\n";
    }
    else {
      if (a < b) swap(a, b);
      long long ans = a - b;
      cout << ans << " " << min(mod(b, ans), mod(ans - b, ans)) << "\n";
    }
  }
}