#include<bits/stdc++.h>
#define int long long
using namespace std;

int f(int n) {
	if (n < 0) return 0;
	int ans = (n / 4 + n / 7 + n / 11 - (n / 28) - (n / 44) - (n / 77) + (n / 308)) + 1;
	return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
		int l, r; cin >> l >> r;
		cout << f(r) - f(l - 1) << "\n";
	}
}
