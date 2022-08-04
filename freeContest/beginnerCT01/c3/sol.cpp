#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 1e5 + 10; 

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, x; cin >> n >> x;
	// a[i] + a[j] * a[j] = x
	vector<int> a(n + 1), cnt(250000, 0);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	
	int res = 0;
	for(int i = 1; i <= n; ++i) {
		cnt[a[i]]++;
		if (x - a[i] * a[i] < 0) continue;
		res += cnt[x - a[i] * a[i]];
	}

	cout << res;
	return 0;
}

