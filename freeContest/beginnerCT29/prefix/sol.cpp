#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1e5 + 10;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	// FO(1);
	string a, b;
	cin >> a >> b;
	if (a.length() > b.length()){
		cout << "No\n";
	}
	else{
		for(int i=0;i<a.length();++i)
			if (a[i] != b[i]){
				cout << "No\n";
				return 0;
			}
		cout << "Yes\n";
	}
	return 0;
}
