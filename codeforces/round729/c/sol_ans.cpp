#include<bits/stdc++.h>
using namespace std;
#define int long long

int func(int n) {
  if (n == 1)
    return 2;
  if (n == 2)
    return 3;
  for (int i = 2; i <= (n); ++i)
    if (n % i != 0)
      return i;
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; ++i)
      res += func(i);
    cout << res << "\n";
  }
}