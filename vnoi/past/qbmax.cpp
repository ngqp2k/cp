#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int INF = (int) 1e9 + 7;

int n, m;
int a[102][102], f[102][102];

int ffunc(int i, int j){
	if (1 <= i && i <= m && 1 <= j && j <= n)
		return f[i][j];
	return -INF;
}

void solve(){
	cin >> m >> n;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			cin >> a[i][j];
	for(int i=1;i<=m;++i)
		f[i][1] = a[i][1];

	for(int i=2;i<=n;++i)
		for(int j=1;j<=m;++j)
			f[j][i] = max(ffunc(j - 1, i - 1), max(ffunc(j, i - 1), ffunc(j + 1, i - 1))) + a[j][i];
	int res = -INF;
	for(int i=1;i<=m;++i)
		res = max(res, f[i][n]);
	cout << res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
