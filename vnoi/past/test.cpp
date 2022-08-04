#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int INF = (int) 1e9 + 7;

int summ(int n){
	int res = 0;
	for(int i=1;i<=n;++i)
	  res += i;
	return res;
}

void solve(){
	int n; cin >> n;
	cout << summ(n);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
