#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 1e5 + 10; 

int n;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			int x; cin >> x;
			if (i == j) cout << sqrt(x) << " ";
		}

	return 0;
}

