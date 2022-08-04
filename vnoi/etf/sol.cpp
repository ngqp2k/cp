#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 1e6 + 10; 

int n;

bool b[N];
vector<int> Prime;

void solve() {
	cin >> n;
	if (!b[n]) {
		cout << n - 1 << "\n";
		return;
	}

	int M = n;
	set<int> ss;
	int i = 2;
	while(M > 1) {
		if (M % i == 0){
			M /= i;
			ss.insert(i);
		}
		else{
			i++;
			if (!b[M]) {
				ss.insert(M);
				break;
			}
		}
	}
	for(auto it = ss.begin(); it != ss.end(); ++it)
		n = n - n / *it;
	cout << n << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	memset(b, false,sizeof b);
	b[1] = true;
	for(int i = 2; i * i <= 1000000; ++i)
		if (!b[i])
			for(int j = i + i; j <= 1000000;j += i)
				b[j] = true;
	int T; cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}

