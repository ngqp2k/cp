#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, m, a, b; cin >> h >> m >> a >> b;
  int hGMT = h - a;
  if (hGMT >= 24)
    hGMT -= 24;
  if (hGMT < 0) {
    hGMT = 24 + hGMT;
  }
  // cout << hGMT << "\n";
  int hRes = hGMT + b;
  if (hRes >= 24)
    hRes -= 24;
  if (hRes < 0) {
    hRes = 24 + hRes;
  }
  cout << hRes << " " << m;
}