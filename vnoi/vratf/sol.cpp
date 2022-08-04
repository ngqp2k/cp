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
// #define int long long

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef map<int, int> mi;

const int mxN = 1e9 + 11;

int f(int n, int k) {
  if (n <= k + 1)
    return 1;
  else {
    if ((n + k) % 2 != 0)
      return 1;
    else
      return f((n + k) / 2, k) + f(n - (n + k) / 2, k);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k; cin >> n >> k;
  cout << f(n, k);
  return 0;
}
