#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1e5 + 1;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int n, S;
int V[N], W[N];


void solve(){
	cin >> n >> S;
	for(int i=1;i<=n;++i){
		cin >> W[i];
	}
	ull sumV = 0;
	for(int i=1;i<=n;++i){
		cin >> V[i];
		if (W[i] <= S)
			sumV += V[i];
	}
	cout << sumV << "\n";

}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	// FO(1);
	int q; cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
