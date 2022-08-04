#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 1e3 + 10; 

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	vector<int> f(N + 1);
	f[0] = 0;
	int res = 0;
	for(int i = 1; i <= N; ++i) {
		int x; cin >> x;
		f[i] = f[i - 1] + x;
		for(int j = 0; j < i; ++j)
			res = max(res, f[i] - f[j]);
	}
	cout << res;
	return 0;
}

