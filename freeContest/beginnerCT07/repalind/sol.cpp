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

bool check(string s) {
  string ss = s;
  reverse(all(ss));
  return (ss == s);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    string s; cin >> s;
    int k; cin >> k;
    if (check(s)) {
      cout << "YES\n";
    }
    else
      cout << "NO\n";
  }
}