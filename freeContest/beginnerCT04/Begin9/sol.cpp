#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int modBigNum(string s, int mod) {
  int res = 0;
  for(int i = 0; i < s.length(); ++i)
    res = (res * 10 + (s[i] - '0')) % mod;
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string a, b; cin >> a >> b;
  int lastDigit = a[a.size() - 1] - '0';
  int n = modBigNum(b, 4);
  if (n == 0) n = 4;
  int res = lastDigit;
  for(int i = 1; i < n; ++i) res *= lastDigit;
  cout << res % 10;
}