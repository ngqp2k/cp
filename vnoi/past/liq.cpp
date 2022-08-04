#include<bits/stdc++.h>
using namespace std;

void solve();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

void solve(){
	int n; cin >> n;
	vector<int> a(n + 1);
	vector<int> f(n + 1, 0);
	for(int i=1;i<=n;++i)
		cin >> a[i];
	int res = -1;
	for(int i=1;i<=n;++i){
		f[i] = 1;
		for(int j=1;j<i;++j)
			if (a[i] > a[j] && f[j] + 1 > f[i])
				f[i] = f[j] + 1;
		res = max(res, f[i]);
	}
	cout << res;
}
