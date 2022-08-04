#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

int Z, O, K;
int dp[51][51][111];

void solve(int z, int o, int cnt) {
  /*
    z, o <= 50
    k <= 100
    - dp[z][o][k]: so day dung z so 0, o so 1, do dai khong giam dai nhat k
    - dp[z][o][k] = dp[z][o - 1][k + 1], neu them so 1 vao cuoi day
    - dp[z][o][k] += dp[z - 1][o][max(k, Z - z + 1)], neu them so 0 vao cuoi day
  */

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    int z, o, k; cin >> z >> o >> k;
    Z = z, O = o, K = k;
  }
}