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

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vi f(16);
  f[0] = 0, f[1] = 3;
  for (int i = 2; i <= 15; ++i)
    f[i] = f[i - 1] * 2 - 1;
  int n; cin >> n;
  cout << f[n] * f[n];
}