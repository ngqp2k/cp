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
  string s; cin >> s;
  int x; cin >> x;
  vi f(30);
  f[0] = x;
  for (int i = 1; i <= 25; ++i) {
    x++;
    if (x == 26)
      x = 0;
    f[i] = x;
  }
  int ans = 0;
  for (int i = 0; i < s.length(); ++i)
    ans += f[s[i] - 'a'];
  cout << ans;
}