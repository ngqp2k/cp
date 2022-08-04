#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define TASK ""
 
using namespace std;
const int N = 1100;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;
 
typedef long long ll;
typedef unsigned long long ull;
 
void File()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(TASK".INP", "r",stdin);
    // freopen(TASK".OUT", "w",stdout);
}
 
int n;
vector<int> g[N];
int depth[N], p[N][LOG + 1];
void solve(void) {
	cin >> n;
  for(int i=0;i<n;++i){
    int m; cin >> m;
    for(int j=0;j<m;++j){
      int x; cin >> x;
      g[i].pb(x);
    }
  }
}
int main()
{
  File();
  int T = 1;
  cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}