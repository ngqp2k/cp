#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 1e5 + 10; 

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	vector<int> f(5000 + 1, 0);
	f[1] = 1;

	int t = 3;
	int tt = t;
	int part = 2;

	for(int i = 2; i <= 5000; ++i)
	{
		tt--;
		f[i] = part;
		if (tt == 0){
			t += 2;
			tt = t;
			part++;
		}

	}


	int T; cin >> T;
	while(T--) {
		int s; cin >> s;
		cout << f[s] << "\n";
	}
	return 0;
}

