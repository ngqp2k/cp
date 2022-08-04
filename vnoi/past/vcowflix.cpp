#include<bits/stdc++.h>
using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 16;
const int mxM = 5000;

int n, C;
long long res = 0, sum = 0;
int w[mxN + 1];

void Try(int i){
	if (w[i] > C)
		return;
	sum += w[i]; // chon con bo` thu i
	if (sum <= C){
		res = max(res, sum);
		for(int j=i+1;j<=n;++j)
			Try(j);
	}
	sum -= w[i]; // bo chon con bo thu i
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> C >> n;
	for(int i=1;i<=n;++i)
		cin >> w[i];
	w[0] = 0;
	Try(0);
	cout << res;
	return 0;
}

