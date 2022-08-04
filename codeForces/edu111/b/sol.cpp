#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 1e5 + 10; 

int n, a, b;
string s;
int cnt[2];

void solve(){
	cin >> n >> a >> b;
	cin >> s;
	cnt[0] = cnt[1] = 0;

	int k = 0;
	s += '#';
	while(s[0] != '#'){
		if (s[0] != s[1]) {
			cnt[s[0] - '0']++;
		}
		s.erase(0, 1);
	}

	// cout << cnt[0] << " " << cnt[1] << "\n";
	// return;

	if (b >= 0) {
		cout << n * (a + b);
	}
	else {
		int amz = (cnt[0] < cnt[1] ? cnt[0] : cnt[1]) + 1;
		cout << n * a + b * amz;
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while(T--){
		solve();
		cout << "\n";
	}
	return 0;
}

