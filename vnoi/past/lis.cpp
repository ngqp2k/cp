#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int INF = (int) 1e9 + 7;

void solve();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

void solve(){
	int n, x; cin >> n;
	vector<long long> f;
	while(n--){
		cin >> x;
		vector<long long> :: iterator it = lower_bound(f.begin(), f.end(), x);
		if (it == f.end())
			f.push_back(x);
		else
			*it = x;
	}
	cout << f.size();
}
