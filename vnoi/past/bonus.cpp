#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 1e3;

int n, k;
int a[mxN + 1][mxN + 1];
long long t[mxN + 1][mxN + 1];
long long f[mxN + 1][mxN + 1];

long long sum(int u, int v){
	long long res = 0;
	for(int i=u;i<=(k+u-1);++i)
		for(int j=v;j<=(k+v-1);++j)
			res += a[i][j];
	return res;
}

void print(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			cout << f[i][j] << " ";
		cout << "\n";
	}
}

void solve(){
	cin >> n >> k;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin >> a[i][j];

	memset(f, 0, sizeof(f));
	for(int i=1;i<=n;++i){
		long long sum = 0;
		for(int j=1;j<=n;++j){
			sum += a[i][j];
			f[i][j] = f[i - 1][j] + sum;
		}
	}
	
	long long res = 0;
  for(int i = n; i >= k; --i){
		;
		for(int j = n; j >= k; --j){
			res = max(res, f[i][j] - f[i - k][j] - f[i][j - k] + f[i - k][j - k]);
		}
	}
	cout << res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
