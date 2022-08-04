#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define MOD 1000000007
#define INF 1000000007
#define int long long

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef map<int, int> mi;

int binaryCalc(vi a, int t) {
  int ans = 0, n = a.size();
  rep(i, n)
  ans += t / a[i];
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T, n, m;
  cin >> T;
  cin >> n; vi a(n);
  rep(i, n) cin >> a[i];
  cin >> m; vi b(m);
  rep(i, m) cin >> b[i];

  int left = 0, right = T;
  int cnt_a, cnt_b, mid;
  int tMax = 0;
  while (left <= right) {
    mid = (left + right) / 2;
    cnt_a = binaryCalc(a, mid);
    cnt_b = binaryCalc(b, T - mid);
    if (cnt_a >= cnt_b) {
      right = mid - 1;
    }
    else {
      left = mid + 1;
      tMax = mid;
    }
  }
  cout << max(min(binaryCalc(a, tMax), binaryCalc(b, T - tMax)),
              min(binaryCalc(a, tMax + 1), binaryCalc(b, T - tMax - 1)));
}
