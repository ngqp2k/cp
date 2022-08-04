#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define MOD 1000000007
#define INF 1000000007
#define int long long
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef map<int, int> mi;

int f(int n) {
  int cnt = 0, ans = 0;
  for (int numEven = 2; numEven <= 8; numEven += 2) {
    // 1, 10, 100, ...
    int d = 1;
    for (int i = 1; i <= 111; ++i) {
      int t = numEven * d;
      if (t > n) break;
      ans += min(d, n - t + 1);
      d *= 10;
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    int l, r; cin >> l >> r;
    cout << f(r) - f(l - 1) << "\n";
  }
}