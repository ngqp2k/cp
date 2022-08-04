#include<bits/stdc++.h>
using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 10000000;

vector<bool> f(mxN + 1, true);
vector<int> d(1, -1);

void sangNT(){
	f[1] = false;
	for(int i=2;i * i <= mxN; ++i)
		if (f[i])
			for(int j = i + i; j <= mxN; j += i)
				f[j] = false;
	;
	for(int i=1;i<=mxN;++i)
		if (f[i])
			d.push_back(i);
}

bool checkPrime(int x){
	if (f[x])
		return true;
	return false;
}

void solve(){
	int k; cin >> k;

	int i = 0;
	int n = 1;
	while(1){
		if (checkPrime(d[n] * 2 - 1))
			i++;
		if (i == k){
			cout << d[n] << " " << d[n] << " " << d[n] * 2 - 1;
			break;
		}
		if (checkPrime(d[n] * 2 + 1))
			i++;
		if (i == k){
			cout << d[n] << " " << d[n] << " " << d[n] * 2 + 1;
			break;
		}
		n++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	sangNT();
  solve();
	return 0;
}
