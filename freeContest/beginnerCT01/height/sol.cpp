#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 1e5 + 10; 
typedef pair<int, int> II;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<II> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a.begin(), a.end());
	vector<int> ans(n), f(n);
	f[0] = 0;
	ans[a[0].se] = 0;
	for(int i = 1; i < n; ++i) {
		if (a[i].fi == a[i - 1].fi)
			f[i] = f[i - 1];
		else
			f[i] = i;
		ans[a[i].se] = f[i];
	}

	for(int i: ans) cout << i << " ";
}
