#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

vector<int> convertBIT(int n) {
  vector<int> ans;
  while (n > 0) {
    ans.pb(n % 2); n /= 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int convertDEC(vector<int> bit) {
  int res = 0, n = bit.size();
  for (int i = 0; i < n; ++i) {
    if (bit[i] == 1) {
      res += (1 << (n - i - 1));
    }
  }
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int n, m; cin >> n >> m;
    if (n > m) {
      cout << 0 << "\n";
      continue;
    }
    vector<int> bitN = convertBIT(n);
    vector<int> bitP = convertBIT(m + 1);
    vector<int> k;
    for (int i = 0; i < bitP.size() - bitN.size(); ++i)
      k.pb(bitP[i]);
    int indexN = 0, indexP = bitP.size() - bitN.size();
    while (indexN < bitN.size()) {
      if (bitN[indexN] == 1) {
        if (bitP[indexP] == 1)
          k.pb(0);
        else {
          for (int j = indexP; j < bitP.size(); ++j)
            k.pb(0);
          break;
        }
      }
      else {
        if (bitP[indexP] == 1)
          k.pb(1);
        else {
          k.pb(0);
        }
      }
      indexN++, indexP++;
    }
    cout << convertDEC(k) << "\n";
  }
}
