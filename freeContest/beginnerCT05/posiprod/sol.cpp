#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int cntPos = 0, cntNeg = 0;
	for(int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x == 0) {
			cout << -1;
			return 0;
		}
		if (x > 0) cntPos++;
		else cntNeg++;
	}
	cout << min(cntPos, cntNeg);
	return 0;
}

