#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 8e5;

int n;
int c[mxN + 1];

void solve(){
  int res = 0;
	cin >> n;
	for(int i=1;i<=2*n;++i){
		int u, v; cin >> u >> v;
		res += u;
		c[i] = v - u;
	}
  sort(c + 1, c + 2*n + 1);
	for(int i=1;i<=n;++i)
	  res += c[i];
	cout << res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
